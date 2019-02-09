/*
 Группа людей называется современниками если был такой момент, когда они могли собраться вместе.
 Для этого в этот момент каждому из них должно было  уже исполниться 18 лет, но ещё не исполниться 80 лет.
 Дан список Жизни Великих Людей. Необходимо получить максимальное количество современников.
 В день 18летия человек уже может принимать участие в собраниях, а в день 80летия и в день смерти уже не может.
 Замечание. Человек мог не дожить до 18-летия, либо умереть в день 18-летия. В этих случаях принимать участие
 в собраниях он не мог.
*/


#include <iostream>

#define YEARS_80 29200
#define YEARS_18 6570
#define DAYS_IN_MONTH 30
#define DAYS_IN_YEAR 365


enum typeOfEvent {
    BEGINING,
    ENDING
};


struct event {
    int timeStamp;
    typeOfEvent type;
};


class Human {
public:
    Human(int birthStamp, int deathStamp);

    bool isParticipant() { return isValid; }
    int getAdultStamp() { return adultTimeStamp; }
    int getAgedStamp() { return agedTimeStamp; }

private:
    bool isValid = true;
    int adultTimeStamp = -1;
    int agedTimeStamp = -1;
};

Human::Human(int birthStamp, int deathStamp) {
    this->adultTimeStamp = birthStamp + YEARS_18;

    if (this->adultTimeStamp < deathStamp) {
        this->agedTimeStamp = std::min(deathStamp, birthStamp + YEARS_80) - 1;
    }
    else {
        this->isValid = false;
    }
}


int getTimeStamp(int day, int month, int year) {
    int timeStamp = DAYS_IN_YEAR * year + DAYS_IN_MONTH * month + day;
    return timeStamp;
}


class Comparator {
public:
    bool operator()(const event &lhs, const event &rhs) {
        return lhs.timeStamp <= rhs.timeStamp;
    }
};


template<class T, class Compare>
void merge(const T *arrFirst, int firstLength, const T *arrSecond, int secondLength, T *result, Compare cmp) {
    int i = 0; //index of arrFirst
    int j = 0; // index of arrSecond

    while (i < firstLength && j < secondLength) {
        if (cmp(arrFirst[i], arrSecond[j])) {
            result[i + j] = arrFirst[i];
            i++;
        }
        else {
            result[i + j] = arrSecond[j];
            j++;
        }
    }
    //handler of the remaining elements
    if (i == firstLength) {
        for (; j < secondLength; ++j)
            result[i + j] = arrSecond[j];
    }
    else {
        for (; i < firstLength; ++i)
            result[i + j] = arrFirst[i];
    }
};


template<class T, class Compare>
void MergeSort(T *arr, int length, Compare cmp) {
    if (length <= 1) return;

    int firstLength = length / 2;
    int secondLength = length - firstLength;

    MergeSort(arr, firstLength, cmp);
    MergeSort(arr + firstLength, secondLength, cmp);

    T *tmp = new T [length];
    merge(arr, firstLength, arr + firstLength, secondLength, tmp, cmp);
    std::copy(tmp, tmp + length, arr);
    delete  [] tmp;
};


int findContemporaries(event *events, int size) {
    int maxContemporaries = 1;
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        events[i].type == BEGINING ? counter++ : counter--;

        if (counter > maxContemporaries)
            maxContemporaries = counter;
    }
    return maxContemporaries;
}


int main() {

    int sizeOfMembers = 0;
    std::cin >> sizeOfMembers;

    auto events = new event [sizeOfMembers * 2];
    int countOfValidEvents = 0;

    for (int i = 0; i < sizeOfMembers; ++i) {
        int day = 0;
        int month = 0;
        int year = 0;

        std::cin >> day >> month >> year;
        int birthTimeStamp = getTimeStamp(day, month, year);

        std::cin >> day >> month >> year;
        int deathTimeStamp = getTimeStamp(day, month, year);

        Human pretender(birthTimeStamp, deathTimeStamp);

        if (pretender.isParticipant()) {
            events[countOfValidEvents].timeStamp = pretender.getAdultStamp();
            events[countOfValidEvents++].type = BEGINING;
            events[countOfValidEvents].timeStamp = pretender.getAgedStamp();
            events[countOfValidEvents++].type = ENDING;
        }
    }

    MergeSort(events, countOfValidEvents, Comparator());

    std::cout << findContemporaries(events, countOfValidEvents);
    
    delete [] events;
    return 0;
}
