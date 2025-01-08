#include <gtest/gtest.h>
#include "../source/disjoint-set.hpp" 

TEST(DisjointSetUnionTest, TestFindFixed) {
    vector<int> parents = {0,3,2,9,3,4,6,2,8,2};
    dsu mydsu(parents); // Initialize DSU with parents

#ifdef RECURSIVE_FIND    
    EXPECT_EQ(mydsu.find(5), 2);
    vector<int> expected_parents = {0,3,2,2,2,2,6,2,8,2};
    EXPECT_TRUE(std::equal(mydsu.getParent().begin(), mydsu.getParent().end(), expected_parents.begin()));
#else
    // iterative
    EXPECT_EQ(mydsu.find(5), 3);
    vector<int> expected_parents = {0,3,2,2,9,3,6,2,8,2};
    EXPECT_TRUE(std::equal(mydsu.getParent().begin(), mydsu.getParent().end(), expected_parents.begin()));
#endif
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
