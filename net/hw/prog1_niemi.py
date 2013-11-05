# Rebar Niemi
# SOS 2013
# Networking Program 1: Web server
# 
# Note: I worked with Josh and utilized a design for this server
# that we collaborated on


# We put everything inside a try just to be safe, so that we could catch
# connection exceptions
try:
  from socket import * #import the entirety of the socket package
  serversocket = socket(AF_INET, SOCK_STREAM) #instantiate a TCP socket stream
  serversocket.bind(('', 80)) #all avaliable hostnames, port 80
  serversocket.listen(5) #queue up to 5 requests to connect

  while True:
    #Establish the connection
    print('Ready to serve...')
    connectionsocket, addr = serversocket.accept() #returns a tuple
                                                 #client socket + addr
                                #blocks until it receives a connection
    print("TCP connection received from:" +addr[0]+" at port:"+str(addr[1]))
    print()

    try: #reading and fetching file
      message = connectionsocket.recv(1024) #receive data from the socket, max
                                            #size of 1024 bytes in buffer

# Note: the UTF-8 encode and decodes are due to the fact that Python 3 changed the
# way byte encoding/decoding happen, which means we need to decode strings into bytes
# and encode bytes into strings
      filename = message.split()[1].decode('UTF-8').strip('/')
      f = open(filename)
      outputdata = f.read()
      connectionsocket.send("HTTP/1.1 200 OK \n\n".encode('UTF-8'))
      connectionsocket.send(outputdata.encode('UTF-8')) #writes the output
      print("...u got served")
      print()
      connectionsocket.close() #closes the client socket that was created

    except IOError:
      connectionsocket.send("HTTP/1.1 404 Not Found \n\n".encode('UTF-8'))
# if we can't retrieve the output, send a proper HTTP response
      print()
      connectionsocket.close()
  serversocket.close() #close the serversocket

except Exception as err:
    serversocket.close()
    print("Whoa exception, socket closed. Retrying...")
    raise err
