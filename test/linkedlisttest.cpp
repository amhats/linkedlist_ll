#include "../linkedlist.cpp"
#include "gtest/gtest.h"

namespace{
    class LinkedListTest: public ::testing::Test{
    public:
            LinkedListTest(){

            }

            virtual ~LinkedListTest(){

            }
    protected:
            virtual void SetUp(){
                l.push_back_ll(5);
            	l.push_back_ll(2);
            	l.push_back_ll(9);
            }

            virtual void TearDown(){

            }

            LinkedList l;
    };

    TEST_F(LinkedListTest, IsNotEmptyInitially){
        EXPECT_EQ(2, l.size_ll());
    }
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
