//https://www.oryx-embedded.com/doc/tcp__fsm_8c_source.html

    //Specified port is unreachable?
    if(socket == NULL)
    {
       //An incoming segment not containing a RST causes
       //a reset to be sent in response
       if(!(segment->flags & TCP_FLAG_RST))
          tcpSendResetSegment(interface, pseudoHeader, segment, length);
 
       //Return immediately
       return;
    }
 
    //Check current state
    switch(socket->state)
    {
    //Process CLOSED state
    case TCP_STATE_CLOSED:
       //This is the default state that each connection starts in before
       //the process of establishing it begins
       tcpStateClosed(interface, pseudoHeader, segment, length);
       break;
    //Process LISTEN state
    case TCP_STATE_LISTEN:
       //A device (normally a server) is waiting to receive a synchronize (SYN)
       //message from a client. It has not yet sent its own SYN message
       tcpStateListen(socket, interface, pseudoHeader, segment, length);
       break;
    //Process SYN_SENT state
    case TCP_STATE_SYN_SENT:
       //The device (normally a client) has sent a synchronize (SYN) message and
       //is waiting for a matching SYN from the other device (usually a server)
       tcpStateSynSent(socket, segment, length);
       break;
    //Process SYN_RECEIVED state
    case TCP_STATE_SYN_RECEIVED:
       //The device has both received a SYN from its partner and sent its own SYN.
       //It is now waiting for an ACK to its SYN to finish connection setup
       tcpStateSynReceived(socket, segment, buffer, offset, length);
       break;
    //Process ESTABLISHED state
    case TCP_STATE_ESTABLISHED:
       //Data can be exchanged freely once both devices in the connection enter
       //this state. This will continue until the connection is closed
       tcpStateEstablished(socket, segment, buffer, offset, length);
       break;
    //Process CLOSE_WAIT state
    case TCP_STATE_CLOSE_WAIT:
       //The device has received a close request (FIN) from the other device. It
       //must now wait for the application to acknowledge this request and
       //generate a matching request
       tcpStateCloseWait(socket, segment, length);
       break;
    //Process LAST_ACK state
    case TCP_STATE_LAST_ACK:
       //A device that has already received a close request and acknowledged it,
       //has sent its own FIN and is waiting for an ACK to this request
       tcpStateLastAck(socket, segment, length);
       break;
    //Process FIN_WAIT_1 state
    case TCP_STATE_FIN_WAIT_1:
       //A device in this state is waiting for an ACK for a FIN it has sent, or
       //is waiting for a connection termination request from the other device
       tcpStateFinWait1(socket, segment, buffer, offset, length);
       break;
    //Process FIN_WAIT_2 state
    case TCP_STATE_FIN_WAIT_2:
       //A device in this state has received an ACK for its request to terminate the
       //connection and is now waiting for a matching FIN from the other device
       tcpStateFinWait2(socket, segment, buffer, offset, length);
       break;
    //Process CLOSING state
    case TCP_STATE_CLOSING:
       //The device has received a FIN from the other device and sent an ACK for
       //it, but not yet received an ACK for its own FIN message
       tcpStateClosing(socket, segment, length);
       break;
    //Process TIME_WAIT state
    case TCP_STATE_TIME_WAIT:
       //The device has now received a FIN from the other device and acknowledged
       //it, and sent its own FIN and received an ACK for it. We are done, except
       //for waiting to ensure the ACK is received and prevent potential overlap
       //with new connections
       tcpStateTimeWait(socket, segment, length);
       break;
    //Invalid state...
    default:
       //Back to the CLOSED state
       tcpChangeState(socket, TCP_STATE_CLOSED);
       //Silently discard incoming packet
       break;
    }
 }
 

/************************************************************************************/

int main(){
    Handler socket;
    int state;
    enum TcpState{
        TCP_STATE_CLOSED       = 0,
        TCP_STATE_LISTEN       = 1,
        TCP_STATE_SYN_SENT     = 2,
        TCP_STATE_SYN_RECEIVED = 3,
        TCP_STATE_ESTABLISHED  = 4,
        TCP_STATE_CLOSE_WAIT   = 5,
        TCP_STATE_LAST_ACK     = 6,
        TCP_STATE_FIN_WAIT_1   = 7,
        TCP_STATE_FIN_WAIT_2   = 8,
        TCP_STATE_CLOSING      = 9,
        TCP_STATE_TIME_WAIT    = 10,
    };
    add(socket, tcpStateClosed(interface, pseudoHeader, segment, length),                           state == TCP_STATE_CLOSED);
    add(socket, tcpStateClosed(tcpStateListen(socket, interface, pseudoHeader, segment, length),    state == TCP_STATE_LISTEN);
    add(socket, tcpStateSynSent(socket, segment, length),                                           state == TCP_STATE_SYN_SENT);
    add(socket, tcpStateSynReceived(socket, segment, buffer, offset, length),                       state == TCP_STATE_SYN_RECEIVED);
    add(socket, tcpStateEstablished(socket, segment, buffer, offset, length),                       state == TCP_STATE_ESTABLISHED);
    add(socket, tcpStateCloseWait(socket, segment, length),                                         state == TCP_STATE_CLOSE_WAIT);
    add(socket, tcpStateLastAck(socket, segment, length),                                           state == TCP_STATE_LAST_ACK);
    add(socket, tcpStateFinWait1(socket, segment, buffer, offset, length),                          state == TCP_STATE_FIN_WAIT_1);
    add(socket, tcpStateFinWait2(socket, segment, buffer, offset, length),                          state == TCP_STATE_FIN_WAIT_2);
    add(socket, tcpStateClosing(socket, segment, length),                                           state == TCP_STATE_CLOSING);
    add(socket, tcpStateTimeWait(socket, segment, length),                                          state == TCP_STATE_TIME_WAIT);
    add(socket, tcpChangeState(socket, TCP_STATE_CLOSED),                                           state == other);
    run(socket, state);
    
} 