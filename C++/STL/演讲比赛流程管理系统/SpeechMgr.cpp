#include "SpeechMgr.hpp"
#include <deque>
#include <algorithm>
#include <numeric>
#include <fstream>
using namespace std;

SpeechMgr::SpeechMgr() {
    //TODO init m_speakers
    initSpeech();

    initSpeakers();

    loadHistory();
}

SpeechMgr::~SpeechMgr() {
}

void SpeechMgr::printInfo() {
    cout << "**********************" << endl;
    cout << "*** 1.开始演讲比赛 ***" << endl;
    cout << "*** 2.查看往届记录 ***" << endl;
    cout << "*** 3.清空比赛记录 ***" << endl;
    cout << "*** 0.退出比赛程序 ***" << endl;
    cout << "**********************" << endl;
}

void SpeechMgr::quitSystem() {
    cout << "欢迎下次使用！" << endl;
    system("read -rsp 'Please Enter to Exit...'");
    exit(0);
}

void SpeechMgr::startContest()
{
    // startGame
    // first round to draw
    for (; m_index < 2; m_index++) {
        // round to draw
        startDraw();
        // round to contest
        speachContest();
    }
    showFinalWinner();
    writeFinalWinner();
    init();
    cout << "本届比赛结束！" << endl;
    system("read -rsp 'Please Enter to Continue...'");
    cout << endl;
}

void SpeechMgr::showSpeakers() 
{
    for (map<int, Speaker>::iterator iter = m_speakers.begin(); iter != m_speakers.end(); iter++) {
        cout << "选手id: " << iter->first << ", 选手姓名：" << iter->second.m_name 
            << "，选手分数：" << iter->second.m_scores[0] << " " << iter->second.m_scores[1] << endl;
    }
}

void SpeechMgr::init()
{
    initSpeech();
    initSpeakers();
    loadHistory();
}

void SpeechMgr::initSpeech() {
    m_index = 0;
    m_round1.clear();
    m_round2.clear();
    m_final.clear();
    m_speakers.clear();
    m_hisVec.clear();
}

// 初始化所有信息
void SpeechMgr::initSpeakers()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++) {
        string speakerName = "speaker";
        speakerName += nameSeed[i];
        Speaker speaker;
        speaker.m_name = speakerName;
        speaker.m_scores[0] = 0;
        speaker.m_scores[1] = 0;

        int id = i + 1001;

        m_round1.push_back(id);

        m_speakers.insert(make_pair(id, speaker));
    }
}

void SpeechMgr::loadHistory()
{
    ifstream ifs;
    ifs.open("SpeechSystem.csv", ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在！" << endl;
        m_fileFlag = false;
    }
    
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        // cout << "文件为空！" << endl;
        m_fileFlag = false;
    }
    ifs.putback(ch);
    string recordStr;
    while (ifs >> recordStr) {
        // cout << recordStr;
        vector<string> recordVec;
        int start = 0;
        int pos = -1;
        while (true) {
            pos = recordStr.find(",", start);
            if (pos == -1) {
                break;
            }
            string subRecordStr = recordStr.substr(start, pos - start);
            // cout << subRecordStr << endl;
            recordVec.push_back(subRecordStr);
            start = pos + 1;
        }
        recordVec.push_back(recordStr.substr(start));
        m_hisVec.push_back(recordVec);
        m_fileFlag = true;
    }
    ifs.close();
}

