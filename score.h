#ifndef _SCORE_H_
#define _SCORE_H_

class Score {
    int hi_score;
    int cur_score;
    int level;

  public:
    int getScore();
    void cleared_row(int);

};

#endif