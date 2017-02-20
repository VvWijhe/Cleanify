//
// Created by victor on 20.02.17.
//

#ifndef GOOGLE_TEST_CLASSNAME_H
#define GOOGLE_TEST_CLASSNAME_H


class ClassName {

int age;
public:
    int getAge() const {
        return age;
    }

    void setAge(int age) {
        ClassName::age = age;
    }
};


#endif //GOOGLE_TEST_CLASSNAME_H
