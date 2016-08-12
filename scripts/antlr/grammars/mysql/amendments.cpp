#define SAVED_NULL NULL
#undef NULL
#define SAVED_UNICODE UNICODE
#undef UNICODE

#define NULL SAVED_NULL
#define UNICODE SAVED_UNICODE

#ifdef __linux__
virtual std::string getSourceName() override;
#endif

#ifdef __linux__
std::string mysqlLexer::getSourceName()
{
    return Lexer::getSourceName();
}
#endif
