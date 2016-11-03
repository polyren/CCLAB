// Made By Wenzy In 2016

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    int bufferSize = 256;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    
    
    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA);
    fbo.begin();
    ofClear(0,50);
    fbo.end();
    feedback.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA);
    feedback.begin();
    ofClear(0,50);
    feedback.end();
    radius=150;
    angle1=0;
    angle2=4*PI/3;
    angle3=2*PI/3;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255,255,245);
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }

    
    pos1x=ofGetWidth()/2+cos(angle1)*radius;
    pos1y=ofGetHeight()/2+sin(angle1)*radius;
    pos2x=ofGetWidth()/2+cos(angle2)*radius;
    pos2y=ofGetHeight()/2+sin(angle2)*radius;
    pos3x=ofGetWidth()/2+cos(angle3)*radius;
    pos3y=ofGetHeight()/2+sin(angle3)*radius;
    
    fbo.begin();
    
    float a= ofMap(scaledVol, 0, 0.1, 234,255,true);
    ofSetColor(0,a);
    
    // 控制拉伸
    feedback.draw(-4,-4,ofGetWidth() + 8,ofGetHeight() + 8);
    //  glBlendFuncSeparate (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    
    // 绘图部分
    ofSetColor(0);
    ofDrawCircle(pos1x,pos1y,6+scaledVol * 190.0f);
    ofDrawCircle(pos2x,pos2y,6+scaledVol * 190.0f);
    ofDrawCircle(pos3x,pos3y,6+scaledVol * 190.0f);
    fbo.end();
    
    feedback.begin();
    ofSetColor(255);
    fbo.draw(0,0);
    feedback.end();
    
    angle1+=0.04;
    angle2+=0.04;
    angle3+=0.04;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.draw(0,0);
    
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
