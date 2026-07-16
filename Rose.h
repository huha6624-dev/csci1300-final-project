#ifndef ROSE_H
#define ROSE_H

// The Rose the Prince left behind. Her thirst rises over time and
// falls when she is watered; if she goes too long unwatered she wilts.
class Rose {
private:
    int thirst;      // 0 = perfectly watered, higher = thirstier
    int wiltLimit;    // thirst level at which the Rose wilts

public:
    Rose();

    void water();
    void increaseThirst();

    int getThirst();
    bool isWilted();
};

#endif
