from http.server import BaseHTTPRequestHandler, HTTPServer
from firebase_admin import credentials
from firebase_admin import firestore
from datetime import datetime
from time import *

cred = credentials.Certificate('credetials.json')
app = firebase_admin.initialize_app(cred)
db = firestore.client()

class MyServer(BaseHTTPRequestHandler):
    def _set_response(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        print('Hello from get')

        if '/sensor1_temp' in self.path:
            current_date = datetime.now()
            date = current_date.strftime('%Y-%m-%d')
            hour = current_date.strftime('%H')
            minute = current_date.strftime('%M')
            collection_name = f'temperatura_{date}'

            sensor1_temp = self.path.split('=')[1]
            print('The temperature is {}'.format(sensor1_temp))
            temperature = db.collections(collection_name).document(f'temp{hour}')
            temp_doc = temperature.get()
            temp_data = temp_doc.to_dict()

            if temp_data == None:
                temperature.set({u'temperature_{}'.format(minute): sensor1_temp})

        self._set_response()
        self.wfile.write('GET request for {}'.format(self.path).encode('utf-8'))

port = 8080
server_address = ('', port)
httpd = HTTPServer(server_address, MyServer)
httpd.serve_forever()