void SpeechMgr::startDraw()
{
    cout << "第" << m_index + 1 << "轮比赛选手正在抽签。。。" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "第" << m_index + 1 << "轮比赛选手抽签结果为：" << endl;
    if (m_index == 0) {
        random_shuffle(m_round1.begin(), m_round1.end());
        for (vector<int>::iterator iter = m_round1.begin(); iter != m_round1.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
    }
    else if (m_index == 1) {
        random_shuffle(m_round2.begin(), m_round2.end());
        for (vector<int>::iterator iter = m_round2.begin(); iter != m_round2.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
    }
    system("read -rsp 'Please Enter to Continue...'");
    cout << endl;
}

void SpeechMgr::speachContest ()
{
    cout << "第" << m_index + 1 << "轮比赛选手正在比赛。。。" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "第" << m_index + 1 << "轮比赛选手获得比分如下。。。" << endl;
    multimap<double, int, greater<double> > groupScoreMap;

    vector<int> v_Src;
    if (m_index == 0) { 
        v_Src = m_round1;
    } else if (m_index == 1) {
        v_Src = m_round2;
    }

    for (int i = 0, count = 1; i < v_Src.size(); i++, count++) {     // count用于分组，六人一组
        // cout << "选手id：" << v_Src[i] << "选手姓名：" << m_speakers[v_Src[i]].m_name << endl;
        deque<double> scoreContainer;
        for (int j = 0; j < 10; j++) {
            double score = random() % 401 + 600;    //十位评委，每位评委打分从460～1000 / 10
            score /= 10.f;
            scoreContainer.push_back(score);
            // cout << score << " ";                //  打印每一位评委的打分
        }
        // cout << endl;
        sort(scoreContainer.begin(), scoreContainer.end());
        scoreContainer.pop_back();                  //  去掉最高分
        scoreContainer.pop_front();                 //  去掉最低分
        double result = accumulate(scoreContainer.begin(), scoreContainer.end(), 0);
        result /= (double)scoreContainer.size();    //  获取平均分
        // cout << "平均分：" << result << endl;

        groupScoreMap.insert(make_pair(result, v_Src[i]));
        m_speakers[v_Src[i]].m_scores[m_index] = result;    //   存第一轮的平均分

        if (count % 6 == 0) {       //  第一组， count == 6
            cout << "第" << count / 6 << "组结果如下：" << endl;
            int nextCount = 0;
            for (multimap<double, int, greater<double> >::iterator iter = groupScoreMap.begin(); iter != groupScoreMap.end(); iter++, nextCount++) {
                cout << "选手id；" << iter->second << " 选手姓名：" << m_speakers[iter->second].m_name 
                    << " 选手本轮得分：" << m_speakers[iter->second].m_scores[m_index] << endl;
                // 取每组的前三名插入到后一个容器中
                if (m_index == 0 && nextCount < 3) {
                    m_round2.push_back(iter->second);
                }
                else if (m_index == 1 && nextCount < 3) {
                    m_final.push_back(iter->second);
                }
            }
            groupScoreMap.clear();    //   count==6 后清空，来存第二组的信息
        }
    }
    cout << "=====================================" << endl;
    cout << "晋级的选手编号为：" << endl;
    if (m_index == 0) {
        for (int i = 0; i < m_round2.size(); i++) {
            cout << m_round2[i] << " ";
        }
    }
    else if (m_index == 1) {
        for (int i = 0; i < m_final.size(); i++) {
            cout << m_final[i] << " ";
        }
    }
    cout << endl;
    system("read -rsp 'Please Enter to Continue...'");
    cout << endl;
}

void SpeechMgr::showFinalWinner()
{
    cout << "最终比赛结果为：" << endl;
    string orderSeed[3] = {"冠军", "亚军", "季军"};
    for (int i = 0; i < m_final.size(); i++) {
        cout << orderSeed[i] << ": id[" << m_final[i] << "], name[" << 
            m_speakers[m_final[i]].m_name << "], score[" << m_speakers[m_final[i]].m_scores[1] << "]" << endl;
    }
}

void SpeechMgr::writeFinalWinner()
{
    ofstream ofs;
    ofs.open("SpeechSystem.csv", ios::out | ios::app);
    vector<string> newRecord;
    for (int i = 0; i < m_final.size(); i++) {
        newRecord.push_back(to_string(m_final[i]));
        newRecord.push_back(to_string(m_speakers[m_final[i]].m_scores[1]));
        if (i != 0) {
            ofs << "," << m_final[i] << "," << m_speakers[m_final[i]].m_scores[1];
        }
        else {
            ofs << m_final[i] << "," << m_speakers[m_final[i]].m_scores[1];
        }
    }
    ofs << endl;
    ofs.close();
    m_hisVec.push_back(newRecord);
    m_fileFlag = true;
    cout << "文件保存成功！" << endl;
}

void SpeechMgr::showHistory()
{
    if (!m_fileFlag) {
        cout << "文件不存在或无内容！" << endl;
        system("read -rsp 'Please Enter to Continue...'");
        return;
    }
    for (int i = 0; i < m_hisVec.size(); i++) {
        cout << "第" << i + 1 << "届比赛的结果是：" << endl;
        int firstId, secondId, thirdId;
        istringstream iss1(m_hisVec[i][0]);
        istringstream iss2(m_hisVec[i][2]);
        istringstream iss3(m_hisVec[i][4]);
        iss1 >> firstId;
        iss2 >> secondId;
        iss3 >> thirdId;
        cout << "冠军编号: " << firstId << ", 姓名：" << m_speakers[firstId].m_name << ", 分数：" << m_hisVec[i][1] << "\n"
            << "亚军编号: " << secondId << ", 姓名：" << m_speakers[secondId].m_name << ", 分数：" << m_hisVec[i][3] << "\n"
            << "季军编号: " << thirdId << ", 姓名：" << m_speakers[thirdId].m_name << ", 分数：" << m_hisVec[i][5] << endl;
    }
    system("read -rsp 'Please Enter to Continue...'");
}

void SpeechMgr::clearRecord()
{
    cout << "确定要清空记录吗?" << endl;
    cout << "1. 确定" << endl;
    cout << "2. 取消" << endl;
    int select;
    cin >> select;
    if (select == 1) {
        ofstream ofs;
        ofs.open("SpeechSystem.csv", ios::trunc);
        ofs.close();
        init();
        m_fileFlag = false;
        cout << "清除成功！" << endl;
    }
    system("Please Enter to Continue...");
}