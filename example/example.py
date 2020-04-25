import svar
import time

m = svar.load('svar_messenger')

def say(msg):
  print("received:",msg)

sub_no_thread = m.messenger.subscribe('example',0,say)
sub_new_thread = m.messenger.subscribe('example',1,say)

m.messenger.publish('example','hello world')

pub = m.messenger.advertise('example',1)

pub.publish('hello publisher')

time.sleep(10)
