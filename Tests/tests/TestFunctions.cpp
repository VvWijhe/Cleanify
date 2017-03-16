//
// Created by victor on 13.03.17.
//

#include "TestFunctions.h"

using testing::Eq;
using namespace std;

namespace{

    class classDeclaration : public testing::Test{
    public: TestFunctions obj;
        classDeclaration(){
            obj;
        }

    };

}


TEST_F(classDeclaration, test1){

    obj.SCI.sendCommand({128}, {0});
    ASSERT_EQ("", "");
}

TEST_F(classDeclaration, test2){
    ASSERT_EQ("", "1");
}

