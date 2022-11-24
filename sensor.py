from firebase_admin import firestore
from firebase_admin import credentials
from datetime import datetime
from random import *
from time import *

cred = credentials.Certificate('credentials.json')
app = firebase_admin.initialize_app(cred)
db = firestore.client()

while True:
    print('sending data')

    current_date = datetime.now()
    date = current_date.strftime('%Y-%m-%d')
    hour = current_date.strftime('%H')
    collection_name = u'sensor_1_{0}'.format(date)
    on = bool(random.getrandbits(1))

    totals_ref = db.collection(collection_name).document('totals')
    totals_doc = totals_ref.get()
    totals_data = totals_doc.to_dict()

    if totals_data == None:
        totals_ref.set({u'total_minutes_on': 1 if on else 0})
    else:
        if on:
            totals_ref.update({u'total_minutes_on': totals_data[u'total_on_minutes'] + 1})

    hour_ref = db.collection(collection_name).document(hour)
    hour_doc = hour_ref.get()
    hour_data = hour_doc.to_dict()

    if hour_data == None:
        hour_ref.set({
            u'minutes_on': 1 if on else 0,
            u'minutes_off': 1 if not on else 0
        })
    else:
        if on:
            hour_ref.update({u'minutes_on': hour_data[u'minutes_on'] + 1})
        else:
            hour_ref.update({u'minutes_off': hour_data[u'minutes_off'] + 1})
    
    time.sleep(10)
