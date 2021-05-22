
#include "../gtest/gtest.h"
#include "TPtrList.h"

TEST(TestSuite, can_create_list)
{
    ASSERT_NO_THROW(TPtrList<int>c);
}

TEST(List, can_push_item_to_list)
{
    TPtrList<int>c;
    ASSERT_NO_THROW(c.InsFirst(1));
}

TEST(List, can_push_item_to_list_back)
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsFirst(i);
    }
    ASSERT_NO_THROW(c.InsLast(1));
}

TEST(List, can_get_iterator)
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsFirst(i);
    }
    ASSERT_NO_THROW(c.begin());
}

TEST(List, can_iterate_list)
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsLast(i);
    }
    TPtrList<int>::iterator iter = c.begin();
    for (int j = 0; j < 10; ++j) {
        EXPECT_EQ(*iter, j);
        iter++;
    }
}

TEST(List, can_copy_list)
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsLast(i);
    }

    TPtrList<int>b = c;
    TPtrList<int>::iterator iter = b.begin();
    for (int j = 0; j < 10; ++j) {
        EXPECT_EQ(*iter, j);
        iter++;
    }
}

TEST(List, default_list_is_empty)
{
    TPtrList<int>c;
    EXPECT_EQ(c.IsEmpty(), true);
}

TEST(List, can_delete_items)
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsLast(i);
    }

    for (int j = 0; j < 10; ++j) {
        c.DelFirst();
    }
    EXPECT_EQ(c.IsEmpty(), true);
}

TEST(List, can_get_first_elem)
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsLast(i);
    }
    int data = c.GetFirst()->GetData();
    EXPECT_EQ(data, 0);
}

TEST(List, can_get_last_elem)
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsLast(i);
    }
    int data = c.GetLast()->GetData();
    EXPECT_EQ(data, 9);
}

TEST(List, can_get_list_with_multiplies_to_K)
{
    TPtrList<int>c;
    for (int i = 0; i < 10; ++i) {
        c.InsLast(i);
    }
    TPtrList<int>b = c.multiplesToK(2);
    TPtrList<int>::iterator i = b.begin();
    while (i != b.end()) {
        EXPECT_EQ(*i % 2, 0);
        i++;
    }
}