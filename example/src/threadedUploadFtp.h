//
//  threadedUploadFtp.h
//  ftpExample
//
//  Created by Natxo Pedreira gonzalez on 27/1/15.
//
//

#ifndef __ftpExample__threadedUploadFtp__
#define __ftpExample__threadedUploadFtp__

#include "ofMain.h"
#include "ofxFTP.h"

typedef struct {
    string fileName;
    string remotePath;
    string localPath;

} QueuedUpload;


class threadedUploadFtp : public ofThread{
    
    
public:
    queue<QueuedUpload> files;
    int counter;
    
    threadedUploadFtp(){
        counter = 0;
    }
    
    //--------------------------------------------------------------
    void setupServer(string _host, string _user, string _pass){
        client.setup(_host, _user, _pass);
    }
    
    //--------------------------------------------------------------
    void addFileToUpload(string _fileName, string _remotePath, string _localPath){
    
        
        QueuedUpload up;
        
        up.fileName = _fileName;
        up.remotePath = _remotePath;
        up.localPath = _localPath;
        
        files.push(up);
    }
    
    //--------------------------------------------------------------
    int getUploadCount(){
        return counter;
    }
    
    
    //--------------------------------------------------------------
    void threadedFunction() {
        while(isThreadRunning()) {
            if(!files.empty()){
                QueuedUpload q = files.front();
                
                if(client.send(q.fileName,q.localPath,q.remotePath) > 0){
                    // upload correcta
                    files.pop();
                    ofLogWarning("THREADED UPLOAD", "upload OK");
                    counter++;
                    
                }else{
                    // upload fail
                    ofLogWarning("THREADED UPLOAD", "upload ERROR");
                }
            }
        }
    }
    
private:
    
    ofxFTPClient client;
    
};

#endif /* defined(__ftpExample__threadedUploadFtp__) */
