void test()
{
    try
    {
        throw new Error("error message");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}