#include "gtest/gtest.h"
#include "graph.h"

using namespace mits;
using namespace std;

class BitMapMatrixTest: public::testing::Test{
	protected:
    	virtual void SetUp(){
    	}
    	virtual void TearDown(){
    	}
};

TEST_F(BitMapMatrixTest, creation){
    
    std::cout<<"Testing Bit Map creation";
	mits::BitMapMatrix bMap(3);
	bMap.setBit(1,1);
    EXPECT_EQ(true, bMap.getBit(1,1));
}

TEST_F(BitMapMatrixTest, graphcreation){
    int adjcMat[6][6]={\
                        {0, 1, 0, 0, 1, 1},\
                        {1, 0, 0, 1, 1, 0},\
                        {0, 0, 0, 1, 0, 0},\
                        {0, 1, 1, 0, 1, 1},\
                        {1, 1, 0, 1, 0, 0},\
                        {1, 0, 0, 1, 0, 0}\
                    };
    mits::BitMapMatrix bmm(6);
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            adjcMat[i][j]==1 ? bmm.setBit(i,j) : bmm.resetBit(i,j);
        }
    }
    
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            EXPECT_EQ(adjcMat[i][j], bmm.getBit(i,j));
        }
        cout<<endl;
    }
}
