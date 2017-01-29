// C++ library includes
#include <fstream>
#include <string>

// External library includes
#include <gtest/gtest.h>

// Internal program includes
#include "sample1_generated.h"

TEST(DISABLED_Ormc_Regression_FlatBuffers, TestSet1)
{
    flatbuffers::FlatBufferBuilder builder;
    //    auto userId = builder.CreateString("1");
    //    auto user1 = flat::CreateUser(builder, userId);
    //    builder.Finish(user1);

    auto userName = builder.CreateString("abc");
    flat::UserBuilder userBuilder(builder);
    userBuilder.add_name(userName);
    auto user2 = userBuilder.Finish();
    builder.Finish(user2);

    std::ofstream stream("./test.bin");
    stream.write(reinterpret_cast<char *>(builder.GetBufferPointer()), builder.GetSize());
}

TEST(DISABLED_Ormc_Regression_FlatBuffers, TestSet2)
{
    flatbuffers::FlatBufferBuilder builder;
    std::ifstream stream("./test.bin");
    std::string buffer(std::istreambuf_iterator<char>(stream), {});

    // auto user1 = flatbuffers::GetRoot<flat::User>(buffer.c_str());
    auto user1 = flat::GetUser(buffer.c_str());
    auto userName = user1->name()->c_str();
    ASSERT_STREQ(userName, "abc");
}
