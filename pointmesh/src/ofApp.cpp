#include "ofApp.h"

//--------------------------------------------------------------
//void ofApp::setup(){
//    ofEnableSmoothing();
//    ofBackground(90);
//    frequency=1.0f;
//    timeFrequency=1.0f;
//    magnitude=20.0f;
//    gridResolution=20;
//
//}
//
////--------------------------------------------------------------
//void ofApp::update(){
//    
//    float time = ofGetElapsedTimef();
//    float noiseTime = time * timeFrequency;
//    ofVec2f extentMin( 0, 0);
//    ofVec2f extentMax( ofGetWidth(), ofGetHeight());
//    mesh.clear();
//    mesh.setMode( OF_PRIMITIVE_POINTS );
//    for( int y = 0; y < gridResolution; y++ )
//    {
//        for( int x = 0; x < gridResolution; x++ )
//        {
//            
//            ofVec2f pos;
//            pos.x = ofMap( x,  0, gridResolution-1, extentMin.x, extentMax.x );
//            pos.y = ofMap( y,  0, gridResolution-1, extentMin.y, extentMax.y );
//
//            ofVec2f noisePos = pos * frequency;
//            ofVec2f vel;
//            
//            vel.x = ofSignedNoise( noisePos.x, noisePos.y, noiseTime );
//            vel.y = ofSignedNoise( noisePos.y, noisePos.x, noiseTime);
//
//            
//            mesh.addVertex( pos + (vel * magnitude));
//            mesh.addColor(ofFloatColor(255,100));
//        }
//    }
//
//
//
//}
//
////--------------------------------------------------------------
//void ofApp::draw(){
//    
//
//mesh.draw();
//
//}

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(58,119,34);
    titleCount=400;
    zScale=30;
    noiseXRange=6;
    noiseYRange=6;
    noiseOffset=1;
    
    
    cam.setPosition(ofPoint(ofGetWidth(), ofGetHeight(), 700));
//    cam.lookAt(ofPoint(1,1,0));`
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    mesh.setMode( OF_PRIMITIVE_LINES );
    mesh2.clear();
    mesh2.setMode( OF_PRIMITIVE_LINES );
    
    float tileSizeY = (float)ofGetHeight()/titleCount;
    float noiseStepY = (float)noiseYRange/titleCount;
    float time=ofGetElapsedTimef();
    
    for (int meshy=0;  meshy<= titleCount; meshy++) {

        for (int meshx=0; meshx<=titleCount; meshx++) {
            float x=ofMap(meshx, 0, titleCount,-ofGetWidth()/2, ofGetWidth()/2);
            float y=ofMap(meshy, 0, titleCount,-ofGetHeight()/2, ofGetHeight()/2);
            
            float noiseX=ofMap(meshx, 0, titleCount, 0, noiseXRange);
            float noiseY=ofMap(meshy, 0, titleCount, 0, noiseYRange);
            
            float x1 = 2*ofNoise(noiseX+noiseOffset, noiseY,time);
            float y1 = 2*ofNoise(noiseX+noiseOffset,noiseY+noiseStepY,time);
            
            ofFill();
            ofSetColor(255,20);
            mesh.addVertex(ofPoint(x+x1*zScale, y+x1*zScale,0));
            mesh.addVertex(ofPoint(x+y1*zScale, y+tileSizeY+y1*zScale,0));
            
        }

    }
    
    
    for (int meshy=0;  meshy<= titleCount; meshy++) {
        
        for (int meshx=0; meshx<=titleCount; meshx++) {
            float x=ofMap(meshx, 0, titleCount,-ofGetWidth()/2, ofGetWidth()/2);
            float y=ofMap(meshy, 0, titleCount,-ofGetHeight()/2, ofGetHeight()/2);
            
            float noiseX=ofMap(meshx, 0, titleCount, 0, noiseXRange);
            float noiseY=ofMap(meshy, 0, titleCount, 0, noiseYRange);
            
            float x1 = 1.5*ofNoise(noiseX+noiseOffset, noiseY,time+0.0001);
            float y1 = 1.5*ofNoise(noiseX+noiseOffset,noiseY+noiseStepY,time+0.0001);
            
            ofFill();
            ofSetColor(255,253,230,15);
            mesh2.addVertex(ofPoint(x+x1*zScale, y+x1*zScale,-20));
            mesh2.addVertex(ofPoint(x+y1*zScale, y+tileSizeY+y1*zScale,-20));
            
        }
        
    }

    noiseOffset+=0.005;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    mesh.draw();
    ofPushMatrix();
    ofRotateZ(90);
//    ofRotate(PI/3);
    mesh2.draw();
    ofPopMatrix();
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
