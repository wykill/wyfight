#ifndef _SPEECHMGR_HPP_
#define _SPEECHMGR_HPP_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "Speaker.hpp"
using namespace std;

class SpeechMgr {
public:
    SpeechMgr();
    ~SpeechMgr();
    void printInfo();
    void quitSystem();
    void startContest();
    void showSpeakers();
    void showHistory();
    void clearRecord();

private:
    void init();
    void initSpeech();
    void initSpeakers();
    void loadHistory();
    void startDraw();
    void speachContest();
    void showFinalWinner();
    void writeFinalWinner();
private: 
    vector<int> m_round1;    // 第一轮比赛的编号
    vector<int> m_round2;    // 第二轮比赛的编号
    vector<int> m_final;     // 决赛的编号
    map<int, Speaker> m_speakers;  //编号，选手信息
    vector<vector<string> > m_hisVec;  // 历史记录
    int m_index;                //轮数
    bool m_fileFlag;            //  文件是否存在
};

#endif
