#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    clientFtp.setupServer("192.168.1.34", "daemon", "xampp");
    clientFtp.startThread();
}       

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofDrawBitmapStringHighlight("UPLOADED FILES " + ofToString(clientFtp.getUploadCount()), ofPoint(50,50));
}

//--------------------------------------------------------------
void testApp::exit(){
    clientFtp.waitForThread();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    for(int i = 0 ; i < dragInfo.files.size() ; i++)
    {
        ofFile file(dragInfo.files[i]);
        string path = file.path().substr(0,file.path().length()-file.getFileName().length());
        clientFtp.addFileToUpload(file.getFileName(), "/", path);
       
    }
}