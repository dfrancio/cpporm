
// Generated from grammars/mysql/mysql.g4 by ANTLR 4.6

#include "mysqlListener.h"
#include "mysqlVisitor.h"

#include "mysqlParser.h"

using namespace antlrcpp;
using namespace mysql;
using namespace antlr4;

mysqlParser::mysqlParser(TokenStream *input) : Parser(input)
{
    _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

mysqlParser::~mysqlParser()
{
    delete _interpreter;
}

std::string mysqlParser::getGrammarFileName() const
{
    return "mysql.g4";
}

const std::vector<std::string> &mysqlParser::getRuleNames() const
{
    return _ruleNames;
}

dfa::Vocabulary &mysqlParser::getVocabulary() const
{
    return _vocabulary;
}

//----------------- ParseContext ------------------------------------------------------------------

mysqlParser::ParseContext::ParseContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::ParseContext::EOF()
{
    return getToken(mysqlParser::EOF, 0);
}

std::vector<mysqlParser::StatementContext *> mysqlParser::ParseContext::statement()
{
    return getRuleContexts<mysqlParser::StatementContext>();
}

mysqlParser::StatementContext *mysqlParser::ParseContext::statement(size_t i)
{
    return getRuleContext<mysqlParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> mysqlParser::ParseContext::SEMI()
{
    return getTokens(mysqlParser::SEMI);
}

tree::TerminalNode *mysqlParser::ParseContext::SEMI(size_t i)
{
    return getToken(mysqlParser::SEMI, i);
}

size_t mysqlParser::ParseContext::getRuleIndex() const
{
    return mysqlParser::RuleParse;
}

void mysqlParser::ParseContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterParse(this);
}

void mysqlParser::ParseContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitParse(this);
}

antlrcpp::Any mysqlParser::ParseContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitParse(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::ParseContext *mysqlParser::parse()
{
    ParseContext *_localctx = _tracker.createInstance<ParseContext>(_ctx, getState());
    enterRule(_localctx, 0, mysqlParser::RuleParse);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(261);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::ALTER || _la == mysqlParser::CREATE

               || _la == mysqlParser::DROP || _la == mysqlParser::SET)
        {
            setState(256);
            statement();
            setState(257);
            match(mysqlParser::SEMI);
            setState(263);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(264);
        match(mysqlParser::EOF);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- StatementContext
//------------------------------------------------------------------

mysqlParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::AssignmentContext *mysqlParser::StatementContext::assignment()
{
    return getRuleContext<mysqlParser::AssignmentContext>(0);
}

mysqlParser::Drop_tableContext *mysqlParser::StatementContext::drop_table()
{
    return getRuleContext<mysqlParser::Drop_tableContext>(0);
}

mysqlParser::Alter_tableContext *mysqlParser::StatementContext::alter_table()
{
    return getRuleContext<mysqlParser::Alter_tableContext>(0);
}

mysqlParser::Create_tableContext *mysqlParser::StatementContext::create_table()
{
    return getRuleContext<mysqlParser::Create_tableContext>(0);
}

size_t mysqlParser::StatementContext::getRuleIndex() const
{
    return mysqlParser::RuleStatement;
}

void mysqlParser::StatementContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterStatement(this);
}

void mysqlParser::StatementContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitStatement(this);
}

antlrcpp::Any mysqlParser::StatementContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitStatement(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::StatementContext *mysqlParser::statement()
{
    StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
    enterRule(_localctx, 2, mysqlParser::RuleStatement);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(270);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::SET:
        {
            enterOuterAlt(_localctx, 1);
            setState(266);
            assignment();
            break;
        }

        case mysqlParser::DROP:
        {
            enterOuterAlt(_localctx, 2);
            setState(267);
            drop_table();
            break;
        }

        case mysqlParser::ALTER:
        {
            enterOuterAlt(_localctx, 3);
            setState(268);
            alter_table();
            break;
        }

        case mysqlParser::CREATE:
        {
            enterOuterAlt(_localctx, 4);
            setState(269);
            create_table();
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AssignmentContext
//------------------------------------------------------------------

mysqlParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::AssignmentContext::SET()
{
    return getToken(mysqlParser::SET, 0);
}

mysqlParser::IdentifierContext *mysqlParser::AssignmentContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

tree::TerminalNode *mysqlParser::AssignmentContext::EQUAL()
{
    return getToken(mysqlParser::EQUAL, 0);
}

mysqlParser::LiteralContext *mysqlParser::AssignmentContext::literal()
{
    return getRuleContext<mysqlParser::LiteralContext>(0);
}

size_t mysqlParser::AssignmentContext::getRuleIndex() const
{
    return mysqlParser::RuleAssignment;
}

void mysqlParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterAssignment(this);
}

void mysqlParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitAssignment(this);
}

antlrcpp::Any mysqlParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitAssignment(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::AssignmentContext *mysqlParser::assignment()
{
    AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
    enterRule(_localctx, 4, mysqlParser::RuleAssignment);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(272);
        match(mysqlParser::SET);
        setState(273);
        identifier();
        setState(274);
        match(mysqlParser::EQUAL);
        setState(275);
        literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Drop_tableContext
//------------------------------------------------------------------

mysqlParser::Drop_tableContext::Drop_tableContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Drop_tableContext::DROP()
{
    return getToken(mysqlParser::DROP, 0);
}

tree::TerminalNode *mysqlParser::Drop_tableContext::TABLE()
{
    return getToken(mysqlParser::TABLE, 0);
}

mysqlParser::Table_name_listContext *mysqlParser::Drop_tableContext::table_name_list()
{
    return getRuleContext<mysqlParser::Table_name_listContext>(0);
}

tree::TerminalNode *mysqlParser::Drop_tableContext::TEMPORARY()
{
    return getToken(mysqlParser::TEMPORARY, 0);
}

tree::TerminalNode *mysqlParser::Drop_tableContext::IF()
{
    return getToken(mysqlParser::IF, 0);
}

tree::TerminalNode *mysqlParser::Drop_tableContext::EXISTS()
{
    return getToken(mysqlParser::EXISTS, 0);
}

tree::TerminalNode *mysqlParser::Drop_tableContext::RESTRICT()
{
    return getToken(mysqlParser::RESTRICT, 0);
}

tree::TerminalNode *mysqlParser::Drop_tableContext::CASCADE()
{
    return getToken(mysqlParser::CASCADE, 0);
}

size_t mysqlParser::Drop_tableContext::getRuleIndex() const
{
    return mysqlParser::RuleDrop_table;
}

void mysqlParser::Drop_tableContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterDrop_table(this);
}

void mysqlParser::Drop_tableContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitDrop_table(this);
}

antlrcpp::Any mysqlParser::Drop_tableContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitDrop_table(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Drop_tableContext *mysqlParser::drop_table()
{
    Drop_tableContext *_localctx = _tracker.createInstance<Drop_tableContext>(_ctx, getState());
    enterRule(_localctx, 6, mysqlParser::RuleDrop_table);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(277);
        match(mysqlParser::DROP);
        setState(279);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::TEMPORARY)
        {
            setState(278);
            match(mysqlParser::TEMPORARY);
        }
        setState(281);
        match(mysqlParser::TABLE);
        setState(284);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::IF)
        {
            setState(282);
            match(mysqlParser::IF);
            setState(283);
            match(mysqlParser::EXISTS);
        }
        setState(286);
        table_name_list();
        setState(288);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::CASCADE || _la == mysqlParser::RESTRICT)
        {
            setState(287);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::CASCADE || _la == mysqlParser::RESTRICT))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Table_name_listContext
//------------------------------------------------------------------

mysqlParser::Table_name_listContext::Table_name_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<mysqlParser::Table_nameContext *> mysqlParser::Table_name_listContext::table_name()
{
    return getRuleContexts<mysqlParser::Table_nameContext>();
}

mysqlParser::Table_nameContext *mysqlParser::Table_name_listContext::table_name(size_t i)
{
    return getRuleContext<mysqlParser::Table_nameContext>(i);
}

std::vector<tree::TerminalNode *> mysqlParser::Table_name_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Table_name_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Table_name_listContext::getRuleIndex() const
{
    return mysqlParser::RuleTable_name_list;
}

void mysqlParser::Table_name_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterTable_name_list(this);
}

void mysqlParser::Table_name_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitTable_name_list(this);
}

antlrcpp::Any mysqlParser::Table_name_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitTable_name_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Table_name_listContext *mysqlParser::table_name_list()
{
    Table_name_listContext *_localctx
        = _tracker.createInstance<Table_name_listContext>(_ctx, getState());
    enterRule(_localctx, 8, mysqlParser::RuleTable_name_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(290);
        table_name();
        setState(295);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(291);
            match(mysqlParser::COMMA);
            setState(292);
            table_name();
            setState(297);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Create_tableContext
//------------------------------------------------------------------

mysqlParser::Create_tableContext::Create_tableContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Create_tableContext::CREATE()
{
    return getToken(mysqlParser::CREATE, 0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::TABLE()
{
    return getToken(mysqlParser::TABLE, 0);
}

mysqlParser::Table_nameContext *mysqlParser::Create_tableContext::table_name()
{
    return getRuleContext<mysqlParser::Table_nameContext>(0);
}

mysqlParser::Create_definition_listContext *mysqlParser::Create_tableContext::
    create_definition_list()
{
    return getRuleContext<mysqlParser::Create_definition_listContext>(0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::TEMPORARY()
{
    return getToken(mysqlParser::TEMPORARY, 0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::IF()
{
    return getToken(mysqlParser::IF, 0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::NOT()
{
    return getToken(mysqlParser::NOT, 0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::EXISTS()
{
    return getToken(mysqlParser::EXISTS, 0);
}

mysqlParser::Table_option_listContext *mysqlParser::Create_tableContext::table_option_list()
{
    return getRuleContext<mysqlParser::Table_option_listContext>(0);
}

mysqlParser::Partition_specificationContext *mysqlParser::Create_tableContext::
    partition_specification()
{
    return getRuleContext<mysqlParser::Partition_specificationContext>(0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::LIKE()
{
    return getToken(mysqlParser::LIKE, 0);
}

mysqlParser::Old_table_nameContext *mysqlParser::Create_tableContext::old_table_name()
{
    return getRuleContext<mysqlParser::Old_table_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

mysqlParser::Query_expressionContext *mysqlParser::Create_tableContext::query_expression()
{
    return getRuleContext<mysqlParser::Query_expressionContext>(0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::AS()
{
    return getToken(mysqlParser::AS, 0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::IGNORE()
{
    return getToken(mysqlParser::IGNORE, 0);
}

tree::TerminalNode *mysqlParser::Create_tableContext::REPLACE()
{
    return getToken(mysqlParser::REPLACE, 0);
}

size_t mysqlParser::Create_tableContext::getRuleIndex() const
{
    return mysqlParser::RuleCreate_table;
}

void mysqlParser::Create_tableContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCreate_table(this);
}

void mysqlParser::Create_tableContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCreate_table(this);
}

antlrcpp::Any mysqlParser::Create_tableContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCreate_table(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Create_tableContext *mysqlParser::create_table()
{
    Create_tableContext *_localctx = _tracker.createInstance<Create_tableContext>(_ctx, getState());
    enterRule(_localctx, 10, mysqlParser::RuleCreate_table);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(364);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx))
        {
        case 1:
        {
            enterOuterAlt(_localctx, 1);
            setState(298);
            match(mysqlParser::CREATE);
            setState(300);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::TEMPORARY)
            {
                setState(299);
                match(mysqlParser::TEMPORARY);
            }
            setState(302);
            match(mysqlParser::TABLE);
            setState(306);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::IF)
            {
                setState(303);
                match(mysqlParser::IF);
                setState(304);
                match(mysqlParser::NOT);
                setState(305);
                match(mysqlParser::EXISTS);
            }
            setState(308);
            table_name();
            setState(309);
            create_definition_list();
            setState(311);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (((((_la - 22) & ~0x3fULL) == 0)
                 && ((1ULL << (_la - 22)) & ((1ULL << (mysqlParser::AUTO_INCREMENT - 22))
                                             | (1ULL << (mysqlParser::AVG_ROW_LENGTH - 22))
                                             | (1ULL << (mysqlParser::CHARACTER - 22))
                                             | (1ULL << (mysqlParser::CHARSET - 22))
                                             | (1ULL << (mysqlParser::CHECKSUM - 22))
                                             | (1ULL << (mysqlParser::COLLATE - 22))
                                             | (1ULL << (mysqlParser::COMMENT - 22))
                                             | (1ULL << (mysqlParser::COMPRESSION - 22))
                                             | (1ULL << (mysqlParser::CONNECTION - 22))))
                     != 0)
                || ((((_la - 99) & ~0x3fULL) == 0)
                    && ((1ULL << (_la - 99)) & ((1ULL << (mysqlParser::DATA - 99))
                                                | (1ULL << (mysqlParser::DEFAULT - 99))
                                                | (1ULL << (mysqlParser::DELAY_KEY_WRITE - 99))
                                                | (1ULL << (mysqlParser::ENCRYPTION - 99))
                                                | (1ULL << (mysqlParser::ENGINE - 99))))
                        != 0)
                || ((((_la - 220) & ~0x3fULL) == 0)
                    && ((1ULL << (_la - 220)) & ((1ULL << (mysqlParser::INDEX - 220))
                                                 | (1ULL << (mysqlParser::INSERT_METHOD - 220))
                                                 | (1ULL << (mysqlParser::KEY_BLOCK_SIZE - 220))))
                        != 0)
                || _la == mysqlParser::MAX_ROWS

                || _la == mysqlParser::MIN_ROWS || _la == mysqlParser::PACK_KEYS

                || _la == mysqlParser::PASSWORD || _la == mysqlParser::ROW_FORMAT

                || _la == mysqlParser::STATS_AUTO_RECALC
                || ((((_la - 530) & ~0x3fULL) == 0)
                    && ((1ULL << (_la - 530)) & ((1ULL << (mysqlParser::STATS_PERSISTENT - 530))
                                                 | (1ULL << (mysqlParser::STATS_SAMPLE_PAGES - 530))
                                                 | (1ULL << (mysqlParser::TABLESPACE - 530))
                                                 | (1ULL << (mysqlParser::UNION - 530))))
                        != 0))
            {
                setState(310);
                table_option_list();
            }
            setState(314);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::PARTITION)
            {
                setState(313);
                partition_specification();
            }
            break;
        }

        case 2:
        {
            enterOuterAlt(_localctx, 2);
            setState(316);
            match(mysqlParser::CREATE);
            setState(318);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::TEMPORARY)
            {
                setState(317);
                match(mysqlParser::TEMPORARY);
            }
            setState(320);
            match(mysqlParser::TABLE);
            setState(324);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::IF)
            {
                setState(321);
                match(mysqlParser::IF);
                setState(322);
                match(mysqlParser::NOT);
                setState(323);
                match(mysqlParser::EXISTS);
            }
            setState(326);
            table_name();
            setState(334);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::LIKE:
            {
                setState(327);
                match(mysqlParser::LIKE);
                setState(328);
                old_table_name();
                break;
            }

            case mysqlParser::LPAREN:
            {
                setState(329);
                match(mysqlParser::LPAREN);
                setState(330);
                match(mysqlParser::LIKE);
                setState(331);
                old_table_name();
                setState(332);
                match(mysqlParser::RPAREN);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 3:
        {
            enterOuterAlt(_localctx, 3);
            setState(336);
            match(mysqlParser::CREATE);
            setState(338);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::TEMPORARY)
            {
                setState(337);
                match(mysqlParser::TEMPORARY);
            }
            setState(340);
            match(mysqlParser::TABLE);
            setState(344);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::IF)
            {
                setState(341);
                match(mysqlParser::IF);
                setState(342);
                match(mysqlParser::NOT);
                setState(343);
                match(mysqlParser::EXISTS);
            }
            setState(346);
            table_name();
            setState(348);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx))
            {
            case 1:
            {
                setState(347);
                create_definition_list();
                break;
            }
            }
            setState(351);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (((((_la - 22) & ~0x3fULL) == 0)
                 && ((1ULL << (_la - 22)) & ((1ULL << (mysqlParser::AUTO_INCREMENT - 22))
                                             | (1ULL << (mysqlParser::AVG_ROW_LENGTH - 22))
                                             | (1ULL << (mysqlParser::CHARACTER - 22))
                                             | (1ULL << (mysqlParser::CHARSET - 22))
                                             | (1ULL << (mysqlParser::CHECKSUM - 22))
                                             | (1ULL << (mysqlParser::COLLATE - 22))
                                             | (1ULL << (mysqlParser::COMMENT - 22))
                                             | (1ULL << (mysqlParser::COMPRESSION - 22))
                                             | (1ULL << (mysqlParser::CONNECTION - 22))))
                     != 0)
                || ((((_la - 99) & ~0x3fULL) == 0)
                    && ((1ULL << (_la - 99)) & ((1ULL << (mysqlParser::DATA - 99))
                                                | (1ULL << (mysqlParser::DEFAULT - 99))
                                                | (1ULL << (mysqlParser::DELAY_KEY_WRITE - 99))
                                                | (1ULL << (mysqlParser::ENCRYPTION - 99))
                                                | (1ULL << (mysqlParser::ENGINE - 99))))
                        != 0)
                || ((((_la - 220) & ~0x3fULL) == 0)
                    && ((1ULL << (_la - 220)) & ((1ULL << (mysqlParser::INDEX - 220))
                                                 | (1ULL << (mysqlParser::INSERT_METHOD - 220))
                                                 | (1ULL << (mysqlParser::KEY_BLOCK_SIZE - 220))))
                        != 0)
                || _la == mysqlParser::MAX_ROWS

                || _la == mysqlParser::MIN_ROWS || _la == mysqlParser::PACK_KEYS

                || _la == mysqlParser::PASSWORD || _la == mysqlParser::ROW_FORMAT

                || _la == mysqlParser::STATS_AUTO_RECALC
                || ((((_la - 530) & ~0x3fULL) == 0)
                    && ((1ULL << (_la - 530)) & ((1ULL << (mysqlParser::STATS_PERSISTENT - 530))
                                                 | (1ULL << (mysqlParser::STATS_SAMPLE_PAGES - 530))
                                                 | (1ULL << (mysqlParser::TABLESPACE - 530))
                                                 | (1ULL << (mysqlParser::UNION - 530))))
                        != 0))
            {
                setState(350);
                table_option_list();
            }
            setState(354);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::PARTITION)
            {
                setState(353);
                partition_specification();
            }
            setState(357);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::IGNORE || _la == mysqlParser::REPLACE)
            {
                setState(356);
                _la = _input->LA(1);
                if (!(_la == mysqlParser::IGNORE || _la == mysqlParser::REPLACE))
                {
                    _errHandler->recoverInline(this);
                }
                else
                {
                    _errHandler->reportMatch(this);
                    consume();
                }
            }
            setState(360);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::AS)
            {
                setState(359);
                match(mysqlParser::AS);
            }
            setState(362);
            query_expression();
            break;
        }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Create_definitionContext
//------------------------------------------------------------------

mysqlParser::Create_definitionContext::Create_definitionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Column_nameContext *mysqlParser::Create_definitionContext::column_name()
{
    return getRuleContext<mysqlParser::Column_nameContext>(0);
}

mysqlParser::Column_definitionContext *mysqlParser::Create_definitionContext::column_definition()
{
    return getRuleContext<mysqlParser::Column_definitionContext>(0);
}

mysqlParser::Index_definitionContext *mysqlParser::Create_definitionContext::index_definition()
{
    return getRuleContext<mysqlParser::Index_definitionContext>(0);
}

tree::TerminalNode *mysqlParser::Create_definitionContext::CHECK()
{
    return getToken(mysqlParser::CHECK, 0);
}

mysqlParser::Check_expressionContext *mysqlParser::Create_definitionContext::check_expression()
{
    return getRuleContext<mysqlParser::Check_expressionContext>(0);
}

size_t mysqlParser::Create_definitionContext::getRuleIndex() const
{
    return mysqlParser::RuleCreate_definition;
}

void mysqlParser::Create_definitionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCreate_definition(this);
}

void mysqlParser::Create_definitionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCreate_definition(this);
}

antlrcpp::Any mysqlParser::Create_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCreate_definition(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Create_definitionContext *mysqlParser::create_definition()
{
    Create_definitionContext *_localctx
        = _tracker.createInstance<Create_definitionContext>(_ctx, getState());
    enterRule(_localctx, 12, mysqlParser::RuleCreate_definition);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(372);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::ID:
        case mysqlParser::BQUOTED_STRING:
        {
            enterOuterAlt(_localctx, 1);
            setState(366);
            column_name();
            setState(367);
            column_definition();
            break;
        }

        case mysqlParser::CONSTRAINT:
        case mysqlParser::FOREIGN:
        case mysqlParser::FULLTEXT:
        case mysqlParser::INDEX:
        case mysqlParser::KEY:
        case mysqlParser::PRIMARY:
        case mysqlParser::SPATIAL:
        case mysqlParser::UNIQUE:
        {
            enterOuterAlt(_localctx, 2);
            setState(369);
            index_definition();
            break;
        }

        case mysqlParser::CHECK:
        {
            enterOuterAlt(_localctx, 3);
            setState(370);
            match(mysqlParser::CHECK);
            setState(371);
            check_expression();
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Index_definitionContext
//------------------------------------------------------------------

mysqlParser::Index_definitionContext::Index_definitionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Index_definitionContext::PRIMARY()
{
    return getToken(mysqlParser::PRIMARY, 0);
}

tree::TerminalNode *mysqlParser::Index_definitionContext::KEY()
{
    return getToken(mysqlParser::KEY, 0);
}

mysqlParser::Index_column_listContext *mysqlParser::Index_definitionContext::index_column_list()
{
    return getRuleContext<mysqlParser::Index_column_listContext>(0);
}

mysqlParser::Index_option_listContext *mysqlParser::Index_definitionContext::index_option_list()
{
    return getRuleContext<mysqlParser::Index_option_listContext>(0);
}

mysqlParser::ConstraintContext *mysqlParser::Index_definitionContext::constraint()
{
    return getRuleContext<mysqlParser::ConstraintContext>(0);
}

mysqlParser::Index_structureContext *mysqlParser::Index_definitionContext::index_structure()
{
    return getRuleContext<mysqlParser::Index_structureContext>(0);
}

tree::TerminalNode *mysqlParser::Index_definitionContext::INDEX()
{
    return getToken(mysqlParser::INDEX, 0);
}

mysqlParser::Index_nameContext *mysqlParser::Index_definitionContext::index_name()
{
    return getRuleContext<mysqlParser::Index_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Index_definitionContext::UNIQUE()
{
    return getToken(mysqlParser::UNIQUE, 0);
}

tree::TerminalNode *mysqlParser::Index_definitionContext::FULLTEXT()
{
    return getToken(mysqlParser::FULLTEXT, 0);
}

tree::TerminalNode *mysqlParser::Index_definitionContext::SPATIAL()
{
    return getToken(mysqlParser::SPATIAL, 0);
}

tree::TerminalNode *mysqlParser::Index_definitionContext::FOREIGN()
{
    return getToken(mysqlParser::FOREIGN, 0);
}

mysqlParser::Reference_definitionContext *mysqlParser::Index_definitionContext::
    reference_definition()
{
    return getRuleContext<mysqlParser::Reference_definitionContext>(0);
}

size_t mysqlParser::Index_definitionContext::getRuleIndex() const
{
    return mysqlParser::RuleIndex_definition;
}

void mysqlParser::Index_definitionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIndex_definition(this);
}

void mysqlParser::Index_definitionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIndex_definition(this);
}

antlrcpp::Any mysqlParser::Index_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIndex_definition(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Index_definitionContext *mysqlParser::index_definition()
{
    Index_definitionContext *_localctx
        = _tracker.createInstance<Index_definitionContext>(_ctx, getState());
    enterRule(_localctx, 14, mysqlParser::RuleIndex_definition);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(432);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx))
        {
        case 1:
        {
            enterOuterAlt(_localctx, 1);
            setState(375);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::CONSTRAINT)
            {
                setState(374);
                constraint();
            }
            setState(377);
            match(mysqlParser::PRIMARY);
            setState(378);
            match(mysqlParser::KEY);
            setState(380);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::BTREE || _la == mysqlParser::HASH)
            {
                setState(379);
                index_structure();
            }
            setState(382);
            index_column_list();
            setState(383);
            index_option_list();
            break;
        }

        case 2:
        {
            enterOuterAlt(_localctx, 2);
            setState(385);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::INDEX

                  || _la == mysqlParser::KEY))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
            setState(387);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::ID

                || _la == mysqlParser::BQUOTED_STRING)
            {
                setState(386);
                index_name();
            }
            setState(390);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::BTREE || _la == mysqlParser::HASH)
            {
                setState(389);
                index_structure();
            }
            setState(392);
            index_column_list();
            setState(393);
            index_option_list();
            break;
        }

        case 3:
        {
            enterOuterAlt(_localctx, 3);
            setState(396);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::CONSTRAINT)
            {
                setState(395);
                constraint();
            }
            setState(398);
            match(mysqlParser::UNIQUE);
            setState(400);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::INDEX

                || _la == mysqlParser::KEY)
            {
                setState(399);
                _la = _input->LA(1);
                if (!(_la == mysqlParser::INDEX

                      || _la == mysqlParser::KEY))
                {
                    _errHandler->recoverInline(this);
                }
                else
                {
                    _errHandler->reportMatch(this);
                    consume();
                }
            }
            setState(403);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::ID

                || _la == mysqlParser::BQUOTED_STRING)
            {
                setState(402);
                index_name();
            }
            setState(406);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::BTREE || _la == mysqlParser::HASH)
            {
                setState(405);
                index_structure();
            }
            setState(408);
            index_column_list();
            setState(409);
            index_option_list();
            break;
        }

        case 4:
        {
            enterOuterAlt(_localctx, 4);
            setState(411);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::FULLTEXT || _la == mysqlParser::SPATIAL))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
            setState(413);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::INDEX

                || _la == mysqlParser::KEY)
            {
                setState(412);
                _la = _input->LA(1);
                if (!(_la == mysqlParser::INDEX

                      || _la == mysqlParser::KEY))
                {
                    _errHandler->recoverInline(this);
                }
                else
                {
                    _errHandler->reportMatch(this);
                    consume();
                }
            }
            setState(416);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::ID

                || _la == mysqlParser::BQUOTED_STRING)
            {
                setState(415);
                index_name();
            }
            setState(418);
            index_column_list();
            setState(419);
            index_option_list();
            break;
        }

        case 5:
        {
            enterOuterAlt(_localctx, 5);
            setState(422);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::CONSTRAINT)
            {
                setState(421);
                constraint();
            }
            setState(424);
            match(mysqlParser::FOREIGN);
            setState(425);
            match(mysqlParser::KEY);
            setState(427);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::ID

                || _la == mysqlParser::BQUOTED_STRING)
            {
                setState(426);
                index_name();
            }
            setState(429);
            index_column_list();
            setState(430);
            reference_definition();
            break;
        }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Column_definitionContext
//------------------------------------------------------------------

mysqlParser::Column_definitionContext::Column_definitionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Data_typeContext *mysqlParser::Column_definitionContext::data_type()
{
    return getRuleContext<mysqlParser::Data_typeContext>(0);
}

mysqlParser::Column_optionsContext *mysqlParser::Column_definitionContext::column_options()
{
    return getRuleContext<mysqlParser::Column_optionsContext>(0);
}

mysqlParser::Reference_definitionContext *mysqlParser::Column_definitionContext::
    reference_definition()
{
    return getRuleContext<mysqlParser::Reference_definitionContext>(0);
}

mysqlParser::Generated_column_optionsContext *mysqlParser::Column_definitionContext::
    generated_column_options()
{
    return getRuleContext<mysqlParser::Generated_column_optionsContext>(0);
}

size_t mysqlParser::Column_definitionContext::getRuleIndex() const
{
    return mysqlParser::RuleColumn_definition;
}

void mysqlParser::Column_definitionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterColumn_definition(this);
}

void mysqlParser::Column_definitionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitColumn_definition(this);
}

antlrcpp::Any mysqlParser::Column_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitColumn_definition(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Column_definitionContext *mysqlParser::column_definition()
{
    Column_definitionContext *_localctx
        = _tracker.createInstance<Column_definitionContext>(_ctx, getState());
    enterRule(_localctx, 16, mysqlParser::RuleColumn_definition);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(442);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx))
        {
        case 1:
        {
            enterOuterAlt(_localctx, 1);
            setState(434);
            data_type();
            setState(435);
            column_options();
            setState(437);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::REFERENCES)
            {
                setState(436);
                reference_definition();
            }
            break;
        }

        case 2:
        {
            enterOuterAlt(_localctx, 2);
            setState(439);
            data_type();
            setState(440);
            generated_column_options();
            break;
        }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Column_optionsContext
//------------------------------------------------------------------

mysqlParser::Column_optionsContext::Column_optionsContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Column_optionsContext::NOT()
{
    return getToken(mysqlParser::NOT, 0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::NULL()
{
    return getToken(mysqlParser::NULL, 0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

mysqlParser::Default_valueContext *mysqlParser::Column_optionsContext::default_value()
{
    return getRuleContext<mysqlParser::Default_valueContext>(0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::AUTO_INCREMENT()
{
    return getToken(mysqlParser::AUTO_INCREMENT, 0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::UNIQUE()
{
    return getToken(mysqlParser::UNIQUE, 0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::KEY()
{
    return getToken(mysqlParser::KEY, 0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::COMMENT()
{
    return getToken(mysqlParser::COMMENT, 0);
}

mysqlParser::CommentContext *mysqlParser::Column_optionsContext::comment()
{
    return getRuleContext<mysqlParser::CommentContext>(0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::COLUMN_FORMAT()
{
    return getToken(mysqlParser::COLUMN_FORMAT, 0);
}

mysqlParser::Column_formatContext *mysqlParser::Column_optionsContext::column_format()
{
    return getRuleContext<mysqlParser::Column_formatContext>(0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::STORAGE()
{
    return getToken(mysqlParser::STORAGE, 0);
}

mysqlParser::Column_storageContext *mysqlParser::Column_optionsContext::column_storage()
{
    return getRuleContext<mysqlParser::Column_storageContext>(0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::ON()
{
    return getToken(mysqlParser::ON, 0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::UPDATE()
{
    return getToken(mysqlParser::UPDATE, 0);
}

mysqlParser::On_update_setContext *mysqlParser::Column_optionsContext::on_update_set()
{
    return getRuleContext<mysqlParser::On_update_setContext>(0);
}

tree::TerminalNode *mysqlParser::Column_optionsContext::PRIMARY()
{
    return getToken(mysqlParser::PRIMARY, 0);
}

size_t mysqlParser::Column_optionsContext::getRuleIndex() const
{
    return mysqlParser::RuleColumn_options;
}

void mysqlParser::Column_optionsContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterColumn_options(this);
}

void mysqlParser::Column_optionsContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitColumn_options(this);
}

antlrcpp::Any mysqlParser::Column_optionsContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitColumn_options(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Column_optionsContext *mysqlParser::column_options()
{
    Column_optionsContext *_localctx
        = _tracker.createInstance<Column_optionsContext>(_ctx, getState());
    enterRule(_localctx, 18, mysqlParser::RuleColumn_options);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(447);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::NOT:
        {
            setState(444);
            match(mysqlParser::NOT);
            setState(445);
            match(mysqlParser::NULL);
            break;
        }

        case mysqlParser::NULL:
        {
            setState(446);
            match(mysqlParser::NULL);
            break;
        }

        case mysqlParser::AFTER:
        case mysqlParser::AUTO_INCREMENT:
        case mysqlParser::COLUMN_FORMAT:
        case mysqlParser::COMMENT:
        case mysqlParser::DEFAULT:
        case mysqlParser::FIRST:
        case mysqlParser::KEY:
        case mysqlParser::ON:
        case mysqlParser::PARTITION:
        case mysqlParser::PRIMARY:
        case mysqlParser::REFERENCES:
        case mysqlParser::STORAGE:
        case mysqlParser::UNIQUE:
        case mysqlParser::RPAREN:
        case mysqlParser::COMMA:
        case mysqlParser::SEMI:
        {
            break;
        }

        default:
            throw NoViableAltException(this);
        }
        setState(451);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::DEFAULT)
        {
            setState(449);
            match(mysqlParser::DEFAULT);
            setState(450);
            default_value();
        }
        setState(454);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::AUTO_INCREMENT)
        {
            setState(453);
            match(mysqlParser::AUTO_INCREMENT);
        }
        setState(464);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::UNIQUE:
        {
            setState(456);
            match(mysqlParser::UNIQUE);
            setState(458);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::KEY)
            {
                setState(457);
                match(mysqlParser::KEY);
            }
            break;
        }

        case mysqlParser::KEY:
        case mysqlParser::PRIMARY:
        {
            setState(461);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::PRIMARY)
            {
                setState(460);
                match(mysqlParser::PRIMARY);
            }
            setState(463);
            match(mysqlParser::KEY);
            break;
        }

        case mysqlParser::AFTER:
        case mysqlParser::COLUMN_FORMAT:
        case mysqlParser::COMMENT:
        case mysqlParser::FIRST:
        case mysqlParser::ON:
        case mysqlParser::PARTITION:
        case mysqlParser::REFERENCES:
        case mysqlParser::STORAGE:
        case mysqlParser::RPAREN:
        case mysqlParser::COMMA:
        case mysqlParser::SEMI:
        {
            break;
        }

        default:
            throw NoViableAltException(this);
        }
        setState(468);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::COMMENT)
        {
            setState(466);
            match(mysqlParser::COMMENT);
            setState(467);
            comment();
        }
        setState(472);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::COLUMN_FORMAT)
        {
            setState(470);
            match(mysqlParser::COLUMN_FORMAT);
            setState(471);
            column_format();
        }
        setState(476);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::STORAGE)
        {
            setState(474);
            match(mysqlParser::STORAGE);
            setState(475);
            column_storage();
        }
        setState(481);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::ON)
        {
            setState(478);
            match(mysqlParser::ON);
            setState(479);
            match(mysqlParser::UPDATE);
            setState(480);
            on_update_set();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Generated_column_optionsContext
//------------------------------------------------------------------

mysqlParser::Generated_column_optionsContext::Generated_column_optionsContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::AS()
{
    return getToken(mysqlParser::AS, 0);
}

mysqlParser::As_expressionContext *mysqlParser::Generated_column_optionsContext::as_expression()
{
    return getRuleContext<mysqlParser::As_expressionContext>(0);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::GENERATED()
{
    return getToken(mysqlParser::GENERATED, 0);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::ALWAYS()
{
    return getToken(mysqlParser::ALWAYS, 0);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::UNIQUE()
{
    return getToken(mysqlParser::UNIQUE, 0);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::COMMENT()
{
    return getToken(mysqlParser::COMMENT, 0);
}

mysqlParser::CommentContext *mysqlParser::Generated_column_optionsContext::comment()
{
    return getRuleContext<mysqlParser::CommentContext>(0);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::NOT()
{
    return getToken(mysqlParser::NOT, 0);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::NULL()
{
    return getToken(mysqlParser::NULL, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Generated_column_optionsContext::KEY()
{
    return getTokens(mysqlParser::KEY);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::KEY(size_t i)
{
    return getToken(mysqlParser::KEY, i);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::VIRTUAL()
{
    return getToken(mysqlParser::VIRTUAL, 0);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::STORED()
{
    return getToken(mysqlParser::STORED, 0);
}

tree::TerminalNode *mysqlParser::Generated_column_optionsContext::PRIMARY()
{
    return getToken(mysqlParser::PRIMARY, 0);
}

size_t mysqlParser::Generated_column_optionsContext::getRuleIndex() const
{
    return mysqlParser::RuleGenerated_column_options;
}

void mysqlParser::Generated_column_optionsContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterGenerated_column_options(this);
}

void mysqlParser::Generated_column_optionsContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitGenerated_column_options(this);
}

antlrcpp::Any mysqlParser::Generated_column_optionsContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitGenerated_column_options(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Generated_column_optionsContext *mysqlParser::generated_column_options()
{
    Generated_column_optionsContext *_localctx
        = _tracker.createInstance<Generated_column_optionsContext>(_ctx, getState());
    enterRule(_localctx, 20, mysqlParser::RuleGenerated_column_options);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(485);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::GENERATED)
        {
            setState(483);
            match(mysqlParser::GENERATED);
            setState(484);
            match(mysqlParser::ALWAYS);
        }
        setState(487);
        match(mysqlParser::AS);
        setState(488);
        as_expression();
        setState(490);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::STORED || _la == mysqlParser::VIRTUAL)
        {
            setState(489);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::STORED || _la == mysqlParser::VIRTUAL))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
        }
        setState(496);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::UNIQUE)
        {
            setState(492);
            match(mysqlParser::UNIQUE);
            setState(494);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx))
            {
            case 1:
            {
                setState(493);
                match(mysqlParser::KEY);
                break;
            }
            }
        }
        setState(500);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::COMMENT)
        {
            setState(498);
            match(mysqlParser::COMMENT);
            setState(499);
            comment();
        }
        setState(505);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::NOT:
        {
            setState(502);
            match(mysqlParser::NOT);
            setState(503);
            match(mysqlParser::NULL);
            break;
        }

        case mysqlParser::NULL:
        {
            setState(504);
            match(mysqlParser::NULL);
            break;
        }

        case mysqlParser::AFTER:
        case mysqlParser::FIRST:
        case mysqlParser::KEY:
        case mysqlParser::PARTITION:
        case mysqlParser::PRIMARY:
        case mysqlParser::RPAREN:
        case mysqlParser::COMMA:
        case mysqlParser::SEMI:
        {
            break;
        }

        default:
            throw NoViableAltException(this);
        }
        setState(511);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::KEY || _la == mysqlParser::PRIMARY)
        {
            setState(508);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::PRIMARY)
            {
                setState(507);
                match(mysqlParser::PRIMARY);
            }
            setState(510);
            match(mysqlParser::KEY);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Data_typeContext
//------------------------------------------------------------------

mysqlParser::Data_typeContext::Data_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_typeContext *mysqlParser::Data_typeContext::integer_type()
{
    return getRuleContext<mysqlParser::Integer_typeContext>(0);
}

tree::TerminalNode *mysqlParser::Data_typeContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

mysqlParser::LengthContext *mysqlParser::Data_typeContext::length()
{
    return getRuleContext<mysqlParser::LengthContext>(0);
}

tree::TerminalNode *mysqlParser::Data_typeContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

tree::TerminalNode *mysqlParser::Data_typeContext::UNSIGNED()
{
    return getToken(mysqlParser::UNSIGNED, 0);
}

tree::TerminalNode *mysqlParser::Data_typeContext::ZEROFILL()
{
    return getToken(mysqlParser::ZEROFILL, 0);
}

mysqlParser::Real_typeContext *mysqlParser::Data_typeContext::real_type()
{
    return getRuleContext<mysqlParser::Real_typeContext>(0);
}

tree::TerminalNode *mysqlParser::Data_typeContext::COMMA()
{
    return getToken(mysqlParser::COMMA, 0);
}

mysqlParser::DecimalsContext *mysqlParser::Data_typeContext::decimals()
{
    return getRuleContext<mysqlParser::DecimalsContext>(0);
}

mysqlParser::Datetime_typeContext *mysqlParser::Data_typeContext::datetime_type()
{
    return getRuleContext<mysqlParser::Datetime_typeContext>(0);
}

mysqlParser::FspContext *mysqlParser::Data_typeContext::fsp()
{
    return getRuleContext<mysqlParser::FspContext>(0);
}

mysqlParser::Char_typeContext *mysqlParser::Data_typeContext::char_type()
{
    return getRuleContext<mysqlParser::Char_typeContext>(0);
}

tree::TerminalNode *mysqlParser::Data_typeContext::BINARY()
{
    return getToken(mysqlParser::BINARY, 0);
}

mysqlParser::CharsetContext *mysqlParser::Data_typeContext::charset()
{
    return getRuleContext<mysqlParser::CharsetContext>(0);
}

mysqlParser::CollationContext *mysqlParser::Data_typeContext::collation()
{
    return getRuleContext<mysqlParser::CollationContext>(0);
}

mysqlParser::Binary_typeContext *mysqlParser::Data_typeContext::binary_type()
{
    return getRuleContext<mysqlParser::Binary_typeContext>(0);
}

mysqlParser::Blob_typeContext *mysqlParser::Data_typeContext::blob_type()
{
    return getRuleContext<mysqlParser::Blob_typeContext>(0);
}

mysqlParser::Text_typeContext *mysqlParser::Data_typeContext::text_type()
{
    return getRuleContext<mysqlParser::Text_typeContext>(0);
}

mysqlParser::Enum_typeContext *mysqlParser::Data_typeContext::enum_type()
{
    return getRuleContext<mysqlParser::Enum_typeContext>(0);
}

mysqlParser::Enum_value_listContext *mysqlParser::Data_typeContext::enum_value_list()
{
    return getRuleContext<mysqlParser::Enum_value_listContext>(0);
}

mysqlParser::Spatial_typeContext *mysqlParser::Data_typeContext::spatial_type()
{
    return getRuleContext<mysqlParser::Spatial_typeContext>(0);
}

tree::TerminalNode *mysqlParser::Data_typeContext::JSON()
{
    return getToken(mysqlParser::JSON, 0);
}

size_t mysqlParser::Data_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleData_type;
}

void mysqlParser::Data_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterData_type(this);
}

void mysqlParser::Data_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitData_type(this);
}

antlrcpp::Any mysqlParser::Data_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitData_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Data_typeContext *mysqlParser::data_type()
{
    Data_typeContext *_localctx = _tracker.createInstance<Data_typeContext>(_ctx, getState());
    enterRule(_localctx, 22, mysqlParser::RuleData_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(600);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::BIGINT:
        case mysqlParser::INT:
        case mysqlParser::INTEGER:
        case mysqlParser::MEDIUMINT:
        case mysqlParser::SMALLINT:
        case mysqlParser::TINYINT:
        {
            enterOuterAlt(_localctx, 1);
            setState(513);
            integer_type();
            setState(518);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LPAREN)
            {
                setState(514);
                match(mysqlParser::LPAREN);
                setState(515);
                length();
                setState(516);
                match(mysqlParser::RPAREN);
            }
            setState(521);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::UNSIGNED)
            {
                setState(520);
                match(mysqlParser::UNSIGNED);
            }
            setState(524);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::ZEROFILL)
            {
                setState(523);
                match(mysqlParser::ZEROFILL);
            }
            break;
        }

        case mysqlParser::DECIMAL:
        case mysqlParser::DOUBLE:
        case mysqlParser::FLOAT:
        case mysqlParser::NUMERIC:
        case mysqlParser::REAL:
        {
            enterOuterAlt(_localctx, 2);
            setState(526);
            real_type();
            setState(535);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LPAREN)
            {
                setState(527);
                match(mysqlParser::LPAREN);
                setState(528);
                length();
                setState(531);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == mysqlParser::COMMA)
                {
                    setState(529);
                    match(mysqlParser::COMMA);
                    setState(530);
                    decimals();
                }
                setState(533);
                match(mysqlParser::RPAREN);
            }
            setState(538);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::UNSIGNED)
            {
                setState(537);
                match(mysqlParser::UNSIGNED);
            }
            setState(541);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::ZEROFILL)
            {
                setState(540);
                match(mysqlParser::ZEROFILL);
            }
            break;
        }

        case mysqlParser::DATE:
        case mysqlParser::DATETIME:
        case mysqlParser::TIME:
        case mysqlParser::TIMESTAMP:
        case mysqlParser::YEAR:
        {
            enterOuterAlt(_localctx, 3);
            setState(543);
            datetime_type();
            setState(548);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LPAREN)
            {
                setState(544);
                match(mysqlParser::LPAREN);
                setState(545);
                fsp();
                setState(546);
                match(mysqlParser::RPAREN);
            }
            break;
        }

        case mysqlParser::CHAR:
        case mysqlParser::VARCHAR:
        {
            enterOuterAlt(_localctx, 4);
            setState(550);
            char_type();
            setState(555);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LPAREN)
            {
                setState(551);
                match(mysqlParser::LPAREN);
                setState(552);
                length();
                setState(553);
                match(mysqlParser::RPAREN);
            }
            setState(558);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::BINARY)
            {
                setState(557);
                match(mysqlParser::BINARY);
            }
            setState(561);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::CHARACTER

                || _la == mysqlParser::CHARSET)
            {
                setState(560);
                charset();
            }
            setState(564);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLLATE)
            {
                setState(563);
                collation();
            }
            break;
        }

        case mysqlParser::BINARY:
        case mysqlParser::BIT:
        case mysqlParser::VARBINARY:
        {
            enterOuterAlt(_localctx, 5);
            setState(566);
            binary_type();
            setState(571);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LPAREN)
            {
                setState(567);
                match(mysqlParser::LPAREN);
                setState(568);
                length();
                setState(569);
                match(mysqlParser::RPAREN);
            }
            break;
        }

        case mysqlParser::BLOB:
        case mysqlParser::LONGBLOB:
        case mysqlParser::MEDIUMBLOB:
        case mysqlParser::TINYBLOB:
        {
            enterOuterAlt(_localctx, 6);
            setState(573);
            blob_type();
            break;
        }

        case mysqlParser::LONGTEXT:
        case mysqlParser::MEDIUMTEXT:
        case mysqlParser::TEXT:
        case mysqlParser::TINYTEXT:
        {
            enterOuterAlt(_localctx, 7);
            setState(574);
            text_type();
            setState(579);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LPAREN)
            {
                setState(575);
                match(mysqlParser::LPAREN);
                setState(576);
                length();
                setState(577);
                match(mysqlParser::RPAREN);
            }
            setState(582);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::BINARY)
            {
                setState(581);
                match(mysqlParser::BINARY);
            }
            setState(585);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::CHARACTER

                || _la == mysqlParser::CHARSET)
            {
                setState(584);
                charset();
            }
            setState(588);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLLATE)
            {
                setState(587);
                collation();
            }
            break;
        }

        case mysqlParser::ENUM:
        case mysqlParser::SET:
        {
            enterOuterAlt(_localctx, 8);
            setState(590);
            enum_type();
            setState(591);
            enum_value_list();
            setState(593);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::CHARACTER

                || _la == mysqlParser::CHARSET)
            {
                setState(592);
                charset();
            }
            setState(596);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLLATE)
            {
                setState(595);
                collation();
            }
            break;
        }

        case mysqlParser::GEOMETRY:
        case mysqlParser::GEOMETRYCOLLECTION:
        case mysqlParser::LINESTRING:
        case mysqlParser::MULTILINESTRING:
        case mysqlParser::MULTIPOINT:
        case mysqlParser::MULTIPOLYGON:
        case mysqlParser::POINT:
        case mysqlParser::POLYGON:
        {
            enterOuterAlt(_localctx, 9);
            setState(598);
            spatial_type();
            break;
        }

        case mysqlParser::JSON:
        {
            enterOuterAlt(_localctx, 10);
            setState(599);
            match(mysqlParser::JSON);
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Table_optionContext
//------------------------------------------------------------------

mysqlParser::Table_optionContext::Table_optionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Table_optionContext::ENGINE()
{
    return getToken(mysqlParser::ENGINE, 0);
}

mysqlParser::Engine_nameContext *mysqlParser::Table_optionContext::engine_name()
{
    return getRuleContext<mysqlParser::Engine_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::EQUAL()
{
    return getToken(mysqlParser::EQUAL, 0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::AUTO_INCREMENT()
{
    return getToken(mysqlParser::AUTO_INCREMENT, 0);
}

mysqlParser::Auto_incrementContext *mysqlParser::Table_optionContext::auto_increment()
{
    return getRuleContext<mysqlParser::Auto_incrementContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::AVG_ROW_LENGTH()
{
    return getToken(mysqlParser::AVG_ROW_LENGTH, 0);
}

mysqlParser::Avg_row_lengthContext *mysqlParser::Table_optionContext::avg_row_length()
{
    return getRuleContext<mysqlParser::Avg_row_lengthContext>(0);
}

mysqlParser::CharsetContext *mysqlParser::Table_optionContext::charset()
{
    return getRuleContext<mysqlParser::CharsetContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::CHECKSUM()
{
    return getToken(mysqlParser::CHECKSUM, 0);
}

mysqlParser::ChecksumContext *mysqlParser::Table_optionContext::checksum()
{
    return getRuleContext<mysqlParser::ChecksumContext>(0);
}

mysqlParser::CollationContext *mysqlParser::Table_optionContext::collation()
{
    return getRuleContext<mysqlParser::CollationContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::COMMENT()
{
    return getToken(mysqlParser::COMMENT, 0);
}

mysqlParser::CommentContext *mysqlParser::Table_optionContext::comment()
{
    return getRuleContext<mysqlParser::CommentContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::COMPRESSION()
{
    return getToken(mysqlParser::COMPRESSION, 0);
}

mysqlParser::CompressionContext *mysqlParser::Table_optionContext::compression()
{
    return getRuleContext<mysqlParser::CompressionContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::CONNECTION()
{
    return getToken(mysqlParser::CONNECTION, 0);
}

mysqlParser::ConnectionContext *mysqlParser::Table_optionContext::connection()
{
    return getRuleContext<mysqlParser::ConnectionContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::DATA()
{
    return getToken(mysqlParser::DATA, 0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::DIRECTORY()
{
    return getToken(mysqlParser::DIRECTORY, 0);
}

mysqlParser::Data_directoryContext *mysqlParser::Table_optionContext::data_directory()
{
    return getRuleContext<mysqlParser::Data_directoryContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::DELAY_KEY_WRITE()
{
    return getToken(mysqlParser::DELAY_KEY_WRITE, 0);
}

mysqlParser::Delay_key_writeContext *mysqlParser::Table_optionContext::delay_key_write()
{
    return getRuleContext<mysqlParser::Delay_key_writeContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::ENCRYPTION()
{
    return getToken(mysqlParser::ENCRYPTION, 0);
}

mysqlParser::EncryptionContext *mysqlParser::Table_optionContext::encryption()
{
    return getRuleContext<mysqlParser::EncryptionContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::INDEX()
{
    return getToken(mysqlParser::INDEX, 0);
}

mysqlParser::Index_directoryContext *mysqlParser::Table_optionContext::index_directory()
{
    return getRuleContext<mysqlParser::Index_directoryContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::INSERT_METHOD()
{
    return getToken(mysqlParser::INSERT_METHOD, 0);
}

mysqlParser::Insert_methodContext *mysqlParser::Table_optionContext::insert_method()
{
    return getRuleContext<mysqlParser::Insert_methodContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::KEY_BLOCK_SIZE()
{
    return getToken(mysqlParser::KEY_BLOCK_SIZE, 0);
}

mysqlParser::Key_block_sizeContext *mysqlParser::Table_optionContext::key_block_size()
{
    return getRuleContext<mysqlParser::Key_block_sizeContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::MAX_ROWS()
{
    return getToken(mysqlParser::MAX_ROWS, 0);
}

mysqlParser::Max_number_of_rowsContext *mysqlParser::Table_optionContext::max_number_of_rows()
{
    return getRuleContext<mysqlParser::Max_number_of_rowsContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::MIN_ROWS()
{
    return getToken(mysqlParser::MIN_ROWS, 0);
}

mysqlParser::Min_number_of_rowsContext *mysqlParser::Table_optionContext::min_number_of_rows()
{
    return getRuleContext<mysqlParser::Min_number_of_rowsContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::PACK_KEYS()
{
    return getToken(mysqlParser::PACK_KEYS, 0);
}

mysqlParser::Pack_keysContext *mysqlParser::Table_optionContext::pack_keys()
{
    return getRuleContext<mysqlParser::Pack_keysContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::PASSWORD()
{
    return getToken(mysqlParser::PASSWORD, 0);
}

mysqlParser::PasswordContext *mysqlParser::Table_optionContext::password()
{
    return getRuleContext<mysqlParser::PasswordContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::ROW_FORMAT()
{
    return getToken(mysqlParser::ROW_FORMAT, 0);
}

mysqlParser::Row_formatContext *mysqlParser::Table_optionContext::row_format()
{
    return getRuleContext<mysqlParser::Row_formatContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::STATS_AUTO_RECALC()
{
    return getToken(mysqlParser::STATS_AUTO_RECALC, 0);
}

mysqlParser::Stats_auto_recalcContext *mysqlParser::Table_optionContext::stats_auto_recalc()
{
    return getRuleContext<mysqlParser::Stats_auto_recalcContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::STATS_PERSISTENT()
{
    return getToken(mysqlParser::STATS_PERSISTENT, 0);
}

mysqlParser::Stats_persistentContext *mysqlParser::Table_optionContext::stats_persistent()
{
    return getRuleContext<mysqlParser::Stats_persistentContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::STATS_SAMPLE_PAGES()
{
    return getToken(mysqlParser::STATS_SAMPLE_PAGES, 0);
}

mysqlParser::Stats_sample_pagesContext *mysqlParser::Table_optionContext::stats_sample_pages()
{
    return getRuleContext<mysqlParser::Stats_sample_pagesContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::TABLESPACE()
{
    return getToken(mysqlParser::TABLESPACE, 0);
}

mysqlParser::Tablespace_nameContext *mysqlParser::Table_optionContext::tablespace_name()
{
    return getRuleContext<mysqlParser::Tablespace_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Table_optionContext::UNION()
{
    return getToken(mysqlParser::UNION, 0);
}

mysqlParser::Table_union_listContext *mysqlParser::Table_optionContext::table_union_list()
{
    return getRuleContext<mysqlParser::Table_union_listContext>(0);
}

size_t mysqlParser::Table_optionContext::getRuleIndex() const
{
    return mysqlParser::RuleTable_option;
}

void mysqlParser::Table_optionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterTable_option(this);
}

void mysqlParser::Table_optionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitTable_option(this);
}

antlrcpp::Any mysqlParser::Table_optionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitTable_option(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Table_optionContext *mysqlParser::table_option()
{
    Table_optionContext *_localctx = _tracker.createInstance<Table_optionContext>(_ctx, getState());
    enterRule(_localctx, 24, mysqlParser::RuleTable_option);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(724);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx))
        {
        case 1:
        {
            enterOuterAlt(_localctx, 1);
            setState(602);
            match(mysqlParser::ENGINE);
            setState(604);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(603);
                match(mysqlParser::EQUAL);
            }
            setState(606);
            engine_name();
            break;
        }

        case 2:
        {
            enterOuterAlt(_localctx, 2);
            setState(607);
            match(mysqlParser::AUTO_INCREMENT);
            setState(609);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(608);
                match(mysqlParser::EQUAL);
            }
            setState(611);
            auto_increment();
            break;
        }

        case 3:
        {
            enterOuterAlt(_localctx, 3);
            setState(612);
            match(mysqlParser::AVG_ROW_LENGTH);
            setState(614);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(613);
                match(mysqlParser::EQUAL);
            }
            setState(616);
            avg_row_length();
            break;
        }

        case 4:
        {
            enterOuterAlt(_localctx, 4);
            setState(618);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::DEFAULT)
            {
                setState(617);
                match(mysqlParser::DEFAULT);
            }
            setState(620);
            charset();
            break;
        }

        case 5:
        {
            enterOuterAlt(_localctx, 5);
            setState(621);
            match(mysqlParser::CHECKSUM);
            setState(623);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(622);
                match(mysqlParser::EQUAL);
            }
            setState(625);
            checksum();
            break;
        }

        case 6:
        {
            enterOuterAlt(_localctx, 6);
            setState(627);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::DEFAULT)
            {
                setState(626);
                match(mysqlParser::DEFAULT);
            }
            setState(629);
            collation();
            break;
        }

        case 7:
        {
            enterOuterAlt(_localctx, 7);
            setState(630);
            match(mysqlParser::COMMENT);
            setState(632);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(631);
                match(mysqlParser::EQUAL);
            }
            setState(634);
            comment();
            break;
        }

        case 8:
        {
            enterOuterAlt(_localctx, 8);
            setState(635);
            match(mysqlParser::COMPRESSION);
            setState(637);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(636);
                match(mysqlParser::EQUAL);
            }
            setState(639);
            compression();
            break;
        }

        case 9:
        {
            enterOuterAlt(_localctx, 9);
            setState(640);
            match(mysqlParser::CONNECTION);
            setState(642);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(641);
                match(mysqlParser::EQUAL);
            }
            setState(644);
            connection();
            break;
        }

        case 10:
        {
            enterOuterAlt(_localctx, 10);
            setState(645);
            match(mysqlParser::DATA);
            setState(646);
            match(mysqlParser::DIRECTORY);
            setState(648);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(647);
                match(mysqlParser::EQUAL);
            }
            setState(650);
            data_directory();
            break;
        }

        case 11:
        {
            enterOuterAlt(_localctx, 11);
            setState(651);
            match(mysqlParser::DELAY_KEY_WRITE);
            setState(653);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(652);
                match(mysqlParser::EQUAL);
            }
            setState(655);
            delay_key_write();
            break;
        }

        case 12:
        {
            enterOuterAlt(_localctx, 12);
            setState(656);
            match(mysqlParser::ENCRYPTION);
            setState(658);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(657);
                match(mysqlParser::EQUAL);
            }
            setState(660);
            encryption();
            break;
        }

        case 13:
        {
            enterOuterAlt(_localctx, 13);
            setState(661);
            match(mysqlParser::INDEX);
            setState(662);
            match(mysqlParser::DIRECTORY);
            setState(664);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(663);
                match(mysqlParser::EQUAL);
            }
            setState(666);
            index_directory();
            break;
        }

        case 14:
        {
            enterOuterAlt(_localctx, 14);
            setState(667);
            match(mysqlParser::INSERT_METHOD);
            setState(669);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(668);
                match(mysqlParser::EQUAL);
            }
            setState(671);
            insert_method();
            break;
        }

        case 15:
        {
            enterOuterAlt(_localctx, 15);
            setState(672);
            match(mysqlParser::KEY_BLOCK_SIZE);
            setState(674);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(673);
                match(mysqlParser::EQUAL);
            }
            setState(676);
            key_block_size();
            break;
        }

        case 16:
        {
            enterOuterAlt(_localctx, 16);
            setState(677);
            match(mysqlParser::MAX_ROWS);
            setState(679);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(678);
                match(mysqlParser::EQUAL);
            }
            setState(681);
            max_number_of_rows();
            break;
        }

        case 17:
        {
            enterOuterAlt(_localctx, 17);
            setState(682);
            match(mysqlParser::MIN_ROWS);
            setState(684);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(683);
                match(mysqlParser::EQUAL);
            }
            setState(686);
            min_number_of_rows();
            break;
        }

        case 18:
        {
            enterOuterAlt(_localctx, 18);
            setState(687);
            match(mysqlParser::PACK_KEYS);
            setState(689);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(688);
                match(mysqlParser::EQUAL);
            }
            setState(691);
            pack_keys();
            break;
        }

        case 19:
        {
            enterOuterAlt(_localctx, 19);
            setState(692);
            match(mysqlParser::PASSWORD);
            setState(694);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(693);
                match(mysqlParser::EQUAL);
            }
            setState(696);
            password();
            break;
        }

        case 20:
        {
            enterOuterAlt(_localctx, 20);
            setState(697);
            match(mysqlParser::ROW_FORMAT);
            setState(699);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(698);
                match(mysqlParser::EQUAL);
            }
            setState(701);
            row_format();
            break;
        }

        case 21:
        {
            enterOuterAlt(_localctx, 21);
            setState(702);
            match(mysqlParser::STATS_AUTO_RECALC);
            setState(704);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(703);
                match(mysqlParser::EQUAL);
            }
            setState(706);
            stats_auto_recalc();
            break;
        }

        case 22:
        {
            enterOuterAlt(_localctx, 22);
            setState(707);
            match(mysqlParser::STATS_PERSISTENT);
            setState(709);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(708);
                match(mysqlParser::EQUAL);
            }
            setState(711);
            stats_persistent();
            break;
        }

        case 23:
        {
            enterOuterAlt(_localctx, 23);
            setState(712);
            match(mysqlParser::STATS_SAMPLE_PAGES);
            setState(714);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(713);
                match(mysqlParser::EQUAL);
            }
            setState(716);
            stats_sample_pages();
            break;
        }

        case 24:
        {
            enterOuterAlt(_localctx, 24);
            setState(717);
            match(mysqlParser::TABLESPACE);
            setState(718);
            tablespace_name();
            break;
        }

        case 25:
        {
            enterOuterAlt(_localctx, 25);
            setState(719);
            match(mysqlParser::UNION);
            setState(721);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(720);
                match(mysqlParser::EQUAL);
            }
            setState(723);
            table_union_list();
            break;
        }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_specificationContext
//------------------------------------------------------------------

mysqlParser::Partition_specificationContext::Partition_specificationContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Partition_specificationContext::PARTITION()
{
    return getToken(mysqlParser::PARTITION, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Partition_specificationContext::BY()
{
    return getTokens(mysqlParser::BY);
}

tree::TerminalNode *mysqlParser::Partition_specificationContext::BY(size_t i)
{
    return getToken(mysqlParser::BY, i);
}

mysqlParser::Partition_byContext *mysqlParser::Partition_specificationContext::partition_by()
{
    return getRuleContext<mysqlParser::Partition_byContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_specificationContext::PARTITIONS()
{
    return getToken(mysqlParser::PARTITIONS, 0);
}

mysqlParser::Partition_countContext *mysqlParser::Partition_specificationContext::partition_count()
{
    return getRuleContext<mysqlParser::Partition_countContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_specificationContext::SUBPARTITION()
{
    return getToken(mysqlParser::SUBPARTITION, 0);
}

mysqlParser::Subpartition_byContext *mysqlParser::Partition_specificationContext::subpartition_by()
{
    return getRuleContext<mysqlParser::Subpartition_byContext>(0);
}

mysqlParser::Partition_definition_listContext *mysqlParser::Partition_specificationContext::
    partition_definition_list()
{
    return getRuleContext<mysqlParser::Partition_definition_listContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_specificationContext::SUBPARTITIONS()
{
    return getToken(mysqlParser::SUBPARTITIONS, 0);
}

mysqlParser::Subpartition_countContext *mysqlParser::Partition_specificationContext::
    subpartition_count()
{
    return getRuleContext<mysqlParser::Subpartition_countContext>(0);
}

size_t mysqlParser::Partition_specificationContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_specification;
}

void mysqlParser::Partition_specificationContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_specification(this);
}

void mysqlParser::Partition_specificationContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_specification(this);
}

antlrcpp::Any mysqlParser::Partition_specificationContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_specification(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_specificationContext *mysqlParser::partition_specification()
{
    Partition_specificationContext *_localctx
        = _tracker.createInstance<Partition_specificationContext>(_ctx, getState());
    enterRule(_localctx, 26, mysqlParser::RulePartition_specification);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(726);
        match(mysqlParser::PARTITION);
        setState(727);
        match(mysqlParser::BY);
        setState(728);
        partition_by();
        setState(731);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::PARTITIONS)
        {
            setState(729);
            match(mysqlParser::PARTITIONS);
            setState(730);
            partition_count();
        }
        setState(740);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::SUBPARTITION)
        {
            setState(733);
            match(mysqlParser::SUBPARTITION);
            setState(734);
            match(mysqlParser::BY);
            setState(735);
            subpartition_by();
            setState(738);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::SUBPARTITIONS)
            {
                setState(736);
                match(mysqlParser::SUBPARTITIONS);
                setState(737);
                subpartition_count();
            }
        }
        setState(743);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx))
        {
        case 1:
        {
            setState(742);
            partition_definition_list();
            break;
        }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_definition_listContext
//------------------------------------------------------------------

mysqlParser::Partition_definition_listContext::Partition_definition_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Partition_definition_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::Partition_definitionContext *> mysqlParser::
    Partition_definition_listContext::partition_definition()
{
    return getRuleContexts<mysqlParser::Partition_definitionContext>();
}

mysqlParser::Partition_definitionContext *mysqlParser::Partition_definition_listContext::
    partition_definition(size_t i)
{
    return getRuleContext<mysqlParser::Partition_definitionContext>(i);
}

tree::TerminalNode *mysqlParser::Partition_definition_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Partition_definition_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Partition_definition_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Partition_definition_listContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_definition_list;
}

void mysqlParser::Partition_definition_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_definition_list(this);
}

void mysqlParser::Partition_definition_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_definition_list(this);
}

antlrcpp::Any mysqlParser::Partition_definition_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_definition_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_definition_listContext *mysqlParser::partition_definition_list()
{
    Partition_definition_listContext *_localctx
        = _tracker.createInstance<Partition_definition_listContext>(_ctx, getState());
    enterRule(_localctx, 28, mysqlParser::RulePartition_definition_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(745);
        match(mysqlParser::LPAREN);
        setState(746);
        partition_definition();
        setState(751);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(747);
            match(mysqlParser::COMMA);
            setState(748);
            partition_definition();
            setState(753);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(754);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_byContext
//------------------------------------------------------------------

mysqlParser::Partition_byContext::Partition_byContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Partition_byContext::HASH()
{
    return getToken(mysqlParser::HASH, 0);
}

mysqlParser::Hash_expressionContext *mysqlParser::Partition_byContext::hash_expression()
{
    return getRuleContext<mysqlParser::Hash_expressionContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_byContext::LINEAR()
{
    return getToken(mysqlParser::LINEAR, 0);
}

tree::TerminalNode *mysqlParser::Partition_byContext::KEY()
{
    return getToken(mysqlParser::KEY, 0);
}

mysqlParser::Key_column_listContext *mysqlParser::Partition_byContext::key_column_list()
{
    return getRuleContext<mysqlParser::Key_column_listContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_byContext::ALGORITHM()
{
    return getToken(mysqlParser::ALGORITHM, 0);
}

tree::TerminalNode *mysqlParser::Partition_byContext::EQUAL()
{
    return getToken(mysqlParser::EQUAL, 0);
}

mysqlParser::Key_algorithmContext *mysqlParser::Partition_byContext::key_algorithm()
{
    return getRuleContext<mysqlParser::Key_algorithmContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_byContext::RANGE()
{
    return getToken(mysqlParser::RANGE, 0);
}

mysqlParser::Range_expressionContext *mysqlParser::Partition_byContext::range_expression()
{
    return getRuleContext<mysqlParser::Range_expressionContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_byContext::COLUMNS()
{
    return getToken(mysqlParser::COLUMNS, 0);
}

mysqlParser::Range_column_listContext *mysqlParser::Partition_byContext::range_column_list()
{
    return getRuleContext<mysqlParser::Range_column_listContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_byContext::LIST()
{
    return getToken(mysqlParser::LIST, 0);
}

mysqlParser::List_expressionContext *mysqlParser::Partition_byContext::list_expression()
{
    return getRuleContext<mysqlParser::List_expressionContext>(0);
}

mysqlParser::List_column_listContext *mysqlParser::Partition_byContext::list_column_list()
{
    return getRuleContext<mysqlParser::List_column_listContext>(0);
}

size_t mysqlParser::Partition_byContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_by;
}

void mysqlParser::Partition_byContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_by(this);
}

void mysqlParser::Partition_byContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_by(this);
}

antlrcpp::Any mysqlParser::Partition_byContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_by(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_byContext *mysqlParser::partition_by()
{
    Partition_byContext *_localctx = _tracker.createInstance<Partition_byContext>(_ctx, getState());
    enterRule(_localctx, 30, mysqlParser::RulePartition_by);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(783);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx))
        {
        case 1:
        {
            enterOuterAlt(_localctx, 1);
            setState(757);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LINEAR)
            {
                setState(756);
                match(mysqlParser::LINEAR);
            }
            setState(759);
            match(mysqlParser::HASH);
            setState(760);
            hash_expression();
            break;
        }

        case 2:
        {
            enterOuterAlt(_localctx, 2);
            setState(762);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LINEAR)
            {
                setState(761);
                match(mysqlParser::LINEAR);
            }
            setState(764);
            match(mysqlParser::KEY);
            setState(768);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::ALGORITHM)
            {
                setState(765);
                match(mysqlParser::ALGORITHM);
                setState(766);
                match(mysqlParser::EQUAL);
                setState(767);
                key_algorithm();
            }
            setState(770);
            key_column_list();
            break;
        }

        case 3:
        {
            enterOuterAlt(_localctx, 3);
            setState(771);
            match(mysqlParser::RANGE);
            setState(775);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::LPAREN:
            {
                setState(772);
                range_expression();
                break;
            }

            case mysqlParser::COLUMNS:
            {
                setState(773);
                match(mysqlParser::COLUMNS);
                setState(774);
                range_column_list();
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 4:
        {
            enterOuterAlt(_localctx, 4);
            setState(777);
            match(mysqlParser::LIST);
            setState(781);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::LPAREN:
            {
                setState(778);
                list_expression();
                break;
            }

            case mysqlParser::COLUMNS:
            {
                setState(779);
                match(mysqlParser::COLUMNS);
                setState(780);
                list_column_list();
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Subpartition_byContext
//------------------------------------------------------------------

mysqlParser::Subpartition_byContext::Subpartition_byContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Subpartition_byContext::HASH()
{
    return getToken(mysqlParser::HASH, 0);
}

mysqlParser::Hash_expressionContext *mysqlParser::Subpartition_byContext::hash_expression()
{
    return getRuleContext<mysqlParser::Hash_expressionContext>(0);
}

tree::TerminalNode *mysqlParser::Subpartition_byContext::LINEAR()
{
    return getToken(mysqlParser::LINEAR, 0);
}

tree::TerminalNode *mysqlParser::Subpartition_byContext::KEY()
{
    return getToken(mysqlParser::KEY, 0);
}

mysqlParser::Key_column_listContext *mysqlParser::Subpartition_byContext::key_column_list()
{
    return getRuleContext<mysqlParser::Key_column_listContext>(0);
}

tree::TerminalNode *mysqlParser::Subpartition_byContext::ALGORITHM()
{
    return getToken(mysqlParser::ALGORITHM, 0);
}

tree::TerminalNode *mysqlParser::Subpartition_byContext::EQUAL()
{
    return getToken(mysqlParser::EQUAL, 0);
}

mysqlParser::Key_algorithmContext *mysqlParser::Subpartition_byContext::key_algorithm()
{
    return getRuleContext<mysqlParser::Key_algorithmContext>(0);
}

size_t mysqlParser::Subpartition_byContext::getRuleIndex() const
{
    return mysqlParser::RuleSubpartition_by;
}

void mysqlParser::Subpartition_byContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterSubpartition_by(this);
}

void mysqlParser::Subpartition_byContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitSubpartition_by(this);
}

antlrcpp::Any mysqlParser::Subpartition_byContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitSubpartition_by(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Subpartition_byContext *mysqlParser::subpartition_by()
{
    Subpartition_byContext *_localctx
        = _tracker.createInstance<Subpartition_byContext>(_ctx, getState());
    enterRule(_localctx, 32, mysqlParser::RuleSubpartition_by);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(800);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx))
        {
        case 1:
        {
            enterOuterAlt(_localctx, 1);
            setState(786);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LINEAR)
            {
                setState(785);
                match(mysqlParser::LINEAR);
            }
            setState(788);
            match(mysqlParser::HASH);
            setState(789);
            hash_expression();
            break;
        }

        case 2:
        {
            enterOuterAlt(_localctx, 2);
            setState(791);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::LINEAR)
            {
                setState(790);
                match(mysqlParser::LINEAR);
            }
            setState(793);
            match(mysqlParser::KEY);
            setState(797);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::ALGORITHM)
            {
                setState(794);
                match(mysqlParser::ALGORITHM);
                setState(795);
                match(mysqlParser::EQUAL);
                setState(796);
                key_algorithm();
            }
            setState(799);
            key_column_list();
            break;
        }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_definitionContext
//------------------------------------------------------------------

mysqlParser::Partition_definitionContext::Partition_definitionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Partition_definitionContext::PARTITION()
{
    return getToken(mysqlParser::PARTITION, 0);
}

mysqlParser::Partition_nameContext *mysqlParser::Partition_definitionContext::partition_name()
{
    return getRuleContext<mysqlParser::Partition_nameContext>(0);
}

mysqlParser::Partition_optionsContext *mysqlParser::Partition_definitionContext::partition_options()
{
    return getRuleContext<mysqlParser::Partition_optionsContext>(0);
}

mysqlParser::Partition_valuesContext *mysqlParser::Partition_definitionContext::partition_values()
{
    return getRuleContext<mysqlParser::Partition_valuesContext>(0);
}

mysqlParser::Subpartition_definition_listContext *mysqlParser::Partition_definitionContext::
    subpartition_definition_list()
{
    return getRuleContext<mysqlParser::Subpartition_definition_listContext>(0);
}

size_t mysqlParser::Partition_definitionContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_definition;
}

void mysqlParser::Partition_definitionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_definition(this);
}

void mysqlParser::Partition_definitionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_definition(this);
}

antlrcpp::Any mysqlParser::Partition_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_definition(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_definitionContext *mysqlParser::partition_definition()
{
    Partition_definitionContext *_localctx
        = _tracker.createInstance<Partition_definitionContext>(_ctx, getState());
    enterRule(_localctx, 34, mysqlParser::RulePartition_definition);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(802);
        match(mysqlParser::PARTITION);
        setState(803);
        partition_name();
        setState(805);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::VALUES)
        {
            setState(804);
            partition_values();
        }
        setState(807);
        partition_options();
        setState(809);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::LPAREN)
        {
            setState(808);
            subpartition_definition_list();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Subpartition_definition_listContext
//------------------------------------------------------------------

mysqlParser::Subpartition_definition_listContext::Subpartition_definition_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Subpartition_definition_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::Subpartition_definitionContext *> mysqlParser::
    Subpartition_definition_listContext::subpartition_definition()
{
    return getRuleContexts<mysqlParser::Subpartition_definitionContext>();
}

mysqlParser::Subpartition_definitionContext *mysqlParser::Subpartition_definition_listContext::
    subpartition_definition(size_t i)
{
    return getRuleContext<mysqlParser::Subpartition_definitionContext>(i);
}

tree::TerminalNode *mysqlParser::Subpartition_definition_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Subpartition_definition_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Subpartition_definition_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Subpartition_definition_listContext::getRuleIndex() const
{
    return mysqlParser::RuleSubpartition_definition_list;
}

void mysqlParser::Subpartition_definition_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterSubpartition_definition_list(this);
}

void mysqlParser::Subpartition_definition_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitSubpartition_definition_list(this);
}

antlrcpp::Any mysqlParser::Subpartition_definition_listContext::accept(
    tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitSubpartition_definition_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Subpartition_definition_listContext *mysqlParser::subpartition_definition_list()
{
    Subpartition_definition_listContext *_localctx
        = _tracker.createInstance<Subpartition_definition_listContext>(_ctx, getState());
    enterRule(_localctx, 36, mysqlParser::RuleSubpartition_definition_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(811);
        match(mysqlParser::LPAREN);
        setState(812);
        subpartition_definition();
        setState(817);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(813);
            match(mysqlParser::COMMA);
            setState(814);
            subpartition_definition();
            setState(819);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(820);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_valuesContext
//------------------------------------------------------------------

mysqlParser::Partition_valuesContext::Partition_valuesContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Partition_valuesContext::VALUES()
{
    return getToken(mysqlParser::VALUES, 0);
}

tree::TerminalNode *mysqlParser::Partition_valuesContext::LESS()
{
    return getToken(mysqlParser::LESS, 0);
}

tree::TerminalNode *mysqlParser::Partition_valuesContext::THAN()
{
    return getToken(mysqlParser::THAN, 0);
}

tree::TerminalNode *mysqlParser::Partition_valuesContext::IN()
{
    return getToken(mysqlParser::IN, 0);
}

mysqlParser::In_value_listContext *mysqlParser::Partition_valuesContext::in_value_list()
{
    return getRuleContext<mysqlParser::In_value_listContext>(0);
}

mysqlParser::Less_than_expressionContext *mysqlParser::Partition_valuesContext::
    less_than_expression()
{
    return getRuleContext<mysqlParser::Less_than_expressionContext>(0);
}

mysqlParser::Less_than_value_listContext *mysqlParser::Partition_valuesContext::
    less_than_value_list()
{
    return getRuleContext<mysqlParser::Less_than_value_listContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_valuesContext::MAXVALUE()
{
    return getToken(mysqlParser::MAXVALUE, 0);
}

size_t mysqlParser::Partition_valuesContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_values;
}

void mysqlParser::Partition_valuesContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_values(this);
}

void mysqlParser::Partition_valuesContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_values(this);
}

antlrcpp::Any mysqlParser::Partition_valuesContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_values(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_valuesContext *mysqlParser::partition_values()
{
    Partition_valuesContext *_localctx
        = _tracker.createInstance<Partition_valuesContext>(_ctx, getState());
    enterRule(_localctx, 38, mysqlParser::RulePartition_values);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(822);
        match(mysqlParser::VALUES);
        setState(832);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::LESS:
        {
            setState(823);
            match(mysqlParser::LESS);
            setState(824);
            match(mysqlParser::THAN);
            setState(828);
            _errHandler->sync(this);
            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx))
            {
            case 1:
            {
                setState(825);
                less_than_expression();
                break;
            }

            case 2:
            {
                setState(826);
                less_than_value_list();
                break;
            }

            case 3:
            {
                setState(827);
                match(mysqlParser::MAXVALUE);
                break;
            }
            }
            break;
        }

        case mysqlParser::IN:
        {
            setState(830);
            match(mysqlParser::IN);
            setState(831);
            in_value_list();
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Subpartition_definitionContext
//------------------------------------------------------------------

mysqlParser::Subpartition_definitionContext::Subpartition_definitionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Subpartition_definitionContext::SUBPARTITION()
{
    return getToken(mysqlParser::SUBPARTITION, 0);
}

mysqlParser::Logical_nameContext *mysqlParser::Subpartition_definitionContext::logical_name()
{
    return getRuleContext<mysqlParser::Logical_nameContext>(0);
}

mysqlParser::Partition_optionsContext *mysqlParser::Subpartition_definitionContext::
    partition_options()
{
    return getRuleContext<mysqlParser::Partition_optionsContext>(0);
}

size_t mysqlParser::Subpartition_definitionContext::getRuleIndex() const
{
    return mysqlParser::RuleSubpartition_definition;
}

void mysqlParser::Subpartition_definitionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterSubpartition_definition(this);
}

void mysqlParser::Subpartition_definitionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitSubpartition_definition(this);
}

antlrcpp::Any mysqlParser::Subpartition_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitSubpartition_definition(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Subpartition_definitionContext *mysqlParser::subpartition_definition()
{
    Subpartition_definitionContext *_localctx
        = _tracker.createInstance<Subpartition_definitionContext>(_ctx, getState());
    enterRule(_localctx, 40, mysqlParser::RuleSubpartition_definition);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(834);
        match(mysqlParser::SUBPARTITION);
        setState(835);
        logical_name();
        setState(836);
        partition_options();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_optionsContext
//------------------------------------------------------------------

mysqlParser::Partition_optionsContext::Partition_optionsContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::ENGINE()
{
    return getToken(mysqlParser::ENGINE, 0);
}

mysqlParser::Engine_nameContext *mysqlParser::Partition_optionsContext::engine_name()
{
    return getRuleContext<mysqlParser::Engine_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::COMMENT()
{
    return getToken(mysqlParser::COMMENT, 0);
}

mysqlParser::CommentContext *mysqlParser::Partition_optionsContext::comment()
{
    return getRuleContext<mysqlParser::CommentContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::DATA()
{
    return getToken(mysqlParser::DATA, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Partition_optionsContext::DIRECTORY()
{
    return getTokens(mysqlParser::DIRECTORY);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::DIRECTORY(size_t i)
{
    return getToken(mysqlParser::DIRECTORY, i);
}

mysqlParser::Data_directoryContext *mysqlParser::Partition_optionsContext::data_directory()
{
    return getRuleContext<mysqlParser::Data_directoryContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::INDEX()
{
    return getToken(mysqlParser::INDEX, 0);
}

mysqlParser::Index_directoryContext *mysqlParser::Partition_optionsContext::index_directory()
{
    return getRuleContext<mysqlParser::Index_directoryContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::MAX_ROWS()
{
    return getToken(mysqlParser::MAX_ROWS, 0);
}

mysqlParser::Max_number_of_rowsContext *mysqlParser::Partition_optionsContext::max_number_of_rows()
{
    return getRuleContext<mysqlParser::Max_number_of_rowsContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::MIN_ROWS()
{
    return getToken(mysqlParser::MIN_ROWS, 0);
}

mysqlParser::Min_number_of_rowsContext *mysqlParser::Partition_optionsContext::min_number_of_rows()
{
    return getRuleContext<mysqlParser::Min_number_of_rowsContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::TABLESPACE()
{
    return getToken(mysqlParser::TABLESPACE, 0);
}

mysqlParser::Tablespace_nameContext *mysqlParser::Partition_optionsContext::tablespace_name()
{
    return getRuleContext<mysqlParser::Tablespace_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::STORAGE()
{
    return getToken(mysqlParser::STORAGE, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Partition_optionsContext::EQUAL()
{
    return getTokens(mysqlParser::EQUAL);
}

tree::TerminalNode *mysqlParser::Partition_optionsContext::EQUAL(size_t i)
{
    return getToken(mysqlParser::EQUAL, i);
}

size_t mysqlParser::Partition_optionsContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_options;
}

void mysqlParser::Partition_optionsContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_options(this);
}

void mysqlParser::Partition_optionsContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_options(this);
}

antlrcpp::Any mysqlParser::Partition_optionsContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_options(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_optionsContext *mysqlParser::partition_options()
{
    Partition_optionsContext *_localctx
        = _tracker.createInstance<Partition_optionsContext>(_ctx, getState());
    enterRule(_localctx, 42, mysqlParser::RulePartition_options);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(846);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::ENGINE || _la == mysqlParser::STORAGE)
        {
            setState(839);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::STORAGE)
            {
                setState(838);
                match(mysqlParser::STORAGE);
            }
            setState(841);
            match(mysqlParser::ENGINE);
            setState(843);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(842);
                match(mysqlParser::EQUAL);
            }
            setState(845);
            engine_name();
        }
        setState(853);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::COMMENT)
        {
            setState(848);
            match(mysqlParser::COMMENT);
            setState(850);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(849);
                match(mysqlParser::EQUAL);
            }
            setState(852);
            comment();
        }
        setState(861);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::DATA)
        {
            setState(855);
            match(mysqlParser::DATA);
            setState(856);
            match(mysqlParser::DIRECTORY);
            setState(858);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(857);
                match(mysqlParser::EQUAL);
            }
            setState(860);
            data_directory();
        }
        setState(869);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::INDEX)
        {
            setState(863);
            match(mysqlParser::INDEX);
            setState(864);
            match(mysqlParser::DIRECTORY);
            setState(866);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(865);
                match(mysqlParser::EQUAL);
            }
            setState(868);
            index_directory();
        }
        setState(876);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::MAX_ROWS)
        {
            setState(871);
            match(mysqlParser::MAX_ROWS);
            setState(873);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(872);
                match(mysqlParser::EQUAL);
            }
            setState(875);
            max_number_of_rows();
        }
        setState(883);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::MIN_ROWS)
        {
            setState(878);
            match(mysqlParser::MIN_ROWS);
            setState(880);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(879);
                match(mysqlParser::EQUAL);
            }
            setState(882);
            min_number_of_rows();
        }
        setState(890);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::TABLESPACE)
        {
            setState(885);
            match(mysqlParser::TABLESPACE);
            setState(887);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(886);
                match(mysqlParser::EQUAL);
            }
            setState(889);
            tablespace_name();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Index_optionContext
//------------------------------------------------------------------

mysqlParser::Index_optionContext::Index_optionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Index_optionContext::KEY_BLOCK_SIZE()
{
    return getToken(mysqlParser::KEY_BLOCK_SIZE, 0);
}

mysqlParser::Key_block_sizeContext *mysqlParser::Index_optionContext::key_block_size()
{
    return getRuleContext<mysqlParser::Key_block_sizeContext>(0);
}

tree::TerminalNode *mysqlParser::Index_optionContext::EQUAL()
{
    return getToken(mysqlParser::EQUAL, 0);
}

tree::TerminalNode *mysqlParser::Index_optionContext::USING()
{
    return getToken(mysqlParser::USING, 0);
}

mysqlParser::Index_structureContext *mysqlParser::Index_optionContext::index_structure()
{
    return getRuleContext<mysqlParser::Index_structureContext>(0);
}

tree::TerminalNode *mysqlParser::Index_optionContext::WITH()
{
    return getToken(mysqlParser::WITH, 0);
}

tree::TerminalNode *mysqlParser::Index_optionContext::PARSER()
{
    return getToken(mysqlParser::PARSER, 0);
}

mysqlParser::Parser_nameContext *mysqlParser::Index_optionContext::parser_name()
{
    return getRuleContext<mysqlParser::Parser_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Index_optionContext::COMMENT()
{
    return getToken(mysqlParser::COMMENT, 0);
}

mysqlParser::CommentContext *mysqlParser::Index_optionContext::comment()
{
    return getRuleContext<mysqlParser::CommentContext>(0);
}

size_t mysqlParser::Index_optionContext::getRuleIndex() const
{
    return mysqlParser::RuleIndex_option;
}

void mysqlParser::Index_optionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIndex_option(this);
}

void mysqlParser::Index_optionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIndex_option(this);
}

antlrcpp::Any mysqlParser::Index_optionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIndex_option(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Index_optionContext *mysqlParser::index_option()
{
    Index_optionContext *_localctx = _tracker.createInstance<Index_optionContext>(_ctx, getState());
    enterRule(_localctx, 44, mysqlParser::RuleIndex_option);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(904);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::KEY_BLOCK_SIZE:
        {
            enterOuterAlt(_localctx, 1);
            setState(892);
            match(mysqlParser::KEY_BLOCK_SIZE);
            setState(894);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(893);
                match(mysqlParser::EQUAL);
            }
            setState(896);
            key_block_size();
            break;
        }

        case mysqlParser::USING:
        {
            enterOuterAlt(_localctx, 2);
            setState(897);
            match(mysqlParser::USING);
            setState(898);
            index_structure();
            break;
        }

        case mysqlParser::WITH:
        {
            enterOuterAlt(_localctx, 3);
            setState(899);
            match(mysqlParser::WITH);
            setState(900);
            match(mysqlParser::PARSER);
            setState(901);
            parser_name();
            break;
        }

        case mysqlParser::COMMENT:
        {
            enterOuterAlt(_localctx, 4);
            setState(902);
            match(mysqlParser::COMMENT);
            setState(903);
            comment();
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Reference_definitionContext
//------------------------------------------------------------------

mysqlParser::Reference_definitionContext::Reference_definitionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Reference_definitionContext::REFERENCES()
{
    return getToken(mysqlParser::REFERENCES, 0);
}

mysqlParser::Table_nameContext *mysqlParser::Reference_definitionContext::table_name()
{
    return getRuleContext<mysqlParser::Table_nameContext>(0);
}

mysqlParser::Reference_column_listContext *mysqlParser::Reference_definitionContext::
    reference_column_list()
{
    return getRuleContext<mysqlParser::Reference_column_listContext>(0);
}

tree::TerminalNode *mysqlParser::Reference_definitionContext::MATCH()
{
    return getToken(mysqlParser::MATCH, 0);
}

mysqlParser::Match_optionContext *mysqlParser::Reference_definitionContext::match_option()
{
    return getRuleContext<mysqlParser::Match_optionContext>(0);
}

std::vector<tree::TerminalNode *> mysqlParser::Reference_definitionContext::ON()
{
    return getTokens(mysqlParser::ON);
}

tree::TerminalNode *mysqlParser::Reference_definitionContext::ON(size_t i)
{
    return getToken(mysqlParser::ON, i);
}

tree::TerminalNode *mysqlParser::Reference_definitionContext::DELETE()
{
    return getToken(mysqlParser::DELETE, 0);
}

mysqlParser::On_delete_optionContext *mysqlParser::Reference_definitionContext::on_delete_option()
{
    return getRuleContext<mysqlParser::On_delete_optionContext>(0);
}

tree::TerminalNode *mysqlParser::Reference_definitionContext::UPDATE()
{
    return getToken(mysqlParser::UPDATE, 0);
}

mysqlParser::On_update_optionContext *mysqlParser::Reference_definitionContext::on_update_option()
{
    return getRuleContext<mysqlParser::On_update_optionContext>(0);
}

size_t mysqlParser::Reference_definitionContext::getRuleIndex() const
{
    return mysqlParser::RuleReference_definition;
}

void mysqlParser::Reference_definitionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterReference_definition(this);
}

void mysqlParser::Reference_definitionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitReference_definition(this);
}

antlrcpp::Any mysqlParser::Reference_definitionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitReference_definition(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Reference_definitionContext *mysqlParser::reference_definition()
{
    Reference_definitionContext *_localctx
        = _tracker.createInstance<Reference_definitionContext>(_ctx, getState());
    enterRule(_localctx, 46, mysqlParser::RuleReference_definition);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(906);
        match(mysqlParser::REFERENCES);
        setState(907);
        table_name();
        setState(909);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::LPAREN)
        {
            setState(908);
            reference_column_list();
        }
        setState(913);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::MATCH)
        {
            setState(911);
            match(mysqlParser::MATCH);
            setState(912);
            match_option();
        }
        setState(918);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx))
        {
        case 1:
        {
            setState(915);
            match(mysqlParser::ON);
            setState(916);
            match(mysqlParser::DELETE);
            setState(917);
            on_delete_option();
            break;
        }
        }
        setState(923);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::ON)
        {
            setState(920);
            match(mysqlParser::ON);
            setState(921);
            match(mysqlParser::UPDATE);
            setState(922);
            on_update_option();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Create_definition_listContext
//------------------------------------------------------------------

mysqlParser::Create_definition_listContext::Create_definition_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Create_definition_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::Create_definitionContext *> mysqlParser::Create_definition_listContext::
    create_definition()
{
    return getRuleContexts<mysqlParser::Create_definitionContext>();
}

mysqlParser::Create_definitionContext *mysqlParser::Create_definition_listContext::
    create_definition(size_t i)
{
    return getRuleContext<mysqlParser::Create_definitionContext>(i);
}

tree::TerminalNode *mysqlParser::Create_definition_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Create_definition_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Create_definition_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Create_definition_listContext::getRuleIndex() const
{
    return mysqlParser::RuleCreate_definition_list;
}

void mysqlParser::Create_definition_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCreate_definition_list(this);
}

void mysqlParser::Create_definition_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCreate_definition_list(this);
}

antlrcpp::Any mysqlParser::Create_definition_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCreate_definition_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Create_definition_listContext *mysqlParser::create_definition_list()
{
    Create_definition_listContext *_localctx
        = _tracker.createInstance<Create_definition_listContext>(_ctx, getState());
    enterRule(_localctx, 48, mysqlParser::RuleCreate_definition_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(925);
        match(mysqlParser::LPAREN);
        setState(926);
        create_definition();
        setState(931);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(927);
            match(mysqlParser::COMMA);
            setState(928);
            create_definition();
            setState(933);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(934);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Table_option_listContext
//------------------------------------------------------------------

mysqlParser::Table_option_listContext::Table_option_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<mysqlParser::Table_optionContext *> mysqlParser::Table_option_listContext::
    table_option()
{
    return getRuleContexts<mysqlParser::Table_optionContext>();
}

mysqlParser::Table_optionContext *mysqlParser::Table_option_listContext::table_option(size_t i)
{
    return getRuleContext<mysqlParser::Table_optionContext>(i);
}

std::vector<tree::TerminalNode *> mysqlParser::Table_option_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Table_option_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Table_option_listContext::getRuleIndex() const
{
    return mysqlParser::RuleTable_option_list;
}

void mysqlParser::Table_option_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterTable_option_list(this);
}

void mysqlParser::Table_option_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitTable_option_list(this);
}

antlrcpp::Any mysqlParser::Table_option_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitTable_option_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Table_option_listContext *mysqlParser::table_option_list()
{
    Table_option_listContext *_localctx
        = _tracker.createInstance<Table_option_listContext>(_ctx, getState());
    enterRule(_localctx, 50, mysqlParser::RuleTable_option_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(936);
        table_option();
        setState(943);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
        {
            if (alt == 1)
            {
                setState(938);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == mysqlParser::COMMA)
                {
                    setState(937);
                    match(mysqlParser::COMMA);
                }
                setState(940);
                table_option();
            }
            setState(945);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Index_option_listContext
//------------------------------------------------------------------

mysqlParser::Index_option_listContext::Index_option_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<mysqlParser::Index_optionContext *> mysqlParser::Index_option_listContext::
    index_option()
{
    return getRuleContexts<mysqlParser::Index_optionContext>();
}

mysqlParser::Index_optionContext *mysqlParser::Index_option_listContext::index_option(size_t i)
{
    return getRuleContext<mysqlParser::Index_optionContext>(i);
}

size_t mysqlParser::Index_option_listContext::getRuleIndex() const
{
    return mysqlParser::RuleIndex_option_list;
}

void mysqlParser::Index_option_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIndex_option_list(this);
}

void mysqlParser::Index_option_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIndex_option_list(this);
}

antlrcpp::Any mysqlParser::Index_option_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIndex_option_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Index_option_listContext *mysqlParser::index_option_list()
{
    Index_option_listContext *_localctx
        = _tracker.createInstance<Index_option_listContext>(_ctx, getState());
    enterRule(_localctx, 52, mysqlParser::RuleIndex_option_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(949);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMENT || _la == mysqlParser::KEY_BLOCK_SIZE
               || _la == mysqlParser::USING

               || _la == mysqlParser::WITH)
        {
            setState(946);
            index_option();
            setState(951);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Index_column_listContext
//------------------------------------------------------------------

mysqlParser::Index_column_listContext::Index_column_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Index_column_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::Index_columnContext *> mysqlParser::Index_column_listContext::
    index_column()
{
    return getRuleContexts<mysqlParser::Index_columnContext>();
}

mysqlParser::Index_columnContext *mysqlParser::Index_column_listContext::index_column(size_t i)
{
    return getRuleContext<mysqlParser::Index_columnContext>(i);
}

tree::TerminalNode *mysqlParser::Index_column_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Index_column_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Index_column_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Index_column_listContext::getRuleIndex() const
{
    return mysqlParser::RuleIndex_column_list;
}

void mysqlParser::Index_column_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIndex_column_list(this);
}

void mysqlParser::Index_column_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIndex_column_list(this);
}

antlrcpp::Any mysqlParser::Index_column_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIndex_column_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Index_column_listContext *mysqlParser::index_column_list()
{
    Index_column_listContext *_localctx
        = _tracker.createInstance<Index_column_listContext>(_ctx, getState());
    enterRule(_localctx, 54, mysqlParser::RuleIndex_column_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(952);
        match(mysqlParser::LPAREN);
        setState(953);
        index_column();
        setState(958);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(954);
            match(mysqlParser::COMMA);
            setState(955);
            index_column();
            setState(960);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(961);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Reference_column_listContext
//------------------------------------------------------------------

mysqlParser::Reference_column_listContext::Reference_column_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Reference_column_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::Reference_columnContext *> mysqlParser::Reference_column_listContext::
    reference_column()
{
    return getRuleContexts<mysqlParser::Reference_columnContext>();
}

mysqlParser::Reference_columnContext *mysqlParser::Reference_column_listContext::reference_column(
    size_t i)
{
    return getRuleContext<mysqlParser::Reference_columnContext>(i);
}

tree::TerminalNode *mysqlParser::Reference_column_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Reference_column_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Reference_column_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Reference_column_listContext::getRuleIndex() const
{
    return mysqlParser::RuleReference_column_list;
}

void mysqlParser::Reference_column_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterReference_column_list(this);
}

void mysqlParser::Reference_column_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitReference_column_list(this);
}

antlrcpp::Any mysqlParser::Reference_column_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitReference_column_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Reference_column_listContext *mysqlParser::reference_column_list()
{
    Reference_column_listContext *_localctx
        = _tracker.createInstance<Reference_column_listContext>(_ctx, getState());
    enterRule(_localctx, 56, mysqlParser::RuleReference_column_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(963);
        match(mysqlParser::LPAREN);
        setState(964);
        reference_column();
        setState(969);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(965);
            match(mysqlParser::COMMA);
            setState(966);
            reference_column();
            setState(971);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(972);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Less_than_value_listContext
//------------------------------------------------------------------

mysqlParser::Less_than_value_listContext::Less_than_value_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Less_than_value_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::LiteralContext *> mysqlParser::Less_than_value_listContext::literal()
{
    return getRuleContexts<mysqlParser::LiteralContext>();
}

mysqlParser::LiteralContext *mysqlParser::Less_than_value_listContext::literal(size_t i)
{
    return getRuleContext<mysqlParser::LiteralContext>(i);
}

tree::TerminalNode *mysqlParser::Less_than_value_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Less_than_value_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Less_than_value_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Less_than_value_listContext::getRuleIndex() const
{
    return mysqlParser::RuleLess_than_value_list;
}

void mysqlParser::Less_than_value_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterLess_than_value_list(this);
}

void mysqlParser::Less_than_value_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitLess_than_value_list(this);
}

antlrcpp::Any mysqlParser::Less_than_value_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitLess_than_value_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Less_than_value_listContext *mysqlParser::less_than_value_list()
{
    Less_than_value_listContext *_localctx
        = _tracker.createInstance<Less_than_value_listContext>(_ctx, getState());
    enterRule(_localctx, 58, mysqlParser::RuleLess_than_value_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(974);
        match(mysqlParser::LPAREN);
        setState(975);
        literal();
        setState(980);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(976);
            match(mysqlParser::COMMA);
            setState(977);
            literal();
            setState(982);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(983);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- In_value_listContext
//------------------------------------------------------------------

mysqlParser::In_value_listContext::In_value_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::In_value_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::LiteralContext *> mysqlParser::In_value_listContext::literal()
{
    return getRuleContexts<mysqlParser::LiteralContext>();
}

mysqlParser::LiteralContext *mysqlParser::In_value_listContext::literal(size_t i)
{
    return getRuleContext<mysqlParser::LiteralContext>(i);
}

tree::TerminalNode *mysqlParser::In_value_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::In_value_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::In_value_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::In_value_listContext::getRuleIndex() const
{
    return mysqlParser::RuleIn_value_list;
}

void mysqlParser::In_value_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIn_value_list(this);
}

void mysqlParser::In_value_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIn_value_list(this);
}

antlrcpp::Any mysqlParser::In_value_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIn_value_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::In_value_listContext *mysqlParser::in_value_list()
{
    In_value_listContext *_localctx
        = _tracker.createInstance<In_value_listContext>(_ctx, getState());
    enterRule(_localctx, 60, mysqlParser::RuleIn_value_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(985);
        match(mysqlParser::LPAREN);
        setState(986);
        literal();
        setState(991);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(987);
            match(mysqlParser::COMMA);
            setState(988);
            literal();
            setState(993);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(994);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Enum_value_listContext
//------------------------------------------------------------------

mysqlParser::Enum_value_listContext::Enum_value_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Enum_value_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::LiteralContext *> mysqlParser::Enum_value_listContext::literal()
{
    return getRuleContexts<mysqlParser::LiteralContext>();
}

mysqlParser::LiteralContext *mysqlParser::Enum_value_listContext::literal(size_t i)
{
    return getRuleContext<mysqlParser::LiteralContext>(i);
}

tree::TerminalNode *mysqlParser::Enum_value_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Enum_value_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Enum_value_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Enum_value_listContext::getRuleIndex() const
{
    return mysqlParser::RuleEnum_value_list;
}

void mysqlParser::Enum_value_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterEnum_value_list(this);
}

void mysqlParser::Enum_value_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitEnum_value_list(this);
}

antlrcpp::Any mysqlParser::Enum_value_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitEnum_value_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Enum_value_listContext *mysqlParser::enum_value_list()
{
    Enum_value_listContext *_localctx
        = _tracker.createInstance<Enum_value_listContext>(_ctx, getState());
    enterRule(_localctx, 62, mysqlParser::RuleEnum_value_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(996);
        match(mysqlParser::LPAREN);
        setState(997);
        literal();
        setState(1002);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(998);
            match(mysqlParser::COMMA);
            setState(999);
            literal();
            setState(1004);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(1005);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Key_column_listContext
//------------------------------------------------------------------

mysqlParser::Key_column_listContext::Key_column_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Key_column_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::IdentifierContext *> mysqlParser::Key_column_listContext::identifier()
{
    return getRuleContexts<mysqlParser::IdentifierContext>();
}

mysqlParser::IdentifierContext *mysqlParser::Key_column_listContext::identifier(size_t i)
{
    return getRuleContext<mysqlParser::IdentifierContext>(i);
}

tree::TerminalNode *mysqlParser::Key_column_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Key_column_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Key_column_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Key_column_listContext::getRuleIndex() const
{
    return mysqlParser::RuleKey_column_list;
}

void mysqlParser::Key_column_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterKey_column_list(this);
}

void mysqlParser::Key_column_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitKey_column_list(this);
}

antlrcpp::Any mysqlParser::Key_column_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitKey_column_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Key_column_listContext *mysqlParser::key_column_list()
{
    Key_column_listContext *_localctx
        = _tracker.createInstance<Key_column_listContext>(_ctx, getState());
    enterRule(_localctx, 64, mysqlParser::RuleKey_column_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1007);
        match(mysqlParser::LPAREN);
        setState(1008);
        identifier();
        setState(1013);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(1009);
            match(mysqlParser::COMMA);
            setState(1010);
            identifier();
            setState(1015);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(1016);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Range_column_listContext
//------------------------------------------------------------------

mysqlParser::Range_column_listContext::Range_column_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Range_column_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::IdentifierContext *> mysqlParser::Range_column_listContext::identifier()
{
    return getRuleContexts<mysqlParser::IdentifierContext>();
}

mysqlParser::IdentifierContext *mysqlParser::Range_column_listContext::identifier(size_t i)
{
    return getRuleContext<mysqlParser::IdentifierContext>(i);
}

tree::TerminalNode *mysqlParser::Range_column_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Range_column_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Range_column_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Range_column_listContext::getRuleIndex() const
{
    return mysqlParser::RuleRange_column_list;
}

void mysqlParser::Range_column_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterRange_column_list(this);
}

void mysqlParser::Range_column_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitRange_column_list(this);
}

antlrcpp::Any mysqlParser::Range_column_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitRange_column_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Range_column_listContext *mysqlParser::range_column_list()
{
    Range_column_listContext *_localctx
        = _tracker.createInstance<Range_column_listContext>(_ctx, getState());
    enterRule(_localctx, 66, mysqlParser::RuleRange_column_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1018);
        match(mysqlParser::LPAREN);
        setState(1019);
        identifier();
        setState(1024);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(1020);
            match(mysqlParser::COMMA);
            setState(1021);
            identifier();
            setState(1026);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(1027);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- List_column_listContext
//------------------------------------------------------------------

mysqlParser::List_column_listContext::List_column_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::List_column_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::IdentifierContext *> mysqlParser::List_column_listContext::identifier()
{
    return getRuleContexts<mysqlParser::IdentifierContext>();
}

mysqlParser::IdentifierContext *mysqlParser::List_column_listContext::identifier(size_t i)
{
    return getRuleContext<mysqlParser::IdentifierContext>(i);
}

tree::TerminalNode *mysqlParser::List_column_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::List_column_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::List_column_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::List_column_listContext::getRuleIndex() const
{
    return mysqlParser::RuleList_column_list;
}

void mysqlParser::List_column_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterList_column_list(this);
}

void mysqlParser::List_column_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitList_column_list(this);
}

antlrcpp::Any mysqlParser::List_column_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitList_column_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::List_column_listContext *mysqlParser::list_column_list()
{
    List_column_listContext *_localctx
        = _tracker.createInstance<List_column_listContext>(_ctx, getState());
    enterRule(_localctx, 68, mysqlParser::RuleList_column_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1029);
        match(mysqlParser::LPAREN);
        setState(1030);
        identifier();
        setState(1035);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(1031);
            match(mysqlParser::COMMA);
            setState(1032);
            identifier();
            setState(1037);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(1038);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Table_union_listContext
//------------------------------------------------------------------

mysqlParser::Table_union_listContext::Table_union_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Table_union_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::Table_nameContext *> mysqlParser::Table_union_listContext::table_name()
{
    return getRuleContexts<mysqlParser::Table_nameContext>();
}

mysqlParser::Table_nameContext *mysqlParser::Table_union_listContext::table_name(size_t i)
{
    return getRuleContext<mysqlParser::Table_nameContext>(i);
}

tree::TerminalNode *mysqlParser::Table_union_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Table_union_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Table_union_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Table_union_listContext::getRuleIndex() const
{
    return mysqlParser::RuleTable_union_list;
}

void mysqlParser::Table_union_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterTable_union_list(this);
}

void mysqlParser::Table_union_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitTable_union_list(this);
}

antlrcpp::Any mysqlParser::Table_union_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitTable_union_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Table_union_listContext *mysqlParser::table_union_list()
{
    Table_union_listContext *_localctx
        = _tracker.createInstance<Table_union_listContext>(_ctx, getState());
    enterRule(_localctx, 70, mysqlParser::RuleTable_union_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1040);
        match(mysqlParser::LPAREN);
        setState(1041);
        table_name();
        setState(1046);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(1042);
            match(mysqlParser::COMMA);
            setState(1043);
            table_name();
            setState(1048);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(1049);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ConstraintContext
//------------------------------------------------------------------

mysqlParser::ConstraintContext::ConstraintContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::ConstraintContext::CONSTRAINT()
{
    return getToken(mysqlParser::CONSTRAINT, 0);
}

mysqlParser::SymbolContext *mysqlParser::ConstraintContext::symbol()
{
    return getRuleContext<mysqlParser::SymbolContext>(0);
}

size_t mysqlParser::ConstraintContext::getRuleIndex() const
{
    return mysqlParser::RuleConstraint;
}

void mysqlParser::ConstraintContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterConstraint(this);
}

void mysqlParser::ConstraintContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitConstraint(this);
}

antlrcpp::Any mysqlParser::ConstraintContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitConstraint(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::ConstraintContext *mysqlParser::constraint()
{
    ConstraintContext *_localctx = _tracker.createInstance<ConstraintContext>(_ctx, getState());
    enterRule(_localctx, 72, mysqlParser::RuleConstraint);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1051);
        match(mysqlParser::CONSTRAINT);
        setState(1053);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::ID

            || _la == mysqlParser::BQUOTED_STRING)
        {
            setState(1052);
            symbol();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CharsetContext
//------------------------------------------------------------------

mysqlParser::CharsetContext::CharsetContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Charset_nameContext *mysqlParser::CharsetContext::charset_name()
{
    return getRuleContext<mysqlParser::Charset_nameContext>(0);
}

tree::TerminalNode *mysqlParser::CharsetContext::CHARACTER()
{
    return getToken(mysqlParser::CHARACTER, 0);
}

tree::TerminalNode *mysqlParser::CharsetContext::SET()
{
    return getToken(mysqlParser::SET, 0);
}

tree::TerminalNode *mysqlParser::CharsetContext::CHARSET()
{
    return getToken(mysqlParser::CHARSET, 0);
}

tree::TerminalNode *mysqlParser::CharsetContext::EQUAL()
{
    return getToken(mysqlParser::EQUAL, 0);
}

size_t mysqlParser::CharsetContext::getRuleIndex() const
{
    return mysqlParser::RuleCharset;
}

void mysqlParser::CharsetContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCharset(this);
}

void mysqlParser::CharsetContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCharset(this);
}

antlrcpp::Any mysqlParser::CharsetContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCharset(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::CharsetContext *mysqlParser::charset()
{
    CharsetContext *_localctx = _tracker.createInstance<CharsetContext>(_ctx, getState());
    enterRule(_localctx, 74, mysqlParser::RuleCharset);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1058);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::CHARACTER:
        {
            setState(1055);
            match(mysqlParser::CHARACTER);
            setState(1056);
            match(mysqlParser::SET);
            break;
        }

        case mysqlParser::CHARSET:
        {
            setState(1057);
            match(mysqlParser::CHARSET);
            break;
        }

        default:
            throw NoViableAltException(this);
        }
        setState(1061);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::EQUAL)
        {
            setState(1060);
            match(mysqlParser::EQUAL);
        }
        setState(1063);
        charset_name();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CollationContext
//------------------------------------------------------------------

mysqlParser::CollationContext::CollationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::CollationContext::COLLATE()
{
    return getToken(mysqlParser::COLLATE, 0);
}

mysqlParser::Collation_nameContext *mysqlParser::CollationContext::collation_name()
{
    return getRuleContext<mysqlParser::Collation_nameContext>(0);
}

tree::TerminalNode *mysqlParser::CollationContext::EQUAL()
{
    return getToken(mysqlParser::EQUAL, 0);
}

size_t mysqlParser::CollationContext::getRuleIndex() const
{
    return mysqlParser::RuleCollation;
}

void mysqlParser::CollationContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCollation(this);
}

void mysqlParser::CollationContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCollation(this);
}

antlrcpp::Any mysqlParser::CollationContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCollation(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::CollationContext *mysqlParser::collation()
{
    CollationContext *_localctx = _tracker.createInstance<CollationContext>(_ctx, getState());
    enterRule(_localctx, 76, mysqlParser::RuleCollation);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1065);
        match(mysqlParser::COLLATE);
        setState(1067);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::EQUAL)
        {
            setState(1066);
            match(mysqlParser::EQUAL);
        }
        setState(1069);
        collation_name();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Index_structureContext
//------------------------------------------------------------------

mysqlParser::Index_structureContext::Index_structureContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Index_structureContext::BTREE()
{
    return getToken(mysqlParser::BTREE, 0);
}

tree::TerminalNode *mysqlParser::Index_structureContext::HASH()
{
    return getToken(mysqlParser::HASH, 0);
}

size_t mysqlParser::Index_structureContext::getRuleIndex() const
{
    return mysqlParser::RuleIndex_structure;
}

void mysqlParser::Index_structureContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIndex_structure(this);
}

void mysqlParser::Index_structureContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIndex_structure(this);
}

antlrcpp::Any mysqlParser::Index_structureContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIndex_structure(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Index_structureContext *mysqlParser::index_structure()
{
    Index_structureContext *_localctx
        = _tracker.createInstance<Index_structureContext>(_ctx, getState());
    enterRule(_localctx, 78, mysqlParser::RuleIndex_structure);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1071);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::BTREE || _la == mysqlParser::HASH))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Index_columnContext
//------------------------------------------------------------------

mysqlParser::Index_columnContext::Index_columnContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Column_nameContext *mysqlParser::Index_columnContext::column_name()
{
    return getRuleContext<mysqlParser::Column_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Index_columnContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

mysqlParser::LengthContext *mysqlParser::Index_columnContext::length()
{
    return getRuleContext<mysqlParser::LengthContext>(0);
}

tree::TerminalNode *mysqlParser::Index_columnContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

tree::TerminalNode *mysqlParser::Index_columnContext::ASC()
{
    return getToken(mysqlParser::ASC, 0);
}

tree::TerminalNode *mysqlParser::Index_columnContext::DESC()
{
    return getToken(mysqlParser::DESC, 0);
}

size_t mysqlParser::Index_columnContext::getRuleIndex() const
{
    return mysqlParser::RuleIndex_column;
}

void mysqlParser::Index_columnContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIndex_column(this);
}

void mysqlParser::Index_columnContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIndex_column(this);
}

antlrcpp::Any mysqlParser::Index_columnContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIndex_column(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Index_columnContext *mysqlParser::index_column()
{
    Index_columnContext *_localctx = _tracker.createInstance<Index_columnContext>(_ctx, getState());
    enterRule(_localctx, 80, mysqlParser::RuleIndex_column);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1073);
        column_name();
        setState(1078);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::LPAREN)
        {
            setState(1074);
            match(mysqlParser::LPAREN);
            setState(1075);
            length();
            setState(1076);
            match(mysqlParser::RPAREN);
        }
        setState(1081);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::ASC || _la == mysqlParser::DESC)
        {
            setState(1080);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::ASC || _la == mysqlParser::DESC))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Reference_columnContext
//------------------------------------------------------------------

mysqlParser::Reference_columnContext::Reference_columnContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Column_nameContext *mysqlParser::Reference_columnContext::column_name()
{
    return getRuleContext<mysqlParser::Column_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Reference_columnContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

mysqlParser::LengthContext *mysqlParser::Reference_columnContext::length()
{
    return getRuleContext<mysqlParser::LengthContext>(0);
}

tree::TerminalNode *mysqlParser::Reference_columnContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

tree::TerminalNode *mysqlParser::Reference_columnContext::ASC()
{
    return getToken(mysqlParser::ASC, 0);
}

tree::TerminalNode *mysqlParser::Reference_columnContext::DESC()
{
    return getToken(mysqlParser::DESC, 0);
}

size_t mysqlParser::Reference_columnContext::getRuleIndex() const
{
    return mysqlParser::RuleReference_column;
}

void mysqlParser::Reference_columnContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterReference_column(this);
}

void mysqlParser::Reference_columnContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitReference_column(this);
}

antlrcpp::Any mysqlParser::Reference_columnContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitReference_column(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Reference_columnContext *mysqlParser::reference_column()
{
    Reference_columnContext *_localctx
        = _tracker.createInstance<Reference_columnContext>(_ctx, getState());
    enterRule(_localctx, 82, mysqlParser::RuleReference_column);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1083);
        column_name();
        setState(1088);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::LPAREN)
        {
            setState(1084);
            match(mysqlParser::LPAREN);
            setState(1085);
            length();
            setState(1086);
            match(mysqlParser::RPAREN);
        }
        setState(1091);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::ASC || _la == mysqlParser::DESC)
        {
            setState(1090);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::ASC || _la == mysqlParser::DESC))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- FspContext ------------------------------------------------------------------

mysqlParser::FspContext::FspContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::FspContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::FspContext::getRuleIndex() const
{
    return mysqlParser::RuleFsp;
}

void mysqlParser::FspContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterFsp(this);
}

void mysqlParser::FspContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitFsp(this);
}

antlrcpp::Any mysqlParser::FspContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitFsp(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::FspContext *mysqlParser::fsp()
{
    FspContext *_localctx = _tracker.createInstance<FspContext>(_ctx, getState());
    enterRule(_localctx, 84, mysqlParser::RuleFsp);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1093);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- LengthContext ------------------------------------------------------------------

mysqlParser::LengthContext::LengthContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::LengthContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::LengthContext::getRuleIndex() const
{
    return mysqlParser::RuleLength;
}

void mysqlParser::LengthContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterLength(this);
}

void mysqlParser::LengthContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitLength(this);
}

antlrcpp::Any mysqlParser::LengthContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitLength(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::LengthContext *mysqlParser::length()
{
    LengthContext *_localctx = _tracker.createInstance<LengthContext>(_ctx, getState());
    enterRule(_localctx, 86, mysqlParser::RuleLength);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1095);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- DecimalsContext
//------------------------------------------------------------------

mysqlParser::DecimalsContext::DecimalsContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::DecimalsContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::DecimalsContext::getRuleIndex() const
{
    return mysqlParser::RuleDecimals;
}

void mysqlParser::DecimalsContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterDecimals(this);
}

void mysqlParser::DecimalsContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitDecimals(this);
}

antlrcpp::Any mysqlParser::DecimalsContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitDecimals(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::DecimalsContext *mysqlParser::decimals()
{
    DecimalsContext *_localctx = _tracker.createInstance<DecimalsContext>(_ctx, getState());
    enterRule(_localctx, 88, mysqlParser::RuleDecimals);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1097);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_countContext
//------------------------------------------------------------------

mysqlParser::Partition_countContext::Partition_countContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Partition_countContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Partition_countContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_count;
}

void mysqlParser::Partition_countContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_count(this);
}

void mysqlParser::Partition_countContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_count(this);
}

antlrcpp::Any mysqlParser::Partition_countContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_count(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_countContext *mysqlParser::partition_count()
{
    Partition_countContext *_localctx
        = _tracker.createInstance<Partition_countContext>(_ctx, getState());
    enterRule(_localctx, 90, mysqlParser::RulePartition_count);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1099);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Subpartition_countContext
//------------------------------------------------------------------

mysqlParser::Subpartition_countContext::Subpartition_countContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Subpartition_countContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Subpartition_countContext::getRuleIndex() const
{
    return mysqlParser::RuleSubpartition_count;
}

void mysqlParser::Subpartition_countContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterSubpartition_count(this);
}

void mysqlParser::Subpartition_countContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitSubpartition_count(this);
}

antlrcpp::Any mysqlParser::Subpartition_countContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitSubpartition_count(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Subpartition_countContext *mysqlParser::subpartition_count()
{
    Subpartition_countContext *_localctx
        = _tracker.createInstance<Subpartition_countContext>(_ctx, getState());
    enterRule(_localctx, 92, mysqlParser::RuleSubpartition_count);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1101);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Auto_incrementContext
//------------------------------------------------------------------

mysqlParser::Auto_incrementContext::Auto_incrementContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Auto_incrementContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Auto_incrementContext::getRuleIndex() const
{
    return mysqlParser::RuleAuto_increment;
}

void mysqlParser::Auto_incrementContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterAuto_increment(this);
}

void mysqlParser::Auto_incrementContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitAuto_increment(this);
}

antlrcpp::Any mysqlParser::Auto_incrementContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitAuto_increment(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Auto_incrementContext *mysqlParser::auto_increment()
{
    Auto_incrementContext *_localctx
        = _tracker.createInstance<Auto_incrementContext>(_ctx, getState());
    enterRule(_localctx, 94, mysqlParser::RuleAuto_increment);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1103);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Avg_row_lengthContext
//------------------------------------------------------------------

mysqlParser::Avg_row_lengthContext::Avg_row_lengthContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Avg_row_lengthContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Avg_row_lengthContext::getRuleIndex() const
{
    return mysqlParser::RuleAvg_row_length;
}

void mysqlParser::Avg_row_lengthContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterAvg_row_length(this);
}

void mysqlParser::Avg_row_lengthContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitAvg_row_length(this);
}

antlrcpp::Any mysqlParser::Avg_row_lengthContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitAvg_row_length(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Avg_row_lengthContext *mysqlParser::avg_row_length()
{
    Avg_row_lengthContext *_localctx
        = _tracker.createInstance<Avg_row_lengthContext>(_ctx, getState());
    enterRule(_localctx, 96, mysqlParser::RuleAvg_row_length);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1105);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Key_block_sizeContext
//------------------------------------------------------------------

mysqlParser::Key_block_sizeContext::Key_block_sizeContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Key_block_sizeContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Key_block_sizeContext::getRuleIndex() const
{
    return mysqlParser::RuleKey_block_size;
}

void mysqlParser::Key_block_sizeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterKey_block_size(this);
}

void mysqlParser::Key_block_sizeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitKey_block_size(this);
}

antlrcpp::Any mysqlParser::Key_block_sizeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitKey_block_size(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Key_block_sizeContext *mysqlParser::key_block_size()
{
    Key_block_sizeContext *_localctx
        = _tracker.createInstance<Key_block_sizeContext>(_ctx, getState());
    enterRule(_localctx, 98, mysqlParser::RuleKey_block_size);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1107);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Max_number_of_rowsContext
//------------------------------------------------------------------

mysqlParser::Max_number_of_rowsContext::Max_number_of_rowsContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Max_number_of_rowsContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Max_number_of_rowsContext::getRuleIndex() const
{
    return mysqlParser::RuleMax_number_of_rows;
}

void mysqlParser::Max_number_of_rowsContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterMax_number_of_rows(this);
}

void mysqlParser::Max_number_of_rowsContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitMax_number_of_rows(this);
}

antlrcpp::Any mysqlParser::Max_number_of_rowsContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitMax_number_of_rows(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Max_number_of_rowsContext *mysqlParser::max_number_of_rows()
{
    Max_number_of_rowsContext *_localctx
        = _tracker.createInstance<Max_number_of_rowsContext>(_ctx, getState());
    enterRule(_localctx, 100, mysqlParser::RuleMax_number_of_rows);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1109);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Min_number_of_rowsContext
//------------------------------------------------------------------

mysqlParser::Min_number_of_rowsContext::Min_number_of_rowsContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Min_number_of_rowsContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Min_number_of_rowsContext::getRuleIndex() const
{
    return mysqlParser::RuleMin_number_of_rows;
}

void mysqlParser::Min_number_of_rowsContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterMin_number_of_rows(this);
}

void mysqlParser::Min_number_of_rowsContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitMin_number_of_rows(this);
}

antlrcpp::Any mysqlParser::Min_number_of_rowsContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitMin_number_of_rows(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Min_number_of_rowsContext *mysqlParser::min_number_of_rows()
{
    Min_number_of_rowsContext *_localctx
        = _tracker.createInstance<Min_number_of_rowsContext>(_ctx, getState());
    enterRule(_localctx, 102, mysqlParser::RuleMin_number_of_rows);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1111);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Stats_sample_pagesContext
//------------------------------------------------------------------

mysqlParser::Stats_sample_pagesContext::Stats_sample_pagesContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Stats_sample_pagesContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Stats_sample_pagesContext::getRuleIndex() const
{
    return mysqlParser::RuleStats_sample_pages;
}

void mysqlParser::Stats_sample_pagesContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterStats_sample_pages(this);
}

void mysqlParser::Stats_sample_pagesContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitStats_sample_pages(this);
}

antlrcpp::Any mysqlParser::Stats_sample_pagesContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitStats_sample_pages(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Stats_sample_pagesContext *mysqlParser::stats_sample_pages()
{
    Stats_sample_pagesContext *_localctx
        = _tracker.createInstance<Stats_sample_pagesContext>(_ctx, getState());
    enterRule(_localctx, 104, mysqlParser::RuleStats_sample_pages);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1113);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ChecksumContext
//------------------------------------------------------------------

mysqlParser::ChecksumContext::ChecksumContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::ChecksumContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::ChecksumContext::getRuleIndex() const
{
    return mysqlParser::RuleChecksum;
}

void mysqlParser::ChecksumContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterChecksum(this);
}

void mysqlParser::ChecksumContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitChecksum(this);
}

antlrcpp::Any mysqlParser::ChecksumContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitChecksum(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::ChecksumContext *mysqlParser::checksum()
{
    ChecksumContext *_localctx = _tracker.createInstance<ChecksumContext>(_ctx, getState());
    enterRule(_localctx, 106, mysqlParser::RuleChecksum);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1115);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CompressionContext
//------------------------------------------------------------------

mysqlParser::CompressionContext::CompressionContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::String_literalContext *mysqlParser::CompressionContext::string_literal()
{
    return getRuleContext<mysqlParser::String_literalContext>(0);
}

size_t mysqlParser::CompressionContext::getRuleIndex() const
{
    return mysqlParser::RuleCompression;
}

void mysqlParser::CompressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCompression(this);
}

void mysqlParser::CompressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCompression(this);
}

antlrcpp::Any mysqlParser::CompressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCompression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::CompressionContext *mysqlParser::compression()
{
    CompressionContext *_localctx = _tracker.createInstance<CompressionContext>(_ctx, getState());
    enterRule(_localctx, 108, mysqlParser::RuleCompression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1117);
        string_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Delay_key_writeContext
//------------------------------------------------------------------

mysqlParser::Delay_key_writeContext::Delay_key_writeContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Delay_key_writeContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Delay_key_writeContext::getRuleIndex() const
{
    return mysqlParser::RuleDelay_key_write;
}

void mysqlParser::Delay_key_writeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterDelay_key_write(this);
}

void mysqlParser::Delay_key_writeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitDelay_key_write(this);
}

antlrcpp::Any mysqlParser::Delay_key_writeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitDelay_key_write(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Delay_key_writeContext *mysqlParser::delay_key_write()
{
    Delay_key_writeContext *_localctx
        = _tracker.createInstance<Delay_key_writeContext>(_ctx, getState());
    enterRule(_localctx, 110, mysqlParser::RuleDelay_key_write);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1119);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- EncryptionContext
//------------------------------------------------------------------

mysqlParser::EncryptionContext::EncryptionContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::String_literalContext *mysqlParser::EncryptionContext::string_literal()
{
    return getRuleContext<mysqlParser::String_literalContext>(0);
}

size_t mysqlParser::EncryptionContext::getRuleIndex() const
{
    return mysqlParser::RuleEncryption;
}

void mysqlParser::EncryptionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterEncryption(this);
}

void mysqlParser::EncryptionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitEncryption(this);
}

antlrcpp::Any mysqlParser::EncryptionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitEncryption(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::EncryptionContext *mysqlParser::encryption()
{
    EncryptionContext *_localctx = _tracker.createInstance<EncryptionContext>(_ctx, getState());
    enterRule(_localctx, 112, mysqlParser::RuleEncryption);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1121);
        string_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Insert_methodContext
//------------------------------------------------------------------

mysqlParser::Insert_methodContext::Insert_methodContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Insert_methodContext::NO()
{
    return getToken(mysqlParser::NO, 0);
}

tree::TerminalNode *mysqlParser::Insert_methodContext::FIRST()
{
    return getToken(mysqlParser::FIRST, 0);
}

tree::TerminalNode *mysqlParser::Insert_methodContext::LAST()
{
    return getToken(mysqlParser::LAST, 0);
}

size_t mysqlParser::Insert_methodContext::getRuleIndex() const
{
    return mysqlParser::RuleInsert_method;
}

void mysqlParser::Insert_methodContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterInsert_method(this);
}

void mysqlParser::Insert_methodContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitInsert_method(this);
}

antlrcpp::Any mysqlParser::Insert_methodContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitInsert_method(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Insert_methodContext *mysqlParser::insert_method()
{
    Insert_methodContext *_localctx
        = _tracker.createInstance<Insert_methodContext>(_ctx, getState());
    enterRule(_localctx, 114, mysqlParser::RuleInsert_method);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1123);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::FIRST || _la == mysqlParser::LAST || _la == mysqlParser::NO))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Pack_keysContext
//------------------------------------------------------------------

mysqlParser::Pack_keysContext::Pack_keysContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Pack_keysContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

tree::TerminalNode *mysqlParser::Pack_keysContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

size_t mysqlParser::Pack_keysContext::getRuleIndex() const
{
    return mysqlParser::RulePack_keys;
}

void mysqlParser::Pack_keysContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPack_keys(this);
}

void mysqlParser::Pack_keysContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPack_keys(this);
}

antlrcpp::Any mysqlParser::Pack_keysContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPack_keys(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Pack_keysContext *mysqlParser::pack_keys()
{
    Pack_keysContext *_localctx = _tracker.createInstance<Pack_keysContext>(_ctx, getState());
    enterRule(_localctx, 116, mysqlParser::RulePack_keys);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1127);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::INT_NUMBER:
        {
            enterOuterAlt(_localctx, 1);
            setState(1125);
            integer_literal();
            break;
        }

        case mysqlParser::DEFAULT:
        {
            enterOuterAlt(_localctx, 2);
            setState(1126);
            match(mysqlParser::DEFAULT);
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Row_formatContext
//------------------------------------------------------------------

mysqlParser::Row_formatContext::Row_formatContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Row_formatContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

tree::TerminalNode *mysqlParser::Row_formatContext::DYNAMIC()
{
    return getToken(mysqlParser::DYNAMIC, 0);
}

tree::TerminalNode *mysqlParser::Row_formatContext::FIXED()
{
    return getToken(mysqlParser::FIXED, 0);
}

tree::TerminalNode *mysqlParser::Row_formatContext::COMPRESSED()
{
    return getToken(mysqlParser::COMPRESSED, 0);
}

tree::TerminalNode *mysqlParser::Row_formatContext::REDUNDANT()
{
    return getToken(mysqlParser::REDUNDANT, 0);
}

tree::TerminalNode *mysqlParser::Row_formatContext::COMPACT()
{
    return getToken(mysqlParser::COMPACT, 0);
}

size_t mysqlParser::Row_formatContext::getRuleIndex() const
{
    return mysqlParser::RuleRow_format;
}

void mysqlParser::Row_formatContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterRow_format(this);
}

void mysqlParser::Row_formatContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitRow_format(this);
}

antlrcpp::Any mysqlParser::Row_formatContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitRow_format(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Row_formatContext *mysqlParser::row_format()
{
    Row_formatContext *_localctx = _tracker.createInstance<Row_formatContext>(_ctx, getState());
    enterRule(_localctx, 118, mysqlParser::RuleRow_format);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1129);
        _la = _input->LA(1);
        if (!(((((_la - 71) & ~0x3fULL) == 0)
               && ((1ULL << (_la - 71)) & ((1ULL << (mysqlParser::COMPACT - 71))
                                           | (1ULL << (mysqlParser::COMPRESSED - 71))
                                           | (1ULL << (mysqlParser::DEFAULT - 71))))
                   != 0)
              || _la == mysqlParser::DYNAMIC

              || _la == mysqlParser::FIXED || _la == mysqlParser::REDUNDANT))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Stats_auto_recalcContext
//------------------------------------------------------------------

mysqlParser::Stats_auto_recalcContext::Stats_auto_recalcContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Stats_auto_recalcContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

mysqlParser::Integer_literalContext *mysqlParser::Stats_auto_recalcContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Stats_auto_recalcContext::getRuleIndex() const
{
    return mysqlParser::RuleStats_auto_recalc;
}

void mysqlParser::Stats_auto_recalcContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterStats_auto_recalc(this);
}

void mysqlParser::Stats_auto_recalcContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitStats_auto_recalc(this);
}

antlrcpp::Any mysqlParser::Stats_auto_recalcContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitStats_auto_recalc(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Stats_auto_recalcContext *mysqlParser::stats_auto_recalc()
{
    Stats_auto_recalcContext *_localctx
        = _tracker.createInstance<Stats_auto_recalcContext>(_ctx, getState());
    enterRule(_localctx, 120, mysqlParser::RuleStats_auto_recalc);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1133);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::DEFAULT:
        {
            enterOuterAlt(_localctx, 1);
            setState(1131);
            match(mysqlParser::DEFAULT);
            break;
        }

        case mysqlParser::INT_NUMBER:
        {
            enterOuterAlt(_localctx, 2);
            setState(1132);
            integer_literal();
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Stats_persistentContext
//------------------------------------------------------------------

mysqlParser::Stats_persistentContext::Stats_persistentContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Stats_persistentContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

mysqlParser::Integer_literalContext *mysqlParser::Stats_persistentContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Stats_persistentContext::getRuleIndex() const
{
    return mysqlParser::RuleStats_persistent;
}

void mysqlParser::Stats_persistentContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterStats_persistent(this);
}

void mysqlParser::Stats_persistentContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitStats_persistent(this);
}

antlrcpp::Any mysqlParser::Stats_persistentContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitStats_persistent(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Stats_persistentContext *mysqlParser::stats_persistent()
{
    Stats_persistentContext *_localctx
        = _tracker.createInstance<Stats_persistentContext>(_ctx, getState());
    enterRule(_localctx, 122, mysqlParser::RuleStats_persistent);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1137);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::DEFAULT:
        {
            enterOuterAlt(_localctx, 1);
            setState(1135);
            match(mysqlParser::DEFAULT);
            break;
        }

        case mysqlParser::INT_NUMBER:
        {
            enterOuterAlt(_localctx, 2);
            setState(1136);
            integer_literal();
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Key_algorithmContext
//------------------------------------------------------------------

mysqlParser::Key_algorithmContext::Key_algorithmContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Key_algorithmContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Key_algorithmContext::getRuleIndex() const
{
    return mysqlParser::RuleKey_algorithm;
}

void mysqlParser::Key_algorithmContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterKey_algorithm(this);
}

void mysqlParser::Key_algorithmContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitKey_algorithm(this);
}

antlrcpp::Any mysqlParser::Key_algorithmContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitKey_algorithm(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Key_algorithmContext *mysqlParser::key_algorithm()
{
    Key_algorithmContext *_localctx
        = _tracker.createInstance<Key_algorithmContext>(_ctx, getState());
    enterRule(_localctx, 124, mysqlParser::RuleKey_algorithm);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1139);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Match_optionContext
//------------------------------------------------------------------

mysqlParser::Match_optionContext::Match_optionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Match_optionContext::FULL()
{
    return getToken(mysqlParser::FULL, 0);
}

tree::TerminalNode *mysqlParser::Match_optionContext::PARTIAL()
{
    return getToken(mysqlParser::PARTIAL, 0);
}

tree::TerminalNode *mysqlParser::Match_optionContext::SIMPLE()
{
    return getToken(mysqlParser::SIMPLE, 0);
}

size_t mysqlParser::Match_optionContext::getRuleIndex() const
{
    return mysqlParser::RuleMatch_option;
}

void mysqlParser::Match_optionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterMatch_option(this);
}

void mysqlParser::Match_optionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitMatch_option(this);
}

antlrcpp::Any mysqlParser::Match_optionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitMatch_option(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Match_optionContext *mysqlParser::match_option()
{
    Match_optionContext *_localctx = _tracker.createInstance<Match_optionContext>(_ctx, getState());
    enterRule(_localctx, 126, mysqlParser::RuleMatch_option);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1141);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::FULL || _la == mysqlParser::PARTIAL
              || _la == mysqlParser::SIMPLE))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- On_delete_optionContext
//------------------------------------------------------------------

mysqlParser::On_delete_optionContext::On_delete_optionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::On_delete_optionContext::RESTRICT()
{
    return getToken(mysqlParser::RESTRICT, 0);
}

tree::TerminalNode *mysqlParser::On_delete_optionContext::CASCADE()
{
    return getToken(mysqlParser::CASCADE, 0);
}

tree::TerminalNode *mysqlParser::On_delete_optionContext::SET()
{
    return getToken(mysqlParser::SET, 0);
}

tree::TerminalNode *mysqlParser::On_delete_optionContext::NULL()
{
    return getToken(mysqlParser::NULL, 0);
}

tree::TerminalNode *mysqlParser::On_delete_optionContext::NO()
{
    return getToken(mysqlParser::NO, 0);
}

tree::TerminalNode *mysqlParser::On_delete_optionContext::ACTION()
{
    return getToken(mysqlParser::ACTION, 0);
}

size_t mysqlParser::On_delete_optionContext::getRuleIndex() const
{
    return mysqlParser::RuleOn_delete_option;
}

void mysqlParser::On_delete_optionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterOn_delete_option(this);
}

void mysqlParser::On_delete_optionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitOn_delete_option(this);
}

antlrcpp::Any mysqlParser::On_delete_optionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitOn_delete_option(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::On_delete_optionContext *mysqlParser::on_delete_option()
{
    On_delete_optionContext *_localctx
        = _tracker.createInstance<On_delete_optionContext>(_ctx, getState());
    enterRule(_localctx, 128, mysqlParser::RuleOn_delete_option);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1149);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::RESTRICT:
        {
            enterOuterAlt(_localctx, 1);
            setState(1143);
            match(mysqlParser::RESTRICT);
            break;
        }

        case mysqlParser::CASCADE:
        {
            enterOuterAlt(_localctx, 2);
            setState(1144);
            match(mysqlParser::CASCADE);
            break;
        }

        case mysqlParser::SET:
        {
            enterOuterAlt(_localctx, 3);
            setState(1145);
            match(mysqlParser::SET);
            setState(1146);
            match(mysqlParser::NULL);
            break;
        }

        case mysqlParser::NO:
        {
            enterOuterAlt(_localctx, 4);
            setState(1147);
            match(mysqlParser::NO);
            setState(1148);
            match(mysqlParser::ACTION);
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- On_update_optionContext
//------------------------------------------------------------------

mysqlParser::On_update_optionContext::On_update_optionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::On_update_optionContext::RESTRICT()
{
    return getToken(mysqlParser::RESTRICT, 0);
}

tree::TerminalNode *mysqlParser::On_update_optionContext::CASCADE()
{
    return getToken(mysqlParser::CASCADE, 0);
}

tree::TerminalNode *mysqlParser::On_update_optionContext::SET()
{
    return getToken(mysqlParser::SET, 0);
}

tree::TerminalNode *mysqlParser::On_update_optionContext::NULL()
{
    return getToken(mysqlParser::NULL, 0);
}

tree::TerminalNode *mysqlParser::On_update_optionContext::NO()
{
    return getToken(mysqlParser::NO, 0);
}

tree::TerminalNode *mysqlParser::On_update_optionContext::ACTION()
{
    return getToken(mysqlParser::ACTION, 0);
}

size_t mysqlParser::On_update_optionContext::getRuleIndex() const
{
    return mysqlParser::RuleOn_update_option;
}

void mysqlParser::On_update_optionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterOn_update_option(this);
}

void mysqlParser::On_update_optionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitOn_update_option(this);
}

antlrcpp::Any mysqlParser::On_update_optionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitOn_update_option(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::On_update_optionContext *mysqlParser::on_update_option()
{
    On_update_optionContext *_localctx
        = _tracker.createInstance<On_update_optionContext>(_ctx, getState());
    enterRule(_localctx, 130, mysqlParser::RuleOn_update_option);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1157);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::RESTRICT:
        {
            enterOuterAlt(_localctx, 1);
            setState(1151);
            match(mysqlParser::RESTRICT);
            break;
        }

        case mysqlParser::CASCADE:
        {
            enterOuterAlt(_localctx, 2);
            setState(1152);
            match(mysqlParser::CASCADE);
            break;
        }

        case mysqlParser::SET:
        {
            enterOuterAlt(_localctx, 3);
            setState(1153);
            match(mysqlParser::SET);
            setState(1154);
            match(mysqlParser::NULL);
            break;
        }

        case mysqlParser::NO:
        {
            enterOuterAlt(_localctx, 4);
            setState(1155);
            match(mysqlParser::NO);
            setState(1156);
            match(mysqlParser::ACTION);
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Column_formatContext
//------------------------------------------------------------------

mysqlParser::Column_formatContext::Column_formatContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Column_formatContext::FIXED()
{
    return getToken(mysqlParser::FIXED, 0);
}

tree::TerminalNode *mysqlParser::Column_formatContext::DYNAMIC()
{
    return getToken(mysqlParser::DYNAMIC, 0);
}

tree::TerminalNode *mysqlParser::Column_formatContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

size_t mysqlParser::Column_formatContext::getRuleIndex() const
{
    return mysqlParser::RuleColumn_format;
}

void mysqlParser::Column_formatContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterColumn_format(this);
}

void mysqlParser::Column_formatContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitColumn_format(this);
}

antlrcpp::Any mysqlParser::Column_formatContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitColumn_format(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Column_formatContext *mysqlParser::column_format()
{
    Column_formatContext *_localctx
        = _tracker.createInstance<Column_formatContext>(_ctx, getState());
    enterRule(_localctx, 132, mysqlParser::RuleColumn_format);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1159);
        _la = _input->LA(1);
        if (!(((((_la - 114) & ~0x3fULL) == 0)
               && ((1ULL << (_la - 114)) & ((1ULL << (mysqlParser::DEFAULT - 114))
                                            | (1ULL << (mysqlParser::DYNAMIC - 114))
                                            | (1ULL << (mysqlParser::FIXED - 114))))
                   != 0)))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Column_storageContext
//------------------------------------------------------------------

mysqlParser::Column_storageContext::Column_storageContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Column_storageContext::DISK()
{
    return getToken(mysqlParser::DISK, 0);
}

tree::TerminalNode *mysqlParser::Column_storageContext::MEMORY()
{
    return getToken(mysqlParser::MEMORY, 0);
}

tree::TerminalNode *mysqlParser::Column_storageContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

size_t mysqlParser::Column_storageContext::getRuleIndex() const
{
    return mysqlParser::RuleColumn_storage;
}

void mysqlParser::Column_storageContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterColumn_storage(this);
}

void mysqlParser::Column_storageContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitColumn_storage(this);
}

antlrcpp::Any mysqlParser::Column_storageContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitColumn_storage(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Column_storageContext *mysqlParser::column_storage()
{
    Column_storageContext *_localctx
        = _tracker.createInstance<Column_storageContext>(_ctx, getState());
    enterRule(_localctx, 134, mysqlParser::RuleColumn_storage);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1161);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::DEFAULT

              || _la == mysqlParser::DISK || _la == mysqlParser::MEMORY))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Integer_typeContext
//------------------------------------------------------------------

mysqlParser::Integer_typeContext::Integer_typeContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Integer_typeContext::TINYINT()
{
    return getToken(mysqlParser::TINYINT, 0);
}

tree::TerminalNode *mysqlParser::Integer_typeContext::SMALLINT()
{
    return getToken(mysqlParser::SMALLINT, 0);
}

tree::TerminalNode *mysqlParser::Integer_typeContext::MEDIUMINT()
{
    return getToken(mysqlParser::MEDIUMINT, 0);
}

tree::TerminalNode *mysqlParser::Integer_typeContext::INT()
{
    return getToken(mysqlParser::INT, 0);
}

tree::TerminalNode *mysqlParser::Integer_typeContext::INTEGER()
{
    return getToken(mysqlParser::INTEGER, 0);
}

tree::TerminalNode *mysqlParser::Integer_typeContext::BIGINT()
{
    return getToken(mysqlParser::BIGINT, 0);
}

size_t mysqlParser::Integer_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleInteger_type;
}

void mysqlParser::Integer_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterInteger_type(this);
}

void mysqlParser::Integer_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitInteger_type(this);
}

antlrcpp::Any mysqlParser::Integer_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitInteger_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Integer_typeContext *mysqlParser::integer_type()
{
    Integer_typeContext *_localctx = _tracker.createInstance<Integer_typeContext>(_ctx, getState());
    enterRule(_localctx, 136, mysqlParser::RuleInteger_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1163);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::BIGINT || _la == mysqlParser::INT

              || _la == mysqlParser::INTEGER || _la == mysqlParser::MEDIUMINT
              || _la == mysqlParser::SMALLINT || _la == mysqlParser::TINYINT))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Real_typeContext
//------------------------------------------------------------------

mysqlParser::Real_typeContext::Real_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Real_typeContext::REAL()
{
    return getToken(mysqlParser::REAL, 0);
}

tree::TerminalNode *mysqlParser::Real_typeContext::DOUBLE()
{
    return getToken(mysqlParser::DOUBLE, 0);
}

tree::TerminalNode *mysqlParser::Real_typeContext::PRECISION()
{
    return getToken(mysqlParser::PRECISION, 0);
}

tree::TerminalNode *mysqlParser::Real_typeContext::FLOAT()
{
    return getToken(mysqlParser::FLOAT, 0);
}

tree::TerminalNode *mysqlParser::Real_typeContext::DECIMAL()
{
    return getToken(mysqlParser::DECIMAL, 0);
}

tree::TerminalNode *mysqlParser::Real_typeContext::NUMERIC()
{
    return getToken(mysqlParser::NUMERIC, 0);
}

size_t mysqlParser::Real_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleReal_type;
}

void mysqlParser::Real_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterReal_type(this);
}

void mysqlParser::Real_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitReal_type(this);
}

antlrcpp::Any mysqlParser::Real_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitReal_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Real_typeContext *mysqlParser::real_type()
{
    Real_typeContext *_localctx = _tracker.createInstance<Real_typeContext>(_ctx, getState());
    enterRule(_localctx, 138, mysqlParser::RuleReal_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1173);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::REAL:
        {
            enterOuterAlt(_localctx, 1);
            setState(1165);
            match(mysqlParser::REAL);
            break;
        }

        case mysqlParser::DOUBLE:
        {
            enterOuterAlt(_localctx, 2);
            setState(1166);
            match(mysqlParser::DOUBLE);
            setState(1168);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::PRECISION)
            {
                setState(1167);
                match(mysqlParser::PRECISION);
            }
            break;
        }

        case mysqlParser::FLOAT:
        {
            enterOuterAlt(_localctx, 3);
            setState(1170);
            match(mysqlParser::FLOAT);
            break;
        }

        case mysqlParser::DECIMAL:
        {
            enterOuterAlt(_localctx, 4);
            setState(1171);
            match(mysqlParser::DECIMAL);
            break;
        }

        case mysqlParser::NUMERIC:
        {
            enterOuterAlt(_localctx, 5);
            setState(1172);
            match(mysqlParser::NUMERIC);
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Text_typeContext
//------------------------------------------------------------------

mysqlParser::Text_typeContext::Text_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Text_typeContext::TINYTEXT()
{
    return getToken(mysqlParser::TINYTEXT, 0);
}

tree::TerminalNode *mysqlParser::Text_typeContext::TEXT()
{
    return getToken(mysqlParser::TEXT, 0);
}

tree::TerminalNode *mysqlParser::Text_typeContext::MEDIUMTEXT()
{
    return getToken(mysqlParser::MEDIUMTEXT, 0);
}

tree::TerminalNode *mysqlParser::Text_typeContext::LONGTEXT()
{
    return getToken(mysqlParser::LONGTEXT, 0);
}

size_t mysqlParser::Text_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleText_type;
}

void mysqlParser::Text_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterText_type(this);
}

void mysqlParser::Text_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitText_type(this);
}

antlrcpp::Any mysqlParser::Text_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitText_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Text_typeContext *mysqlParser::text_type()
{
    Text_typeContext *_localctx = _tracker.createInstance<Text_typeContext>(_ctx, getState());
    enterRule(_localctx, 140, mysqlParser::RuleText_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1175);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::LONGTEXT

              || _la == mysqlParser::MEDIUMTEXT || _la == mysqlParser::TEXT

              || _la == mysqlParser::TINYTEXT))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Blob_typeContext
//------------------------------------------------------------------

mysqlParser::Blob_typeContext::Blob_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Blob_typeContext::TINYBLOB()
{
    return getToken(mysqlParser::TINYBLOB, 0);
}

tree::TerminalNode *mysqlParser::Blob_typeContext::BLOB()
{
    return getToken(mysqlParser::BLOB, 0);
}

tree::TerminalNode *mysqlParser::Blob_typeContext::MEDIUMBLOB()
{
    return getToken(mysqlParser::MEDIUMBLOB, 0);
}

tree::TerminalNode *mysqlParser::Blob_typeContext::LONGBLOB()
{
    return getToken(mysqlParser::LONGBLOB, 0);
}

size_t mysqlParser::Blob_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleBlob_type;
}

void mysqlParser::Blob_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterBlob_type(this);
}

void mysqlParser::Blob_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitBlob_type(this);
}

antlrcpp::Any mysqlParser::Blob_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitBlob_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Blob_typeContext *mysqlParser::blob_type()
{
    Blob_typeContext *_localctx = _tracker.createInstance<Blob_typeContext>(_ctx, getState());
    enterRule(_localctx, 142, mysqlParser::RuleBlob_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1177);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::BLOB || _la == mysqlParser::LONGBLOB

              || _la == mysqlParser::MEDIUMBLOB || _la == mysqlParser::TINYBLOB))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Spatial_typeContext
//------------------------------------------------------------------

mysqlParser::Spatial_typeContext::Spatial_typeContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Spatial_typeContext::GEOMETRY()
{
    return getToken(mysqlParser::GEOMETRY, 0);
}

tree::TerminalNode *mysqlParser::Spatial_typeContext::POINT()
{
    return getToken(mysqlParser::POINT, 0);
}

tree::TerminalNode *mysqlParser::Spatial_typeContext::LINESTRING()
{
    return getToken(mysqlParser::LINESTRING, 0);
}

tree::TerminalNode *mysqlParser::Spatial_typeContext::POLYGON()
{
    return getToken(mysqlParser::POLYGON, 0);
}

tree::TerminalNode *mysqlParser::Spatial_typeContext::MULTIPOINT()
{
    return getToken(mysqlParser::MULTIPOINT, 0);
}

tree::TerminalNode *mysqlParser::Spatial_typeContext::MULTILINESTRING()
{
    return getToken(mysqlParser::MULTILINESTRING, 0);
}

tree::TerminalNode *mysqlParser::Spatial_typeContext::MULTIPOLYGON()
{
    return getToken(mysqlParser::MULTIPOLYGON, 0);
}

tree::TerminalNode *mysqlParser::Spatial_typeContext::GEOMETRYCOLLECTION()
{
    return getToken(mysqlParser::GEOMETRYCOLLECTION, 0);
}

size_t mysqlParser::Spatial_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleSpatial_type;
}

void mysqlParser::Spatial_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterSpatial_type(this);
}

void mysqlParser::Spatial_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitSpatial_type(this);
}

antlrcpp::Any mysqlParser::Spatial_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitSpatial_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Spatial_typeContext *mysqlParser::spatial_type()
{
    Spatial_typeContext *_localctx = _tracker.createInstance<Spatial_typeContext>(_ctx, getState());
    enterRule(_localctx, 144, mysqlParser::RuleSpatial_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1179);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::GEOMETRY

              || _la == mysqlParser::GEOMETRYCOLLECTION || _la == mysqlParser::LINESTRING
              || ((((_la - 336) & ~0x3fULL) == 0)
                  && ((1ULL << (_la - 336)) & ((1ULL << (mysqlParser::MULTILINESTRING - 336))
                                               | (1ULL << (mysqlParser::MULTIPOINT - 336))
                                               | (1ULL << (mysqlParser::MULTIPOLYGON - 336))
                                               | (1ULL << (mysqlParser::POINT - 336))
                                               | (1ULL << (mysqlParser::POLYGON - 336))))
                      != 0)))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Enum_typeContext
//------------------------------------------------------------------

mysqlParser::Enum_typeContext::Enum_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Enum_typeContext::ENUM()
{
    return getToken(mysqlParser::ENUM, 0);
}

tree::TerminalNode *mysqlParser::Enum_typeContext::SET()
{
    return getToken(mysqlParser::SET, 0);
}

size_t mysqlParser::Enum_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleEnum_type;
}

void mysqlParser::Enum_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterEnum_type(this);
}

void mysqlParser::Enum_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitEnum_type(this);
}

antlrcpp::Any mysqlParser::Enum_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitEnum_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Enum_typeContext *mysqlParser::enum_type()
{
    Enum_typeContext *_localctx = _tracker.createInstance<Enum_typeContext>(_ctx, getState());
    enterRule(_localctx, 146, mysqlParser::RuleEnum_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1181);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::ENUM || _la == mysqlParser::SET))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Binary_typeContext
//------------------------------------------------------------------

mysqlParser::Binary_typeContext::Binary_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Binary_typeContext::BIT()
{
    return getToken(mysqlParser::BIT, 0);
}

tree::TerminalNode *mysqlParser::Binary_typeContext::BINARY()
{
    return getToken(mysqlParser::BINARY, 0);
}

tree::TerminalNode *mysqlParser::Binary_typeContext::VARBINARY()
{
    return getToken(mysqlParser::VARBINARY, 0);
}

size_t mysqlParser::Binary_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleBinary_type;
}

void mysqlParser::Binary_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterBinary_type(this);
}

void mysqlParser::Binary_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitBinary_type(this);
}

antlrcpp::Any mysqlParser::Binary_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitBinary_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Binary_typeContext *mysqlParser::binary_type()
{
    Binary_typeContext *_localctx = _tracker.createInstance<Binary_typeContext>(_ctx, getState());
    enterRule(_localctx, 148, mysqlParser::RuleBinary_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1183);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::BINARY

              || _la == mysqlParser::BIT || _la == mysqlParser::VARBINARY))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Char_typeContext
//------------------------------------------------------------------

mysqlParser::Char_typeContext::Char_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Char_typeContext::CHAR()
{
    return getToken(mysqlParser::CHAR, 0);
}

tree::TerminalNode *mysqlParser::Char_typeContext::VARCHAR()
{
    return getToken(mysqlParser::VARCHAR, 0);
}

size_t mysqlParser::Char_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleChar_type;
}

void mysqlParser::Char_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterChar_type(this);
}

void mysqlParser::Char_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitChar_type(this);
}

antlrcpp::Any mysqlParser::Char_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitChar_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Char_typeContext *mysqlParser::char_type()
{
    Char_typeContext *_localctx = _tracker.createInstance<Char_typeContext>(_ctx, getState());
    enterRule(_localctx, 150, mysqlParser::RuleChar_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1185);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::CHAR || _la == mysqlParser::VARCHAR))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Datetime_typeContext
//------------------------------------------------------------------

mysqlParser::Datetime_typeContext::Datetime_typeContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Datetime_typeContext::DATE()
{
    return getToken(mysqlParser::DATE, 0);
}

tree::TerminalNode *mysqlParser::Datetime_typeContext::TIME()
{
    return getToken(mysqlParser::TIME, 0);
}

tree::TerminalNode *mysqlParser::Datetime_typeContext::TIMESTAMP()
{
    return getToken(mysqlParser::TIMESTAMP, 0);
}

tree::TerminalNode *mysqlParser::Datetime_typeContext::DATETIME()
{
    return getToken(mysqlParser::DATETIME, 0);
}

tree::TerminalNode *mysqlParser::Datetime_typeContext::YEAR()
{
    return getToken(mysqlParser::YEAR, 0);
}

size_t mysqlParser::Datetime_typeContext::getRuleIndex() const
{
    return mysqlParser::RuleDatetime_type;
}

void mysqlParser::Datetime_typeContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterDatetime_type(this);
}

void mysqlParser::Datetime_typeContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitDatetime_type(this);
}

antlrcpp::Any mysqlParser::Datetime_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitDatetime_type(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Datetime_typeContext *mysqlParser::datetime_type()
{
    Datetime_typeContext *_localctx
        = _tracker.createInstance<Datetime_typeContext>(_ctx, getState());
    enterRule(_localctx, 152, mysqlParser::RuleDatetime_type);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1187);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::DATE

              || _la == mysqlParser::DATETIME || _la == mysqlParser::TIME

              || _la == mysqlParser::TIMESTAMP || _la == mysqlParser::YEAR))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- On_update_setContext
//------------------------------------------------------------------

mysqlParser::On_update_setContext::On_update_setContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::LiteralContext *mysqlParser::On_update_setContext::literal()
{
    return getRuleContext<mysqlParser::LiteralContext>(0);
}

size_t mysqlParser::On_update_setContext::getRuleIndex() const
{
    return mysqlParser::RuleOn_update_set;
}

void mysqlParser::On_update_setContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterOn_update_set(this);
}

void mysqlParser::On_update_setContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitOn_update_set(this);
}

antlrcpp::Any mysqlParser::On_update_setContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitOn_update_set(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::On_update_setContext *mysqlParser::on_update_set()
{
    On_update_setContext *_localctx
        = _tracker.createInstance<On_update_setContext>(_ctx, getState());
    enterRule(_localctx, 154, mysqlParser::RuleOn_update_set);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1189);
        literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Default_valueContext
//------------------------------------------------------------------

mysqlParser::Default_valueContext::Default_valueContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::LiteralContext *mysqlParser::Default_valueContext::literal()
{
    return getRuleContext<mysqlParser::LiteralContext>(0);
}

size_t mysqlParser::Default_valueContext::getRuleIndex() const
{
    return mysqlParser::RuleDefault_value;
}

void mysqlParser::Default_valueContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterDefault_value(this);
}

void mysqlParser::Default_valueContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitDefault_value(this);
}

antlrcpp::Any mysqlParser::Default_valueContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitDefault_value(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Default_valueContext *mysqlParser::default_value()
{
    Default_valueContext *_localctx
        = _tracker.createInstance<Default_valueContext>(_ctx, getState());
    enterRule(_localctx, 156, mysqlParser::RuleDefault_value);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1191);
        literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CommentContext
//------------------------------------------------------------------

mysqlParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::String_literalContext *mysqlParser::CommentContext::string_literal()
{
    return getRuleContext<mysqlParser::String_literalContext>(0);
}

size_t mysqlParser::CommentContext::getRuleIndex() const
{
    return mysqlParser::RuleComment;
}

void mysqlParser::CommentContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterComment(this);
}

void mysqlParser::CommentContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitComment(this);
}

antlrcpp::Any mysqlParser::CommentContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitComment(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::CommentContext *mysqlParser::comment()
{
    CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
    enterRule(_localctx, 158, mysqlParser::RuleComment);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1193);
        string_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ConnectionContext
//------------------------------------------------------------------

mysqlParser::ConnectionContext::ConnectionContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::String_literalContext *mysqlParser::ConnectionContext::string_literal()
{
    return getRuleContext<mysqlParser::String_literalContext>(0);
}

size_t mysqlParser::ConnectionContext::getRuleIndex() const
{
    return mysqlParser::RuleConnection;
}

void mysqlParser::ConnectionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterConnection(this);
}

void mysqlParser::ConnectionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitConnection(this);
}

antlrcpp::Any mysqlParser::ConnectionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitConnection(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::ConnectionContext *mysqlParser::connection()
{
    ConnectionContext *_localctx = _tracker.createInstance<ConnectionContext>(_ctx, getState());
    enterRule(_localctx, 160, mysqlParser::RuleConnection);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1195);
        string_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- PasswordContext
//------------------------------------------------------------------

mysqlParser::PasswordContext::PasswordContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::String_literalContext *mysqlParser::PasswordContext::string_literal()
{
    return getRuleContext<mysqlParser::String_literalContext>(0);
}

size_t mysqlParser::PasswordContext::getRuleIndex() const
{
    return mysqlParser::RulePassword;
}

void mysqlParser::PasswordContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPassword(this);
}

void mysqlParser::PasswordContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPassword(this);
}

antlrcpp::Any mysqlParser::PasswordContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPassword(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::PasswordContext *mysqlParser::password()
{
    PasswordContext *_localctx = _tracker.createInstance<PasswordContext>(_ctx, getState());
    enterRule(_localctx, 162, mysqlParser::RulePassword);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1197);
        string_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Data_directoryContext
//------------------------------------------------------------------

mysqlParser::Data_directoryContext::Data_directoryContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::String_literalContext *mysqlParser::Data_directoryContext::string_literal()
{
    return getRuleContext<mysqlParser::String_literalContext>(0);
}

size_t mysqlParser::Data_directoryContext::getRuleIndex() const
{
    return mysqlParser::RuleData_directory;
}

void mysqlParser::Data_directoryContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterData_directory(this);
}

void mysqlParser::Data_directoryContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitData_directory(this);
}

antlrcpp::Any mysqlParser::Data_directoryContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitData_directory(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Data_directoryContext *mysqlParser::data_directory()
{
    Data_directoryContext *_localctx
        = _tracker.createInstance<Data_directoryContext>(_ctx, getState());
    enterRule(_localctx, 164, mysqlParser::RuleData_directory);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1199);
        string_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Index_directoryContext
//------------------------------------------------------------------

mysqlParser::Index_directoryContext::Index_directoryContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::String_literalContext *mysqlParser::Index_directoryContext::string_literal()
{
    return getRuleContext<mysqlParser::String_literalContext>(0);
}

size_t mysqlParser::Index_directoryContext::getRuleIndex() const
{
    return mysqlParser::RuleIndex_directory;
}

void mysqlParser::Index_directoryContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIndex_directory(this);
}

void mysqlParser::Index_directoryContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIndex_directory(this);
}

antlrcpp::Any mysqlParser::Index_directoryContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIndex_directory(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Index_directoryContext *mysqlParser::index_directory()
{
    Index_directoryContext *_localctx
        = _tracker.createInstance<Index_directoryContext>(_ctx, getState());
    enterRule(_localctx, 166, mysqlParser::RuleIndex_directory);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1201);
        string_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- As_expressionContext
//------------------------------------------------------------------

mysqlParser::As_expressionContext::As_expressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::ExpressionContext *mysqlParser::As_expressionContext::expression()
{
    return getRuleContext<mysqlParser::ExpressionContext>(0);
}

size_t mysqlParser::As_expressionContext::getRuleIndex() const
{
    return mysqlParser::RuleAs_expression;
}

void mysqlParser::As_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterAs_expression(this);
}

void mysqlParser::As_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitAs_expression(this);
}

antlrcpp::Any mysqlParser::As_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitAs_expression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::As_expressionContext *mysqlParser::as_expression()
{
    As_expressionContext *_localctx
        = _tracker.createInstance<As_expressionContext>(_ctx, getState());
    enterRule(_localctx, 168, mysqlParser::RuleAs_expression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1203);
        expression();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Query_expressionContext
//------------------------------------------------------------------

mysqlParser::Query_expressionContext::Query_expressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::ExpressionContext *mysqlParser::Query_expressionContext::expression()
{
    return getRuleContext<mysqlParser::ExpressionContext>(0);
}

size_t mysqlParser::Query_expressionContext::getRuleIndex() const
{
    return mysqlParser::RuleQuery_expression;
}

void mysqlParser::Query_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterQuery_expression(this);
}

void mysqlParser::Query_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitQuery_expression(this);
}

antlrcpp::Any mysqlParser::Query_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitQuery_expression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Query_expressionContext *mysqlParser::query_expression()
{
    Query_expressionContext *_localctx
        = _tracker.createInstance<Query_expressionContext>(_ctx, getState());
    enterRule(_localctx, 170, mysqlParser::RuleQuery_expression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1205);
        expression();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Check_expressionContext
//------------------------------------------------------------------

mysqlParser::Check_expressionContext::Check_expressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::ExpressionContext *mysqlParser::Check_expressionContext::expression()
{
    return getRuleContext<mysqlParser::ExpressionContext>(0);
}

size_t mysqlParser::Check_expressionContext::getRuleIndex() const
{
    return mysqlParser::RuleCheck_expression;
}

void mysqlParser::Check_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCheck_expression(this);
}

void mysqlParser::Check_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCheck_expression(this);
}

antlrcpp::Any mysqlParser::Check_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCheck_expression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Check_expressionContext *mysqlParser::check_expression()
{
    Check_expressionContext *_localctx
        = _tracker.createInstance<Check_expressionContext>(_ctx, getState());
    enterRule(_localctx, 172, mysqlParser::RuleCheck_expression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1207);
        expression();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Hash_expressionContext
//------------------------------------------------------------------

mysqlParser::Hash_expressionContext::Hash_expressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::ExpressionContext *mysqlParser::Hash_expressionContext::expression()
{
    return getRuleContext<mysqlParser::ExpressionContext>(0);
}

size_t mysqlParser::Hash_expressionContext::getRuleIndex() const
{
    return mysqlParser::RuleHash_expression;
}

void mysqlParser::Hash_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterHash_expression(this);
}

void mysqlParser::Hash_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitHash_expression(this);
}

antlrcpp::Any mysqlParser::Hash_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitHash_expression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Hash_expressionContext *mysqlParser::hash_expression()
{
    Hash_expressionContext *_localctx
        = _tracker.createInstance<Hash_expressionContext>(_ctx, getState());
    enterRule(_localctx, 174, mysqlParser::RuleHash_expression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1209);
        expression();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Range_expressionContext
//------------------------------------------------------------------

mysqlParser::Range_expressionContext::Range_expressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::ExpressionContext *mysqlParser::Range_expressionContext::expression()
{
    return getRuleContext<mysqlParser::ExpressionContext>(0);
}

size_t mysqlParser::Range_expressionContext::getRuleIndex() const
{
    return mysqlParser::RuleRange_expression;
}

void mysqlParser::Range_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterRange_expression(this);
}

void mysqlParser::Range_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitRange_expression(this);
}

antlrcpp::Any mysqlParser::Range_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitRange_expression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Range_expressionContext *mysqlParser::range_expression()
{
    Range_expressionContext *_localctx
        = _tracker.createInstance<Range_expressionContext>(_ctx, getState());
    enterRule(_localctx, 176, mysqlParser::RuleRange_expression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1211);
        expression();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- List_expressionContext
//------------------------------------------------------------------

mysqlParser::List_expressionContext::List_expressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::ExpressionContext *mysqlParser::List_expressionContext::expression()
{
    return getRuleContext<mysqlParser::ExpressionContext>(0);
}

size_t mysqlParser::List_expressionContext::getRuleIndex() const
{
    return mysqlParser::RuleList_expression;
}

void mysqlParser::List_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterList_expression(this);
}

void mysqlParser::List_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitList_expression(this);
}

antlrcpp::Any mysqlParser::List_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitList_expression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::List_expressionContext *mysqlParser::list_expression()
{
    List_expressionContext *_localctx
        = _tracker.createInstance<List_expressionContext>(_ctx, getState());
    enterRule(_localctx, 178, mysqlParser::RuleList_expression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1213);
        expression();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Less_than_expressionContext
//------------------------------------------------------------------

mysqlParser::Less_than_expressionContext::Less_than_expressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::ExpressionContext *mysqlParser::Less_than_expressionContext::expression()
{
    return getRuleContext<mysqlParser::ExpressionContext>(0);
}

size_t mysqlParser::Less_than_expressionContext::getRuleIndex() const
{
    return mysqlParser::RuleLess_than_expression;
}

void mysqlParser::Less_than_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterLess_than_expression(this);
}

void mysqlParser::Less_than_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitLess_than_expression(this);
}

antlrcpp::Any mysqlParser::Less_than_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitLess_than_expression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Less_than_expressionContext *mysqlParser::less_than_expression()
{
    Less_than_expressionContext *_localctx
        = _tracker.createInstance<Less_than_expressionContext>(_ctx, getState());
    enterRule(_localctx, 180, mysqlParser::RuleLess_than_expression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1215);
        expression();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ExpressionContext
//------------------------------------------------------------------

mysqlParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::ExpressionContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

mysqlParser::LiteralContext *mysqlParser::ExpressionContext::literal()
{
    return getRuleContext<mysqlParser::LiteralContext>(0);
}

tree::TerminalNode *mysqlParser::ExpressionContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

size_t mysqlParser::ExpressionContext::getRuleIndex() const
{
    return mysqlParser::RuleExpression;
}

void mysqlParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterExpression(this);
}

void mysqlParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitExpression(this);
}

antlrcpp::Any mysqlParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitExpression(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::ExpressionContext *mysqlParser::expression()
{
    ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
    enterRule(_localctx, 182, mysqlParser::RuleExpression);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1217);
        match(mysqlParser::LPAREN);
        setState(1218);
        literal();
        setState(1219);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- SymbolContext ------------------------------------------------------------------

mysqlParser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::SymbolContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::SymbolContext::getRuleIndex() const
{
    return mysqlParser::RuleSymbol;
}

void mysqlParser::SymbolContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterSymbol(this);
}

void mysqlParser::SymbolContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitSymbol(this);
}

antlrcpp::Any mysqlParser::SymbolContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitSymbol(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::SymbolContext *mysqlParser::symbol()
{
    SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
    enterRule(_localctx, 184, mysqlParser::RuleSymbol);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1221);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Engine_nameContext
//------------------------------------------------------------------

mysqlParser::Engine_nameContext::Engine_nameContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Engine_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Engine_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleEngine_name;
}

void mysqlParser::Engine_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterEngine_name(this);
}

void mysqlParser::Engine_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitEngine_name(this);
}

antlrcpp::Any mysqlParser::Engine_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitEngine_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Engine_nameContext *mysqlParser::engine_name()
{
    Engine_nameContext *_localctx = _tracker.createInstance<Engine_nameContext>(_ctx, getState());
    enterRule(_localctx, 186, mysqlParser::RuleEngine_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1223);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Old_table_nameContext
//------------------------------------------------------------------

mysqlParser::Old_table_nameContext::Old_table_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Table_nameContext *mysqlParser::Old_table_nameContext::table_name()
{
    return getRuleContext<mysqlParser::Table_nameContext>(0);
}

size_t mysqlParser::Old_table_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleOld_table_name;
}

void mysqlParser::Old_table_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterOld_table_name(this);
}

void mysqlParser::Old_table_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitOld_table_name(this);
}

antlrcpp::Any mysqlParser::Old_table_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitOld_table_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Old_table_nameContext *mysqlParser::old_table_name()
{
    Old_table_nameContext *_localctx
        = _tracker.createInstance<Old_table_nameContext>(_ctx, getState());
    enterRule(_localctx, 188, mysqlParser::RuleOld_table_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1225);
        table_name();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Column_nameContext
//------------------------------------------------------------------

mysqlParser::Column_nameContext::Column_nameContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Column_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Column_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleColumn_name;
}

void mysqlParser::Column_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterColumn_name(this);
}

void mysqlParser::Column_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitColumn_name(this);
}

antlrcpp::Any mysqlParser::Column_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitColumn_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Column_nameContext *mysqlParser::column_name()
{
    Column_nameContext *_localctx = _tracker.createInstance<Column_nameContext>(_ctx, getState());
    enterRule(_localctx, 190, mysqlParser::RuleColumn_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1227);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Index_nameContext
//------------------------------------------------------------------

mysqlParser::Index_nameContext::Index_nameContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Index_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Index_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleIndex_name;
}

void mysqlParser::Index_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIndex_name(this);
}

void mysqlParser::Index_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIndex_name(this);
}

antlrcpp::Any mysqlParser::Index_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIndex_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Index_nameContext *mysqlParser::index_name()
{
    Index_nameContext *_localctx = _tracker.createInstance<Index_nameContext>(_ctx, getState());
    enterRule(_localctx, 192, mysqlParser::RuleIndex_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1229);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Tablespace_nameContext
//------------------------------------------------------------------

mysqlParser::Tablespace_nameContext::Tablespace_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Tablespace_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Tablespace_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleTablespace_name;
}

void mysqlParser::Tablespace_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterTablespace_name(this);
}

void mysqlParser::Tablespace_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitTablespace_name(this);
}

antlrcpp::Any mysqlParser::Tablespace_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitTablespace_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Tablespace_nameContext *mysqlParser::tablespace_name()
{
    Tablespace_nameContext *_localctx
        = _tracker.createInstance<Tablespace_nameContext>(_ctx, getState());
    enterRule(_localctx, 194, mysqlParser::RuleTablespace_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1231);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Table_nameContext
//------------------------------------------------------------------

mysqlParser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Table_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

mysqlParser::Database_nameContext *mysqlParser::Table_nameContext::database_name()
{
    return getRuleContext<mysqlParser::Database_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Table_nameContext::PERIOD()
{
    return getToken(mysqlParser::PERIOD, 0);
}

size_t mysqlParser::Table_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleTable_name;
}

void mysqlParser::Table_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterTable_name(this);
}

void mysqlParser::Table_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitTable_name(this);
}

antlrcpp::Any mysqlParser::Table_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitTable_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Table_nameContext *mysqlParser::table_name()
{
    Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
    enterRule(_localctx, 196, mysqlParser::RuleTable_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1236);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx))
        {
        case 1:
        {
            setState(1233);
            database_name();
            setState(1234);
            match(mysqlParser::PERIOD);
            break;
        }
        }
        setState(1238);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Database_nameContext
//------------------------------------------------------------------

mysqlParser::Database_nameContext::Database_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Database_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Database_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleDatabase_name;
}

void mysqlParser::Database_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterDatabase_name(this);
}

void mysqlParser::Database_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitDatabase_name(this);
}

antlrcpp::Any mysqlParser::Database_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitDatabase_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Database_nameContext *mysqlParser::database_name()
{
    Database_nameContext *_localctx
        = _tracker.createInstance<Database_nameContext>(_ctx, getState());
    enterRule(_localctx, 198, mysqlParser::RuleDatabase_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1240);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Parser_nameContext
//------------------------------------------------------------------

mysqlParser::Parser_nameContext::Parser_nameContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Parser_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Parser_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleParser_name;
}

void mysqlParser::Parser_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterParser_name(this);
}

void mysqlParser::Parser_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitParser_name(this);
}

antlrcpp::Any mysqlParser::Parser_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitParser_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Parser_nameContext *mysqlParser::parser_name()
{
    Parser_nameContext *_localctx = _tracker.createInstance<Parser_nameContext>(_ctx, getState());
    enterRule(_localctx, 200, mysqlParser::RuleParser_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1242);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Charset_nameContext
//------------------------------------------------------------------

mysqlParser::Charset_nameContext::Charset_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Charset_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Charset_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleCharset_name;
}

void mysqlParser::Charset_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCharset_name(this);
}

void mysqlParser::Charset_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCharset_name(this);
}

antlrcpp::Any mysqlParser::Charset_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCharset_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Charset_nameContext *mysqlParser::charset_name()
{
    Charset_nameContext *_localctx = _tracker.createInstance<Charset_nameContext>(_ctx, getState());
    enterRule(_localctx, 202, mysqlParser::RuleCharset_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1244);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Collation_nameContext
//------------------------------------------------------------------

mysqlParser::Collation_nameContext::Collation_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Collation_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Collation_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleCollation_name;
}

void mysqlParser::Collation_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterCollation_name(this);
}

void mysqlParser::Collation_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitCollation_name(this);
}

antlrcpp::Any mysqlParser::Collation_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitCollation_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Collation_nameContext *mysqlParser::collation_name()
{
    Collation_nameContext *_localctx
        = _tracker.createInstance<Collation_nameContext>(_ctx, getState());
    enterRule(_localctx, 204, mysqlParser::RuleCollation_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1246);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_nameContext
//------------------------------------------------------------------

mysqlParser::Partition_nameContext::Partition_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Partition_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Partition_nameContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_name;
}

void mysqlParser::Partition_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_name(this);
}

void mysqlParser::Partition_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_name(this);
}

antlrcpp::Any mysqlParser::Partition_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_nameContext *mysqlParser::partition_name()
{
    Partition_nameContext *_localctx
        = _tracker.createInstance<Partition_nameContext>(_ctx, getState());
    enterRule(_localctx, 206, mysqlParser::RulePartition_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1248);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Logical_nameContext
//------------------------------------------------------------------

mysqlParser::Logical_nameContext::Logical_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::IdentifierContext *mysqlParser::Logical_nameContext::identifier()
{
    return getRuleContext<mysqlParser::IdentifierContext>(0);
}

size_t mysqlParser::Logical_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleLogical_name;
}

void mysqlParser::Logical_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterLogical_name(this);
}

void mysqlParser::Logical_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitLogical_name(this);
}

antlrcpp::Any mysqlParser::Logical_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitLogical_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Logical_nameContext *mysqlParser::logical_name()
{
    Logical_nameContext *_localctx = _tracker.createInstance<Logical_nameContext>(_ctx, getState());
    enterRule(_localctx, 208, mysqlParser::RuleLogical_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1250);
        identifier();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- LiteralContext
//------------------------------------------------------------------

mysqlParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::LiteralContext::NULL()
{
    return getToken(mysqlParser::NULL, 0);
}

mysqlParser::Bool_literalContext *mysqlParser::LiteralContext::bool_literal()
{
    return getRuleContext<mysqlParser::Bool_literalContext>(0);
}

mysqlParser::Float_literalContext *mysqlParser::LiteralContext::float_literal()
{
    return getRuleContext<mysqlParser::Float_literalContext>(0);
}

mysqlParser::Integer_literalContext *mysqlParser::LiteralContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

mysqlParser::String_literalContext *mysqlParser::LiteralContext::string_literal()
{
    return getRuleContext<mysqlParser::String_literalContext>(0);
}

mysqlParser::Datetime_literalContext *mysqlParser::LiteralContext::datetime_literal()
{
    return getRuleContext<mysqlParser::Datetime_literalContext>(0);
}

size_t mysqlParser::LiteralContext::getRuleIndex() const
{
    return mysqlParser::RuleLiteral;
}

void mysqlParser::LiteralContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterLiteral(this);
}

void mysqlParser::LiteralContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitLiteral(this);
}

antlrcpp::Any mysqlParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitLiteral(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::LiteralContext *mysqlParser::literal()
{
    LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
    enterRule(_localctx, 210, mysqlParser::RuleLiteral);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1258);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::NULL:
        {
            enterOuterAlt(_localctx, 1);
            setState(1252);
            match(mysqlParser::NULL);
            break;
        }

        case mysqlParser::FALSE:
        case mysqlParser::TRUE:
        {
            enterOuterAlt(_localctx, 2);
            setState(1253);
            bool_literal();
            break;
        }

        case mysqlParser::FLOAT_NUMBER:
        {
            enterOuterAlt(_localctx, 3);
            setState(1254);
            float_literal();
            break;
        }

        case mysqlParser::INT_NUMBER:
        {
            enterOuterAlt(_localctx, 4);
            setState(1255);
            integer_literal();
            break;
        }

        case mysqlParser::SQUOTED_STRING:
        case mysqlParser::DQUOTED_STRING:
        {
            enterOuterAlt(_localctx, 5);
            setState(1256);
            string_literal();
            break;
        }

        case mysqlParser::CURRENT_DATE:
        case mysqlParser::CURRENT_TIME:
        case mysqlParser::CURRENT_TIMESTAMP:
        {
            enterOuterAlt(_localctx, 6);
            setState(1257);
            datetime_literal();
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- IdentifierContext
//------------------------------------------------------------------

mysqlParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::IdentifierContext::ID()
{
    return getToken(mysqlParser::ID, 0);
}

tree::TerminalNode *mysqlParser::IdentifierContext::BQUOTED_STRING()
{
    return getToken(mysqlParser::BQUOTED_STRING, 0);
}

size_t mysqlParser::IdentifierContext::getRuleIndex() const
{
    return mysqlParser::RuleIdentifier;
}

void mysqlParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterIdentifier(this);
}

void mysqlParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitIdentifier(this);
}

antlrcpp::Any mysqlParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitIdentifier(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::IdentifierContext *mysqlParser::identifier()
{
    IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
    enterRule(_localctx, 212, mysqlParser::RuleIdentifier);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1260);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::ID

              || _la == mysqlParser::BQUOTED_STRING))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Bool_literalContext
//------------------------------------------------------------------

mysqlParser::Bool_literalContext::Bool_literalContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Bool_literalContext::TRUE()
{
    return getToken(mysqlParser::TRUE, 0);
}

tree::TerminalNode *mysqlParser::Bool_literalContext::FALSE()
{
    return getToken(mysqlParser::FALSE, 0);
}

size_t mysqlParser::Bool_literalContext::getRuleIndex() const
{
    return mysqlParser::RuleBool_literal;
}

void mysqlParser::Bool_literalContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterBool_literal(this);
}

void mysqlParser::Bool_literalContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitBool_literal(this);
}

antlrcpp::Any mysqlParser::Bool_literalContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitBool_literal(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Bool_literalContext *mysqlParser::bool_literal()
{
    Bool_literalContext *_localctx = _tracker.createInstance<Bool_literalContext>(_ctx, getState());
    enterRule(_localctx, 214, mysqlParser::RuleBool_literal);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1262);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::FALSE || _la == mysqlParser::TRUE))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Float_literalContext
//------------------------------------------------------------------

mysqlParser::Float_literalContext::Float_literalContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Float_literalContext::FLOAT_NUMBER()
{
    return getToken(mysqlParser::FLOAT_NUMBER, 0);
}

size_t mysqlParser::Float_literalContext::getRuleIndex() const
{
    return mysqlParser::RuleFloat_literal;
}

void mysqlParser::Float_literalContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterFloat_literal(this);
}

void mysqlParser::Float_literalContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitFloat_literal(this);
}

antlrcpp::Any mysqlParser::Float_literalContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitFloat_literal(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Float_literalContext *mysqlParser::float_literal()
{
    Float_literalContext *_localctx
        = _tracker.createInstance<Float_literalContext>(_ctx, getState());
    enterRule(_localctx, 216, mysqlParser::RuleFloat_literal);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1264);
        match(mysqlParser::FLOAT_NUMBER);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Integer_literalContext
//------------------------------------------------------------------

mysqlParser::Integer_literalContext::Integer_literalContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Integer_literalContext::INT_NUMBER()
{
    return getToken(mysqlParser::INT_NUMBER, 0);
}

size_t mysqlParser::Integer_literalContext::getRuleIndex() const
{
    return mysqlParser::RuleInteger_literal;
}

void mysqlParser::Integer_literalContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterInteger_literal(this);
}

void mysqlParser::Integer_literalContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitInteger_literal(this);
}

antlrcpp::Any mysqlParser::Integer_literalContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitInteger_literal(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Integer_literalContext *mysqlParser::integer_literal()
{
    Integer_literalContext *_localctx
        = _tracker.createInstance<Integer_literalContext>(_ctx, getState());
    enterRule(_localctx, 218, mysqlParser::RuleInteger_literal);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1266);
        match(mysqlParser::INT_NUMBER);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- String_literalContext
//------------------------------------------------------------------

mysqlParser::String_literalContext::String_literalContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::String_literalContext::SQUOTED_STRING()
{
    return getToken(mysqlParser::SQUOTED_STRING, 0);
}

tree::TerminalNode *mysqlParser::String_literalContext::DQUOTED_STRING()
{
    return getToken(mysqlParser::DQUOTED_STRING, 0);
}

size_t mysqlParser::String_literalContext::getRuleIndex() const
{
    return mysqlParser::RuleString_literal;
}

void mysqlParser::String_literalContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterString_literal(this);
}

void mysqlParser::String_literalContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitString_literal(this);
}

antlrcpp::Any mysqlParser::String_literalContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitString_literal(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::String_literalContext *mysqlParser::string_literal()
{
    String_literalContext *_localctx
        = _tracker.createInstance<String_literalContext>(_ctx, getState());
    enterRule(_localctx, 220, mysqlParser::RuleString_literal);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1268);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::SQUOTED_STRING

              || _la == mysqlParser::DQUOTED_STRING))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Datetime_literalContext
//------------------------------------------------------------------

mysqlParser::Datetime_literalContext::Datetime_literalContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Datetime_literalContext::CURRENT_DATE()
{
    return getToken(mysqlParser::CURRENT_DATE, 0);
}

tree::TerminalNode *mysqlParser::Datetime_literalContext::CURRENT_TIME()
{
    return getToken(mysqlParser::CURRENT_TIME, 0);
}

tree::TerminalNode *mysqlParser::Datetime_literalContext::CURRENT_TIMESTAMP()
{
    return getToken(mysqlParser::CURRENT_TIMESTAMP, 0);
}

size_t mysqlParser::Datetime_literalContext::getRuleIndex() const
{
    return mysqlParser::RuleDatetime_literal;
}

void mysqlParser::Datetime_literalContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterDatetime_literal(this);
}

void mysqlParser::Datetime_literalContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitDatetime_literal(this);
}

antlrcpp::Any mysqlParser::Datetime_literalContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitDatetime_literal(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Datetime_literalContext *mysqlParser::datetime_literal()
{
    Datetime_literalContext *_localctx
        = _tracker.createInstance<Datetime_literalContext>(_ctx, getState());
    enterRule(_localctx, 222, mysqlParser::RuleDatetime_literal);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1270);
        _la = _input->LA(1);
        if (!(((((_la - 93) & ~0x3fULL) == 0)
               && ((1ULL << (_la - 93)) & ((1ULL << (mysqlParser::CURRENT_DATE - 93))
                                           | (1ULL << (mysqlParser::CURRENT_TIME - 93))
                                           | (1ULL << (mysqlParser::CURRENT_TIMESTAMP - 93))))
                   != 0)))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Alter_tableContext
//------------------------------------------------------------------

mysqlParser::Alter_tableContext::Alter_tableContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Alter_tableContext::ALTER()
{
    return getToken(mysqlParser::ALTER, 0);
}

tree::TerminalNode *mysqlParser::Alter_tableContext::TABLE()
{
    return getToken(mysqlParser::TABLE, 0);
}

mysqlParser::Table_nameContext *mysqlParser::Alter_tableContext::table_name()
{
    return getRuleContext<mysqlParser::Table_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_tableContext::IGNORE()
{
    return getToken(mysqlParser::IGNORE, 0);
}

mysqlParser::Alter_specification_listContext *mysqlParser::Alter_tableContext::
    alter_specification_list()
{
    return getRuleContext<mysqlParser::Alter_specification_listContext>(0);
}

mysqlParser::Partition_specificationContext *mysqlParser::Alter_tableContext::
    partition_specification()
{
    return getRuleContext<mysqlParser::Partition_specificationContext>(0);
}

size_t mysqlParser::Alter_tableContext::getRuleIndex() const
{
    return mysqlParser::RuleAlter_table;
}

void mysqlParser::Alter_tableContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterAlter_table(this);
}

void mysqlParser::Alter_tableContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitAlter_table(this);
}

antlrcpp::Any mysqlParser::Alter_tableContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitAlter_table(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Alter_tableContext *mysqlParser::alter_table()
{
    Alter_tableContext *_localctx = _tracker.createInstance<Alter_tableContext>(_ctx, getState());
    enterRule(_localctx, 224, mysqlParser::RuleAlter_table);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1272);
        match(mysqlParser::ALTER);
        setState(1274);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::IGNORE)
        {
            setState(1273);
            match(mysqlParser::IGNORE);
        }
        setState(1276);
        match(mysqlParser::TABLE);
        setState(1277);
        table_name();
        setState(1279);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0)
             && ((1ULL << _la)
                 & ((1ULL << mysqlParser::ADD) | (1ULL << mysqlParser::ALGORITHM)
                    | (1ULL << mysqlParser::ALTER) | (1ULL << mysqlParser::ANALYZE)
                    | (1ULL << mysqlParser::AUTO_INCREMENT) | (1ULL << mysqlParser::AVG_ROW_LENGTH)
                    | (1ULL << mysqlParser::CHANGE) | (1ULL << mysqlParser::CHARACTER)
                    | (1ULL << mysqlParser::CHARSET) | (1ULL << mysqlParser::CHECK)
                    | (1ULL << mysqlParser::CHECKSUM) | (1ULL << mysqlParser::COALESCE)
                    | (1ULL << mysqlParser::COLLATE)))
                 != 0)
            || ((((_la - 68) & ~0x3fULL) == 0)
                && ((1ULL << (_la - 68))
                    & ((1ULL << (mysqlParser::COMMENT - 68))
                       | (1ULL << (mysqlParser::COMPRESSION - 68))
                       | (1ULL << (mysqlParser::CONNECTION - 68))
                       | (1ULL << (mysqlParser::CONVERT - 68)) | (1ULL << (mysqlParser::DATA - 68))
                       | (1ULL << (mysqlParser::DEFAULT - 68))
                       | (1ULL << (mysqlParser::DELAY_KEY_WRITE - 68))
                       | (1ULL << (mysqlParser::DISABLE - 68))
                       | (1ULL << (mysqlParser::DISCARD - 68))))
                    != 0)
            || ((((_la - 134) & ~0x3fULL) == 0)
                && ((1ULL << (_la - 134))
                    & ((1ULL << (mysqlParser::DROP - 134)) | (1ULL << (mysqlParser::ENABLE - 134))
                       | (1ULL << (mysqlParser::ENCRYPTION - 134))
                       | (1ULL << (mysqlParser::ENGINE - 134))
                       | (1ULL << (mysqlParser::EXCHANGE - 134))
                       | (1ULL << (mysqlParser::FORCE - 134))))
                    != 0)
            || ((((_la - 218) & ~0x3fULL) == 0)
                && ((1ULL << (_la - 218))
                    & ((1ULL << (mysqlParser::IMPORT - 218)) | (1ULL << (mysqlParser::INDEX - 218))
                       | (1ULL << (mysqlParser::INSERT_METHOD - 218))
                       | (1ULL << (mysqlParser::KEY_BLOCK_SIZE - 218))
                       | (1ULL << (mysqlParser::LOCK - 218))))
                    != 0)
            || ((((_la - 312) & ~0x3fULL) == 0)
                && ((1ULL << (_la - 312)) & ((1ULL << (mysqlParser::MAX_ROWS - 312))
                                             | (1ULL << (mysqlParser::MIN_ROWS - 312))
                                             | (1ULL << (mysqlParser::MODIFY - 312))
                                             | (1ULL << (mysqlParser::OPTIMIZE - 312))
                                             | (1ULL << (mysqlParser::ORDER - 312))))
                    != 0)
            || ((((_la - 379) & ~0x3fULL) == 0)
                && ((1ULL << (_la - 379)) & ((1ULL << (mysqlParser::PACK_KEYS - 379))
                                             | (1ULL << (mysqlParser::PASSWORD - 379))
                                             | (1ULL << (mysqlParser::REBUILD - 379))
                                             | (1ULL << (mysqlParser::REMOVE - 379))
                                             | (1ULL << (mysqlParser::RENAME - 379))
                                             | (1ULL << (mysqlParser::REORGANIZE - 379))
                                             | (1ULL << (mysqlParser::REPAIR - 379))))
                    != 0)
            || _la == mysqlParser::ROW_FORMAT

            || _la == mysqlParser::STATS_AUTO_RECALC
            || ((((_la - 530) & ~0x3fULL) == 0)
                && ((1ULL << (_la - 530)) & ((1ULL << (mysqlParser::STATS_PERSISTENT - 530))
                                             | (1ULL << (mysqlParser::STATS_SAMPLE_PAGES - 530))
                                             | (1ULL << (mysqlParser::TABLESPACE - 530))
                                             | (1ULL << (mysqlParser::TRUNCATE - 530))
                                             | (1ULL << (mysqlParser::UNION - 530))
                                             | (1ULL << (mysqlParser::UPGRADE - 530))))
                    != 0)
            || _la == mysqlParser::WITH

            || _la == mysqlParser::WITHOUT)
        {
            setState(1278);
            alter_specification_list();
        }
        setState(1282);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == mysqlParser::PARTITION)
        {
            setState(1281);
            partition_specification();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Alter_specificationContext
//------------------------------------------------------------------

mysqlParser::Alter_specificationContext::Alter_specificationContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Table_option_listContext *mysqlParser::Alter_specificationContext::table_option_list()
{
    return getRuleContext<mysqlParser::Table_option_listContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::ADD()
{
    return getToken(mysqlParser::ADD, 0);
}

mysqlParser::Column_nameContext *mysqlParser::Alter_specificationContext::column_name()
{
    return getRuleContext<mysqlParser::Column_nameContext>(0);
}

mysqlParser::Column_definitionContext *mysqlParser::Alter_specificationContext::column_definition()
{
    return getRuleContext<mysqlParser::Column_definitionContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::COLUMN()
{
    return getToken(mysqlParser::COLUMN, 0);
}

mysqlParser::First_afterContext *mysqlParser::Alter_specificationContext::first_after()
{
    return getRuleContext<mysqlParser::First_afterContext>(0);
}

mysqlParser::Column_definition_listContext *mysqlParser::Alter_specificationContext::
    column_definition_list()
{
    return getRuleContext<mysqlParser::Column_definition_listContext>(0);
}

mysqlParser::Index_definitionContext *mysqlParser::Alter_specificationContext::index_definition()
{
    return getRuleContext<mysqlParser::Index_definitionContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::ALGORITHM()
{
    return getToken(mysqlParser::ALGORITHM, 0);
}

mysqlParser::Table_algorithmContext *mysqlParser::Alter_specificationContext::table_algorithm()
{
    return getRuleContext<mysqlParser::Table_algorithmContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::EQUAL()
{
    return getToken(mysqlParser::EQUAL, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::ALTER()
{
    return getToken(mysqlParser::ALTER, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::SET()
{
    return getToken(mysqlParser::SET, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

mysqlParser::Default_valueContext *mysqlParser::Alter_specificationContext::default_value()
{
    return getRuleContext<mysqlParser::Default_valueContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::DROP()
{
    return getToken(mysqlParser::DROP, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::CHANGE()
{
    return getToken(mysqlParser::CHANGE, 0);
}

mysqlParser::Old_column_nameContext *mysqlParser::Alter_specificationContext::old_column_name()
{
    return getRuleContext<mysqlParser::Old_column_nameContext>(0);
}

mysqlParser::New_column_nameContext *mysqlParser::Alter_specificationContext::new_column_name()
{
    return getRuleContext<mysqlParser::New_column_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::LOCK()
{
    return getToken(mysqlParser::LOCK, 0);
}

mysqlParser::Table_lockContext *mysqlParser::Alter_specificationContext::table_lock()
{
    return getRuleContext<mysqlParser::Table_lockContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::MODIFY()
{
    return getToken(mysqlParser::MODIFY, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::PRIMARY()
{
    return getToken(mysqlParser::PRIMARY, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::KEY()
{
    return getToken(mysqlParser::KEY, 0);
}

mysqlParser::Index_nameContext *mysqlParser::Alter_specificationContext::index_name()
{
    return getRuleContext<mysqlParser::Index_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::INDEX()
{
    return getToken(mysqlParser::INDEX, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::FOREIGN()
{
    return getToken(mysqlParser::FOREIGN, 0);
}

mysqlParser::Fk_symbolContext *mysqlParser::Alter_specificationContext::fk_symbol()
{
    return getRuleContext<mysqlParser::Fk_symbolContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::DISABLE()
{
    return getToken(mysqlParser::DISABLE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::KEYS()
{
    return getToken(mysqlParser::KEYS, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::ENABLE()
{
    return getToken(mysqlParser::ENABLE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::RENAME()
{
    return getToken(mysqlParser::RENAME, 0);
}

mysqlParser::New_table_nameContext *mysqlParser::Alter_specificationContext::new_table_name()
{
    return getRuleContext<mysqlParser::New_table_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::TO()
{
    return getToken(mysqlParser::TO, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::AS()
{
    return getToken(mysqlParser::AS, 0);
}

mysqlParser::Old_index_nameContext *mysqlParser::Alter_specificationContext::old_index_name()
{
    return getRuleContext<mysqlParser::Old_index_nameContext>(0);
}

mysqlParser::New_index_nameContext *mysqlParser::Alter_specificationContext::new_index_name()
{
    return getRuleContext<mysqlParser::New_index_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::ORDER()
{
    return getToken(mysqlParser::ORDER, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::BY()
{
    return getToken(mysqlParser::BY, 0);
}

mysqlParser::Column_name_listContext *mysqlParser::Alter_specificationContext::column_name_list()
{
    return getRuleContext<mysqlParser::Column_name_listContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::CONVERT()
{
    return getToken(mysqlParser::CONVERT, 0);
}

mysqlParser::CharsetContext *mysqlParser::Alter_specificationContext::charset()
{
    return getRuleContext<mysqlParser::CharsetContext>(0);
}

mysqlParser::CollationContext *mysqlParser::Alter_specificationContext::collation()
{
    return getRuleContext<mysqlParser::CollationContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::DISCARD()
{
    return getToken(mysqlParser::DISCARD, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::TABLESPACE()
{
    return getToken(mysqlParser::TABLESPACE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::IMPORT()
{
    return getToken(mysqlParser::IMPORT, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::FORCE()
{
    return getToken(mysqlParser::FORCE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::VALIDATION()
{
    return getToken(mysqlParser::VALIDATION, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::WITHOUT()
{
    return getToken(mysqlParser::WITHOUT, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Alter_specificationContext::WITH()
{
    return getTokens(mysqlParser::WITH);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::WITH(size_t i)
{
    return getToken(mysqlParser::WITH, i);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::PARTITION()
{
    return getToken(mysqlParser::PARTITION, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

mysqlParser::Partition_definitionContext *mysqlParser::Alter_specificationContext::
    partition_definition()
{
    return getRuleContext<mysqlParser::Partition_definitionContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

mysqlParser::Partition_name_listContext *mysqlParser::Alter_specificationContext::
    partition_name_list()
{
    return getRuleContext<mysqlParser::Partition_name_listContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::ALL()
{
    return getToken(mysqlParser::ALL, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::TRUNCATE()
{
    return getToken(mysqlParser::TRUNCATE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::COALESCE()
{
    return getToken(mysqlParser::COALESCE, 0);
}

mysqlParser::Partition_numberContext *mysqlParser::Alter_specificationContext::partition_number()
{
    return getRuleContext<mysqlParser::Partition_numberContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::REORGANIZE()
{
    return getToken(mysqlParser::REORGANIZE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::INTO()
{
    return getToken(mysqlParser::INTO, 0);
}

mysqlParser::Partition_definition_listContext *mysqlParser::Alter_specificationContext::
    partition_definition_list()
{
    return getRuleContext<mysqlParser::Partition_definition_listContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::EXCHANGE()
{
    return getToken(mysqlParser::EXCHANGE, 0);
}

mysqlParser::Partition_nameContext *mysqlParser::Alter_specificationContext::partition_name()
{
    return getRuleContext<mysqlParser::Partition_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::TABLE()
{
    return getToken(mysqlParser::TABLE, 0);
}

mysqlParser::Table_nameContext *mysqlParser::Alter_specificationContext::table_name()
{
    return getRuleContext<mysqlParser::Table_nameContext>(0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::ANALYZE()
{
    return getToken(mysqlParser::ANALYZE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::CHECK()
{
    return getToken(mysqlParser::CHECK, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::OPTIMIZE()
{
    return getToken(mysqlParser::OPTIMIZE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::REBUILD()
{
    return getToken(mysqlParser::REBUILD, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::REPAIR()
{
    return getToken(mysqlParser::REPAIR, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::REMOVE()
{
    return getToken(mysqlParser::REMOVE, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::PARTITIONING()
{
    return getToken(mysqlParser::PARTITIONING, 0);
}

tree::TerminalNode *mysqlParser::Alter_specificationContext::UPGRADE()
{
    return getToken(mysqlParser::UPGRADE, 0);
}

size_t mysqlParser::Alter_specificationContext::getRuleIndex() const
{
    return mysqlParser::RuleAlter_specification;
}

void mysqlParser::Alter_specificationContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterAlter_specification(this);
}

void mysqlParser::Alter_specificationContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitAlter_specification(this);
}

antlrcpp::Any mysqlParser::Alter_specificationContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitAlter_specification(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Alter_specificationContext *mysqlParser::alter_specification()
{
    Alter_specificationContext *_localctx
        = _tracker.createInstance<Alter_specificationContext>(_ctx, getState());
    enterRule(_localctx, 226, mysqlParser::RuleAlter_specification);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1477);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 199, _ctx))
        {
        case 1:
        {
            enterOuterAlt(_localctx, 1);
            setState(1284);
            table_option_list();
            break;
        }

        case 2:
        {
            enterOuterAlt(_localctx, 2);
            setState(1285);
            match(mysqlParser::ADD);
            setState(1287);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLUMN)
            {
                setState(1286);
                match(mysqlParser::COLUMN);
            }
            setState(1289);
            column_name();
            setState(1290);
            column_definition();
            setState(1292);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::AFTER || _la == mysqlParser::FIRST)
            {
                setState(1291);
                first_after();
            }
            break;
        }

        case 3:
        {
            enterOuterAlt(_localctx, 3);
            setState(1294);
            match(mysqlParser::ADD);
            setState(1296);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLUMN)
            {
                setState(1295);
                match(mysqlParser::COLUMN);
            }
            setState(1298);
            column_definition_list();
            break;
        }

        case 4:
        {
            enterOuterAlt(_localctx, 4);
            setState(1299);
            match(mysqlParser::ADD);
            setState(1300);
            index_definition();
            break;
        }

        case 5:
        {
            enterOuterAlt(_localctx, 5);
            setState(1301);
            match(mysqlParser::ALGORITHM);
            setState(1303);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(1302);
                match(mysqlParser::EQUAL);
            }
            setState(1305);
            table_algorithm();
            break;
        }

        case 6:
        {
            enterOuterAlt(_localctx, 6);
            setState(1306);
            match(mysqlParser::ALTER);
            setState(1308);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLUMN)
            {
                setState(1307);
                match(mysqlParser::COLUMN);
            }
            setState(1310);
            column_name();
            setState(1316);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::SET:
            {
                setState(1311);
                match(mysqlParser::SET);
                setState(1312);
                match(mysqlParser::DEFAULT);
                setState(1313);
                default_value();
                break;
            }

            case mysqlParser::DROP:
            {
                setState(1314);
                match(mysqlParser::DROP);
                setState(1315);
                match(mysqlParser::DEFAULT);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 7:
        {
            enterOuterAlt(_localctx, 7);
            setState(1318);
            match(mysqlParser::CHANGE);
            setState(1320);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLUMN)
            {
                setState(1319);
                match(mysqlParser::COLUMN);
            }
            setState(1322);
            old_column_name();
            setState(1323);
            new_column_name();
            setState(1324);
            column_definition();
            setState(1326);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::AFTER || _la == mysqlParser::FIRST)
            {
                setState(1325);
                first_after();
            }
            break;
        }

        case 8:
        {
            enterOuterAlt(_localctx, 8);
            setState(1328);
            match(mysqlParser::LOCK);
            setState(1330);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::EQUAL)
            {
                setState(1329);
                match(mysqlParser::EQUAL);
            }
            setState(1332);
            table_lock();
            break;
        }

        case 9:
        {
            enterOuterAlt(_localctx, 9);
            setState(1333);
            match(mysqlParser::MODIFY);
            setState(1335);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLUMN)
            {
                setState(1334);
                match(mysqlParser::COLUMN);
            }
            setState(1337);
            column_name();
            setState(1338);
            column_definition();
            setState(1340);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::AFTER || _la == mysqlParser::FIRST)
            {
                setState(1339);
                first_after();
            }
            break;
        }

        case 10:
        {
            enterOuterAlt(_localctx, 10);
            setState(1342);
            match(mysqlParser::DROP);
            setState(1344);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLUMN)
            {
                setState(1343);
                match(mysqlParser::COLUMN);
            }
            setState(1346);
            column_name();
            break;
        }

        case 11:
        {
            enterOuterAlt(_localctx, 11);
            setState(1347);
            match(mysqlParser::DROP);
            setState(1348);
            match(mysqlParser::PRIMARY);
            setState(1349);
            match(mysqlParser::KEY);
            break;
        }

        case 12:
        {
            enterOuterAlt(_localctx, 12);
            setState(1350);
            match(mysqlParser::DROP);
            setState(1351);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::INDEX

                  || _la == mysqlParser::KEY))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
            setState(1352);
            index_name();
            break;
        }

        case 13:
        {
            enterOuterAlt(_localctx, 13);
            setState(1353);
            match(mysqlParser::DROP);
            setState(1354);
            match(mysqlParser::FOREIGN);
            setState(1355);
            match(mysqlParser::KEY);
            setState(1356);
            fk_symbol();
            break;
        }

        case 14:
        {
            enterOuterAlt(_localctx, 14);
            setState(1357);
            match(mysqlParser::DISABLE);
            setState(1358);
            match(mysqlParser::KEYS);
            break;
        }

        case 15:
        {
            enterOuterAlt(_localctx, 15);
            setState(1359);
            match(mysqlParser::ENABLE);
            setState(1360);
            match(mysqlParser::KEYS);
            break;
        }

        case 16:
        {
            enterOuterAlt(_localctx, 16);
            setState(1361);
            match(mysqlParser::RENAME);
            setState(1363);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::AS || _la == mysqlParser::TO)
            {
                setState(1362);
                _la = _input->LA(1);
                if (!(_la == mysqlParser::AS || _la == mysqlParser::TO))
                {
                    _errHandler->recoverInline(this);
                }
                else
                {
                    _errHandler->reportMatch(this);
                    consume();
                }
            }
            setState(1365);
            new_table_name();
            break;
        }

        case 17:
        {
            enterOuterAlt(_localctx, 17);
            setState(1366);
            match(mysqlParser::RENAME);
            setState(1367);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::INDEX

                  || _la == mysqlParser::KEY))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
            setState(1368);
            old_index_name();
            setState(1369);
            match(mysqlParser::TO);
            setState(1370);
            new_index_name();
            break;
        }

        case 18:
        {
            enterOuterAlt(_localctx, 18);
            setState(1372);
            match(mysqlParser::ORDER);
            setState(1373);
            match(mysqlParser::BY);
            setState(1374);
            column_name_list();
            break;
        }

        case 19:
        {
            enterOuterAlt(_localctx, 19);
            setState(1375);
            match(mysqlParser::CONVERT);
            setState(1376);
            match(mysqlParser::TO);
            setState(1377);
            charset();
            setState(1379);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLLATE)
            {
                setState(1378);
                collation();
            }
            break;
        }

        case 20:
        {
            enterOuterAlt(_localctx, 20);
            setState(1382);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::DEFAULT)
            {
                setState(1381);
                match(mysqlParser::DEFAULT);
            }
            setState(1384);
            charset();
            setState(1386);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::COLLATE)
            {
                setState(1385);
                collation();
            }
            break;
        }

        case 21:
        {
            enterOuterAlt(_localctx, 21);
            setState(1388);
            match(mysqlParser::DISCARD);
            setState(1389);
            match(mysqlParser::TABLESPACE);
            break;
        }

        case 22:
        {
            enterOuterAlt(_localctx, 22);
            setState(1390);
            match(mysqlParser::IMPORT);
            setState(1391);
            match(mysqlParser::TABLESPACE);
            break;
        }

        case 23:
        {
            enterOuterAlt(_localctx, 23);
            setState(1392);
            match(mysqlParser::FORCE);
            break;
        }

        case 24:
        {
            enterOuterAlt(_localctx, 24);
            setState(1393);
            _la = _input->LA(1);
            if (!(_la == mysqlParser::WITH

                  || _la == mysqlParser::WITHOUT))
            {
                _errHandler->recoverInline(this);
            }
            else
            {
                _errHandler->reportMatch(this);
                consume();
            }
            setState(1394);
            match(mysqlParser::VALIDATION);
            break;
        }

        case 25:
        {
            enterOuterAlt(_localctx, 25);
            setState(1395);
            match(mysqlParser::ADD);
            setState(1396);
            match(mysqlParser::PARTITION);
            setState(1397);
            match(mysqlParser::LPAREN);
            setState(1398);
            partition_definition();
            setState(1399);
            match(mysqlParser::RPAREN);
            break;
        }

        case 26:
        {
            enterOuterAlt(_localctx, 26);
            setState(1401);
            match(mysqlParser::DROP);
            setState(1402);
            match(mysqlParser::PARTITION);
            setState(1403);
            partition_name_list();
            break;
        }

        case 27:
        {
            enterOuterAlt(_localctx, 27);
            setState(1404);
            match(mysqlParser::DISCARD);
            setState(1405);
            match(mysqlParser::PARTITION);
            setState(1408);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::ID:
            case mysqlParser::BQUOTED_STRING:
            {
                setState(1406);
                partition_name_list();
                break;
            }

            case mysqlParser::ALL:
            {
                setState(1407);
                match(mysqlParser::ALL);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            setState(1410);
            match(mysqlParser::TABLESPACE);
            break;
        }

        case 28:
        {
            enterOuterAlt(_localctx, 28);
            setState(1411);
            match(mysqlParser::IMPORT);
            setState(1412);
            match(mysqlParser::PARTITION);
            setState(1415);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::ID:
            case mysqlParser::BQUOTED_STRING:
            {
                setState(1413);
                partition_name_list();
                break;
            }

            case mysqlParser::ALL:
            {
                setState(1414);
                match(mysqlParser::ALL);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            setState(1417);
            match(mysqlParser::TABLESPACE);
            break;
        }

        case 29:
        {
            enterOuterAlt(_localctx, 29);
            setState(1418);
            match(mysqlParser::TRUNCATE);
            setState(1419);
            match(mysqlParser::PARTITION);
            setState(1422);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::ID:
            case mysqlParser::BQUOTED_STRING:
            {
                setState(1420);
                partition_name_list();
                break;
            }

            case mysqlParser::ALL:
            {
                setState(1421);
                match(mysqlParser::ALL);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 30:
        {
            enterOuterAlt(_localctx, 30);
            setState(1424);
            match(mysqlParser::COALESCE);
            setState(1425);
            match(mysqlParser::PARTITION);
            setState(1426);
            partition_number();
            break;
        }

        case 31:
        {
            enterOuterAlt(_localctx, 31);
            setState(1427);
            match(mysqlParser::REORGANIZE);
            setState(1428);
            match(mysqlParser::PARTITION);
            setState(1429);
            partition_name_list();
            setState(1430);
            match(mysqlParser::INTO);
            setState(1431);
            partition_definition_list();
            break;
        }

        case 32:
        {
            enterOuterAlt(_localctx, 32);
            setState(1433);
            match(mysqlParser::EXCHANGE);
            setState(1434);
            match(mysqlParser::PARTITION);
            setState(1435);
            partition_name();
            setState(1436);
            match(mysqlParser::WITH);
            setState(1437);
            match(mysqlParser::TABLE);
            setState(1438);
            table_name();
            setState(1441);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == mysqlParser::WITH

                || _la == mysqlParser::WITHOUT)
            {
                setState(1439);
                _la = _input->LA(1);
                if (!(_la == mysqlParser::WITH

                      || _la == mysqlParser::WITHOUT))
                {
                    _errHandler->recoverInline(this);
                }
                else
                {
                    _errHandler->reportMatch(this);
                    consume();
                }
                setState(1440);
                match(mysqlParser::VALIDATION);
            }
            break;
        }

        case 33:
        {
            enterOuterAlt(_localctx, 33);
            setState(1443);
            match(mysqlParser::ANALYZE);
            setState(1444);
            match(mysqlParser::PARTITION);
            setState(1447);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::ID:
            case mysqlParser::BQUOTED_STRING:
            {
                setState(1445);
                partition_name_list();
                break;
            }

            case mysqlParser::ALL:
            {
                setState(1446);
                match(mysqlParser::ALL);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 34:
        {
            enterOuterAlt(_localctx, 34);
            setState(1449);
            match(mysqlParser::CHECK);
            setState(1450);
            match(mysqlParser::PARTITION);
            setState(1453);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::ID:
            case mysqlParser::BQUOTED_STRING:
            {
                setState(1451);
                partition_name_list();
                break;
            }

            case mysqlParser::ALL:
            {
                setState(1452);
                match(mysqlParser::ALL);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 35:
        {
            enterOuterAlt(_localctx, 35);
            setState(1455);
            match(mysqlParser::OPTIMIZE);
            setState(1456);
            match(mysqlParser::PARTITION);
            setState(1459);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::ID:
            case mysqlParser::BQUOTED_STRING:
            {
                setState(1457);
                partition_name_list();
                break;
            }

            case mysqlParser::ALL:
            {
                setState(1458);
                match(mysqlParser::ALL);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 36:
        {
            enterOuterAlt(_localctx, 36);
            setState(1461);
            match(mysqlParser::REBUILD);
            setState(1462);
            match(mysqlParser::PARTITION);
            setState(1465);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::ID:
            case mysqlParser::BQUOTED_STRING:
            {
                setState(1463);
                partition_name_list();
                break;
            }

            case mysqlParser::ALL:
            {
                setState(1464);
                match(mysqlParser::ALL);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 37:
        {
            enterOuterAlt(_localctx, 37);
            setState(1467);
            match(mysqlParser::REPAIR);
            setState(1468);
            match(mysqlParser::PARTITION);
            setState(1471);
            _errHandler->sync(this);
            switch (_input->LA(1))
            {
            case mysqlParser::ID:
            case mysqlParser::BQUOTED_STRING:
            {
                setState(1469);
                partition_name_list();
                break;
            }

            case mysqlParser::ALL:
            {
                setState(1470);
                match(mysqlParser::ALL);
                break;
            }

            default:
                throw NoViableAltException(this);
            }
            break;
        }

        case 38:
        {
            enterOuterAlt(_localctx, 38);
            setState(1473);
            match(mysqlParser::REMOVE);
            setState(1474);
            match(mysqlParser::PARTITIONING);
            break;
        }

        case 39:
        {
            enterOuterAlt(_localctx, 39);
            setState(1475);
            match(mysqlParser::UPGRADE);
            setState(1476);
            match(mysqlParser::PARTITIONING);
            break;
        }
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Alter_specification_listContext
//------------------------------------------------------------------

mysqlParser::Alter_specification_listContext::Alter_specification_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<mysqlParser::Alter_specificationContext *> mysqlParser::
    Alter_specification_listContext::alter_specification()
{
    return getRuleContexts<mysqlParser::Alter_specificationContext>();
}

mysqlParser::Alter_specificationContext *mysqlParser::Alter_specification_listContext::
    alter_specification(size_t i)
{
    return getRuleContext<mysqlParser::Alter_specificationContext>(i);
}

std::vector<tree::TerminalNode *> mysqlParser::Alter_specification_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Alter_specification_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Alter_specification_listContext::getRuleIndex() const
{
    return mysqlParser::RuleAlter_specification_list;
}

void mysqlParser::Alter_specification_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterAlter_specification_list(this);
}

void mysqlParser::Alter_specification_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitAlter_specification_list(this);
}

antlrcpp::Any mysqlParser::Alter_specification_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitAlter_specification_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Alter_specification_listContext *mysqlParser::alter_specification_list()
{
    Alter_specification_listContext *_localctx
        = _tracker.createInstance<Alter_specification_listContext>(_ctx, getState());
    enterRule(_localctx, 228, mysqlParser::RuleAlter_specification_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1479);
        alter_specification();
        setState(1484);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(1480);
            match(mysqlParser::COMMA);
            setState(1481);
            alter_specification();
            setState(1486);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Column_name_listContext
//------------------------------------------------------------------

mysqlParser::Column_name_listContext::Column_name_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<mysqlParser::Column_nameContext *> mysqlParser::Column_name_listContext::column_name()
{
    return getRuleContexts<mysqlParser::Column_nameContext>();
}

mysqlParser::Column_nameContext *mysqlParser::Column_name_listContext::column_name(size_t i)
{
    return getRuleContext<mysqlParser::Column_nameContext>(i);
}

std::vector<tree::TerminalNode *> mysqlParser::Column_name_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Column_name_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Column_name_listContext::getRuleIndex() const
{
    return mysqlParser::RuleColumn_name_list;
}

void mysqlParser::Column_name_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterColumn_name_list(this);
}

void mysqlParser::Column_name_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitColumn_name_list(this);
}

antlrcpp::Any mysqlParser::Column_name_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitColumn_name_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Column_name_listContext *mysqlParser::column_name_list()
{
    Column_name_listContext *_localctx
        = _tracker.createInstance<Column_name_listContext>(_ctx, getState());
    enterRule(_localctx, 230, mysqlParser::RuleColumn_name_list);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(1487);
        column_name();
        setState(1492);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 201, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
        {
            if (alt == 1)
            {
                setState(1488);
                match(mysqlParser::COMMA);
                setState(1489);
                column_name();
            }
            setState(1494);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 201, _ctx);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_name_listContext
//------------------------------------------------------------------

mysqlParser::Partition_name_listContext::Partition_name_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<mysqlParser::Partition_nameContext *> mysqlParser::Partition_name_listContext::
    partition_name()
{
    return getRuleContexts<mysqlParser::Partition_nameContext>();
}

mysqlParser::Partition_nameContext *mysqlParser::Partition_name_listContext::partition_name(
    size_t i)
{
    return getRuleContext<mysqlParser::Partition_nameContext>(i);
}

std::vector<tree::TerminalNode *> mysqlParser::Partition_name_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Partition_name_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Partition_name_listContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_name_list;
}

void mysqlParser::Partition_name_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_name_list(this);
}

void mysqlParser::Partition_name_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_name_list(this);
}

antlrcpp::Any mysqlParser::Partition_name_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_name_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_name_listContext *mysqlParser::partition_name_list()
{
    Partition_name_listContext *_localctx
        = _tracker.createInstance<Partition_name_listContext>(_ctx, getState());
    enterRule(_localctx, 232, mysqlParser::RulePartition_name_list);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(1495);
        partition_name();
        setState(1500);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 202, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
        {
            if (alt == 1)
            {
                setState(1496);
                match(mysqlParser::COMMA);
                setState(1497);
                partition_name();
            }
            setState(1502);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 202, _ctx);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Column_definition_listContext
//------------------------------------------------------------------

mysqlParser::Column_definition_listContext::Column_definition_listContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Column_definition_listContext::LPAREN()
{
    return getToken(mysqlParser::LPAREN, 0);
}

std::vector<mysqlParser::Column_nameContext *> mysqlParser::Column_definition_listContext::
    column_name()
{
    return getRuleContexts<mysqlParser::Column_nameContext>();
}

mysqlParser::Column_nameContext *mysqlParser::Column_definition_listContext::column_name(size_t i)
{
    return getRuleContext<mysqlParser::Column_nameContext>(i);
}

std::vector<mysqlParser::Column_definitionContext *> mysqlParser::Column_definition_listContext::
    column_definition()
{
    return getRuleContexts<mysqlParser::Column_definitionContext>();
}

mysqlParser::Column_definitionContext *mysqlParser::Column_definition_listContext::
    column_definition(size_t i)
{
    return getRuleContext<mysqlParser::Column_definitionContext>(i);
}

tree::TerminalNode *mysqlParser::Column_definition_listContext::RPAREN()
{
    return getToken(mysqlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> mysqlParser::Column_definition_listContext::COMMA()
{
    return getTokens(mysqlParser::COMMA);
}

tree::TerminalNode *mysqlParser::Column_definition_listContext::COMMA(size_t i)
{
    return getToken(mysqlParser::COMMA, i);
}

size_t mysqlParser::Column_definition_listContext::getRuleIndex() const
{
    return mysqlParser::RuleColumn_definition_list;
}

void mysqlParser::Column_definition_listContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterColumn_definition_list(this);
}

void mysqlParser::Column_definition_listContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitColumn_definition_list(this);
}

antlrcpp::Any mysqlParser::Column_definition_listContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitColumn_definition_list(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Column_definition_listContext *mysqlParser::column_definition_list()
{
    Column_definition_listContext *_localctx
        = _tracker.createInstance<Column_definition_listContext>(_ctx, getState());
    enterRule(_localctx, 234, mysqlParser::RuleColumn_definition_list);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1503);
        match(mysqlParser::LPAREN);
        setState(1504);
        column_name();
        setState(1505);
        column_definition();
        setState(1512);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == mysqlParser::COMMA)
        {
            setState(1506);
            match(mysqlParser::COMMA);
            setState(1507);
            column_name();
            setState(1508);
            column_definition();
            setState(1514);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(1515);
        match(mysqlParser::RPAREN);
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Table_algorithmContext
//------------------------------------------------------------------

mysqlParser::Table_algorithmContext::Table_algorithmContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Table_algorithmContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

tree::TerminalNode *mysqlParser::Table_algorithmContext::INPLACE()
{
    return getToken(mysqlParser::INPLACE, 0);
}

tree::TerminalNode *mysqlParser::Table_algorithmContext::COPY()
{
    return getToken(mysqlParser::COPY, 0);
}

size_t mysqlParser::Table_algorithmContext::getRuleIndex() const
{
    return mysqlParser::RuleTable_algorithm;
}

void mysqlParser::Table_algorithmContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterTable_algorithm(this);
}

void mysqlParser::Table_algorithmContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitTable_algorithm(this);
}

antlrcpp::Any mysqlParser::Table_algorithmContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitTable_algorithm(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Table_algorithmContext *mysqlParser::table_algorithm()
{
    Table_algorithmContext *_localctx
        = _tracker.createInstance<Table_algorithmContext>(_ctx, getState());
    enterRule(_localctx, 236, mysqlParser::RuleTable_algorithm);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1517);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::COPY

              || _la == mysqlParser::DEFAULT || _la == mysqlParser::INPLACE))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Table_lockContext
//------------------------------------------------------------------

mysqlParser::Table_lockContext::Table_lockContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::Table_lockContext::DEFAULT()
{
    return getToken(mysqlParser::DEFAULT, 0);
}

tree::TerminalNode *mysqlParser::Table_lockContext::NONE()
{
    return getToken(mysqlParser::NONE, 0);
}

tree::TerminalNode *mysqlParser::Table_lockContext::SHARED()
{
    return getToken(mysqlParser::SHARED, 0);
}

tree::TerminalNode *mysqlParser::Table_lockContext::EXCLUSIVE()
{
    return getToken(mysqlParser::EXCLUSIVE, 0);
}

size_t mysqlParser::Table_lockContext::getRuleIndex() const
{
    return mysqlParser::RuleTable_lock;
}

void mysqlParser::Table_lockContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterTable_lock(this);
}

void mysqlParser::Table_lockContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitTable_lock(this);
}

antlrcpp::Any mysqlParser::Table_lockContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitTable_lock(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Table_lockContext *mysqlParser::table_lock()
{
    Table_lockContext *_localctx = _tracker.createInstance<Table_lockContext>(_ctx, getState());
    enterRule(_localctx, 238, mysqlParser::RuleTable_lock);
    size_t _la = 0;

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1519);
        _la = _input->LA(1);
        if (!(_la == mysqlParser::DEFAULT

              || _la == mysqlParser::EXCLUSIVE || _la == mysqlParser::NONE
              || _la == mysqlParser::SHARED))
        {
            _errHandler->recoverInline(this);
        }
        else
        {
            _errHandler->reportMatch(this);
            consume();
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- First_afterContext
//------------------------------------------------------------------

mysqlParser::First_afterContext::First_afterContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *mysqlParser::First_afterContext::FIRST()
{
    return getToken(mysqlParser::FIRST, 0);
}

tree::TerminalNode *mysqlParser::First_afterContext::AFTER()
{
    return getToken(mysqlParser::AFTER, 0);
}

mysqlParser::Column_nameContext *mysqlParser::First_afterContext::column_name()
{
    return getRuleContext<mysqlParser::Column_nameContext>(0);
}

size_t mysqlParser::First_afterContext::getRuleIndex() const
{
    return mysqlParser::RuleFirst_after;
}

void mysqlParser::First_afterContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterFirst_after(this);
}

void mysqlParser::First_afterContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitFirst_after(this);
}

antlrcpp::Any mysqlParser::First_afterContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitFirst_after(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::First_afterContext *mysqlParser::first_after()
{
    First_afterContext *_localctx = _tracker.createInstance<First_afterContext>(_ctx, getState());
    enterRule(_localctx, 240, mysqlParser::RuleFirst_after);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        setState(1524);
        _errHandler->sync(this);
        switch (_input->LA(1))
        {
        case mysqlParser::FIRST:
        {
            enterOuterAlt(_localctx, 1);
            setState(1521);
            match(mysqlParser::FIRST);
            break;
        }

        case mysqlParser::AFTER:
        {
            enterOuterAlt(_localctx, 2);
            setState(1522);
            match(mysqlParser::AFTER);
            setState(1523);
            column_name();
            break;
        }

        default:
            throw NoViableAltException(this);
        }
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Fk_symbolContext
//------------------------------------------------------------------

mysqlParser::Fk_symbolContext::Fk_symbolContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::SymbolContext *mysqlParser::Fk_symbolContext::symbol()
{
    return getRuleContext<mysqlParser::SymbolContext>(0);
}

size_t mysqlParser::Fk_symbolContext::getRuleIndex() const
{
    return mysqlParser::RuleFk_symbol;
}

void mysqlParser::Fk_symbolContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterFk_symbol(this);
}

void mysqlParser::Fk_symbolContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitFk_symbol(this);
}

antlrcpp::Any mysqlParser::Fk_symbolContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitFk_symbol(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Fk_symbolContext *mysqlParser::fk_symbol()
{
    Fk_symbolContext *_localctx = _tracker.createInstance<Fk_symbolContext>(_ctx, getState());
    enterRule(_localctx, 242, mysqlParser::RuleFk_symbol);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1526);
        symbol();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- New_table_nameContext
//------------------------------------------------------------------

mysqlParser::New_table_nameContext::New_table_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Table_nameContext *mysqlParser::New_table_nameContext::table_name()
{
    return getRuleContext<mysqlParser::Table_nameContext>(0);
}

size_t mysqlParser::New_table_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleNew_table_name;
}

void mysqlParser::New_table_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterNew_table_name(this);
}

void mysqlParser::New_table_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitNew_table_name(this);
}

antlrcpp::Any mysqlParser::New_table_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitNew_table_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::New_table_nameContext *mysqlParser::new_table_name()
{
    New_table_nameContext *_localctx
        = _tracker.createInstance<New_table_nameContext>(_ctx, getState());
    enterRule(_localctx, 244, mysqlParser::RuleNew_table_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1528);
        table_name();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Old_column_nameContext
//------------------------------------------------------------------

mysqlParser::Old_column_nameContext::Old_column_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Column_nameContext *mysqlParser::Old_column_nameContext::column_name()
{
    return getRuleContext<mysqlParser::Column_nameContext>(0);
}

size_t mysqlParser::Old_column_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleOld_column_name;
}

void mysqlParser::Old_column_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterOld_column_name(this);
}

void mysqlParser::Old_column_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitOld_column_name(this);
}

antlrcpp::Any mysqlParser::Old_column_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitOld_column_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Old_column_nameContext *mysqlParser::old_column_name()
{
    Old_column_nameContext *_localctx
        = _tracker.createInstance<Old_column_nameContext>(_ctx, getState());
    enterRule(_localctx, 246, mysqlParser::RuleOld_column_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1530);
        column_name();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- New_column_nameContext
//------------------------------------------------------------------

mysqlParser::New_column_nameContext::New_column_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Column_nameContext *mysqlParser::New_column_nameContext::column_name()
{
    return getRuleContext<mysqlParser::Column_nameContext>(0);
}

size_t mysqlParser::New_column_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleNew_column_name;
}

void mysqlParser::New_column_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterNew_column_name(this);
}

void mysqlParser::New_column_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitNew_column_name(this);
}

antlrcpp::Any mysqlParser::New_column_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitNew_column_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::New_column_nameContext *mysqlParser::new_column_name()
{
    New_column_nameContext *_localctx
        = _tracker.createInstance<New_column_nameContext>(_ctx, getState());
    enterRule(_localctx, 248, mysqlParser::RuleNew_column_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1532);
        column_name();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Old_index_nameContext
//------------------------------------------------------------------

mysqlParser::Old_index_nameContext::Old_index_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Index_nameContext *mysqlParser::Old_index_nameContext::index_name()
{
    return getRuleContext<mysqlParser::Index_nameContext>(0);
}

size_t mysqlParser::Old_index_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleOld_index_name;
}

void mysqlParser::Old_index_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterOld_index_name(this);
}

void mysqlParser::Old_index_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitOld_index_name(this);
}

antlrcpp::Any mysqlParser::Old_index_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitOld_index_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Old_index_nameContext *mysqlParser::old_index_name()
{
    Old_index_nameContext *_localctx
        = _tracker.createInstance<Old_index_nameContext>(_ctx, getState());
    enterRule(_localctx, 250, mysqlParser::RuleOld_index_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1534);
        index_name();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- New_index_nameContext
//------------------------------------------------------------------

mysqlParser::New_index_nameContext::New_index_nameContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Index_nameContext *mysqlParser::New_index_nameContext::index_name()
{
    return getRuleContext<mysqlParser::Index_nameContext>(0);
}

size_t mysqlParser::New_index_nameContext::getRuleIndex() const
{
    return mysqlParser::RuleNew_index_name;
}

void mysqlParser::New_index_nameContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterNew_index_name(this);
}

void mysqlParser::New_index_nameContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitNew_index_name(this);
}

antlrcpp::Any mysqlParser::New_index_nameContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitNew_index_name(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::New_index_nameContext *mysqlParser::new_index_name()
{
    New_index_nameContext *_localctx
        = _tracker.createInstance<New_index_nameContext>(_ctx, getState());
    enterRule(_localctx, 252, mysqlParser::RuleNew_index_name);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1536);
        index_name();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- Partition_numberContext
//------------------------------------------------------------------

mysqlParser::Partition_numberContext::Partition_numberContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

mysqlParser::Integer_literalContext *mysqlParser::Partition_numberContext::integer_literal()
{
    return getRuleContext<mysqlParser::Integer_literalContext>(0);
}

size_t mysqlParser::Partition_numberContext::getRuleIndex() const
{
    return mysqlParser::RulePartition_number;
}

void mysqlParser::Partition_numberContext::enterRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterPartition_number(this);
}

void mysqlParser::Partition_numberContext::exitRule(tree::ParseTreeListener *listener)
{
    auto parserListener = dynamic_cast<mysqlListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitPartition_number(this);
}

antlrcpp::Any mysqlParser::Partition_numberContext::accept(tree::ParseTreeVisitor *visitor)
{
    if (auto parserVisitor = dynamic_cast<mysqlVisitor *>(visitor))
        return parserVisitor->visitPartition_number(this);
    else
        return visitor->visitChildren(this);
}

mysqlParser::Partition_numberContext *mysqlParser::partition_number()
{
    Partition_numberContext *_localctx
        = _tracker.createInstance<Partition_numberContext>(_ctx, getState());
    enterRule(_localctx, 254, mysqlParser::RulePartition_number);

    auto onExit = finally([=] { exitRule(); });
    try
    {
        enterOuterAlt(_localctx, 1);
        setState(1538);
        integer_literal();
    }
    catch (RecognitionException &e)
    {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> mysqlParser::_decisionToDFA;
atn::PredictionContextCache mysqlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN mysqlParser::_atn;
std::vector<uint16_t> mysqlParser::_serializedATN;

std::vector<std::string> mysqlParser::_ruleNames = {"parse",
                                                    "statement",
                                                    "assignment",
                                                    "drop_table",
                                                    "table_name_list",
                                                    "create_table",
                                                    "create_definition",
                                                    "index_definition",
                                                    "column_definition",
                                                    "column_options",
                                                    "generated_column_options",
                                                    "data_type",
                                                    "table_option",
                                                    "partition_specification",
                                                    "partition_definition_list",
                                                    "partition_by",
                                                    "subpartition_by",
                                                    "partition_definition",
                                                    "subpartition_definition_list",
                                                    "partition_values",
                                                    "subpartition_definition",
                                                    "partition_options",
                                                    "index_option",
                                                    "reference_definition",
                                                    "create_definition_list",
                                                    "table_option_list",
                                                    "index_option_list",
                                                    "index_column_list",
                                                    "reference_column_list",
                                                    "less_than_value_list",
                                                    "in_value_list",
                                                    "enum_value_list",
                                                    "key_column_list",
                                                    "range_column_list",
                                                    "list_column_list",
                                                    "table_union_list",
                                                    "constraint",
                                                    "charset",
                                                    "collation",
                                                    "index_structure",
                                                    "index_column",
                                                    "reference_column",
                                                    "fsp",
                                                    "length",
                                                    "decimals",
                                                    "partition_count",
                                                    "subpartition_count",
                                                    "auto_increment",
                                                    "avg_row_length",
                                                    "key_block_size",
                                                    "max_number_of_rows",
                                                    "min_number_of_rows",
                                                    "stats_sample_pages",
                                                    "checksum",
                                                    "compression",
                                                    "delay_key_write",
                                                    "encryption",
                                                    "insert_method",
                                                    "pack_keys",
                                                    "row_format",
                                                    "stats_auto_recalc",
                                                    "stats_persistent",
                                                    "key_algorithm",
                                                    "match_option",
                                                    "on_delete_option",
                                                    "on_update_option",
                                                    "column_format",
                                                    "column_storage",
                                                    "integer_type",
                                                    "real_type",
                                                    "text_type",
                                                    "blob_type",
                                                    "spatial_type",
                                                    "enum_type",
                                                    "binary_type",
                                                    "char_type",
                                                    "datetime_type",
                                                    "on_update_set",
                                                    "default_value",
                                                    "comment",
                                                    "connection",
                                                    "password",
                                                    "data_directory",
                                                    "index_directory",
                                                    "as_expression",
                                                    "query_expression",
                                                    "check_expression",
                                                    "hash_expression",
                                                    "range_expression",
                                                    "list_expression",
                                                    "less_than_expression",
                                                    "expression",
                                                    "symbol",
                                                    "engine_name",
                                                    "old_table_name",
                                                    "column_name",
                                                    "index_name",
                                                    "tablespace_name",
                                                    "table_name",
                                                    "database_name",
                                                    "parser_name",
                                                    "charset_name",
                                                    "collation_name",
                                                    "partition_name",
                                                    "logical_name",
                                                    "literal",
                                                    "identifier",
                                                    "bool_literal",
                                                    "float_literal",
                                                    "integer_literal",
                                                    "string_literal",
                                                    "datetime_literal",
                                                    "alter_table",
                                                    "alter_specification",
                                                    "alter_specification_list",
                                                    "column_name_list",
                                                    "partition_name_list",
                                                    "column_definition_list",
                                                    "table_algorithm",
                                                    "table_lock",
                                                    "first_after",
                                                    "fk_symbol",
                                                    "new_table_name",
                                                    "old_column_name",
                                                    "new_column_name",
                                                    "old_index_name",
                                                    "new_index_name",
                                                    "partition_number"};

std::vector<std::string> mysqlParser::_literalNames = {
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "",    "",    "",    "",    "",    "",    "",   "", "",
    "", "", "", "", "", "", "", "", "", "", "'('", "')'", "'.'", "','", "':'", "';'", "'='"};

std::vector<std::string> mysqlParser::_symbolicNames = {"",
                                                        "ACCESSIBLE",
                                                        "ACCOUNT",
                                                        "ACTION",
                                                        "ADD",
                                                        "AFTER",
                                                        "AGAINST",
                                                        "AGGREGATE",
                                                        "ALGORITHM",
                                                        "ALL",
                                                        "ALTER",
                                                        "ALWAYS",
                                                        "ANALYSE",
                                                        "ANALYZE",
                                                        "AND",
                                                        "ANY",
                                                        "AS",
                                                        "ASC",
                                                        "ASCII",
                                                        "ASENSITIVE",
                                                        "AT",
                                                        "AUTOEXTEND_SIZE",
                                                        "AUTO_INCREMENT",
                                                        "AVG",
                                                        "AVG_ROW_LENGTH",
                                                        "BACKUP",
                                                        "BEFORE",
                                                        "BEGIN",
                                                        "BETWEEN",
                                                        "BIGINT",
                                                        "BINARY",
                                                        "BINLOG",
                                                        "BIT",
                                                        "BLOB",
                                                        "BLOCK",
                                                        "BOOL",
                                                        "BOOLEAN",
                                                        "BOTH",
                                                        "BTREE",
                                                        "BY",
                                                        "BYTE",
                                                        "CACHE",
                                                        "CALL",
                                                        "CASCADE",
                                                        "CASCADED",
                                                        "CASE",
                                                        "CATALOG_NAME",
                                                        "CHAIN",
                                                        "CHANGE",
                                                        "CHANGED",
                                                        "CHANNEL",
                                                        "CHAR",
                                                        "CHARACTER",
                                                        "CHARSET",
                                                        "CHECK",
                                                        "CHECKSUM",
                                                        "CIPHER",
                                                        "CLASS_ORIGIN",
                                                        "CLIENT",
                                                        "CLOSE",
                                                        "COALESCE",
                                                        "CODE",
                                                        "COLLATE",
                                                        "COLLATION",
                                                        "COLUMN",
                                                        "COLUMNS",
                                                        "COLUMN_FORMAT",
                                                        "COLUMN_NAME",
                                                        "COMMENT",
                                                        "COMMIT",
                                                        "COMMITTED",
                                                        "COMPACT",
                                                        "COMPLETION",
                                                        "COMPRESSED",
                                                        "COMPRESSION",
                                                        "CONCURRENT",
                                                        "CONDITION",
                                                        "CONNECTION",
                                                        "CONSISTENT",
                                                        "CONSTRAINT",
                                                        "CONSTRAINT_CATALOG",
                                                        "CONSTRAINT_NAME",
                                                        "CONSTRAINT_SCHEMA",
                                                        "CONTAINS",
                                                        "CONTEXT",
                                                        "CONTINUE",
                                                        "CONVERT",
                                                        "COPY",
                                                        "CPU",
                                                        "CREATE",
                                                        "CROSS",
                                                        "CUBE",
                                                        "CURRENT",
                                                        "CURRENT_DATE",
                                                        "CURRENT_TIME",
                                                        "CURRENT_TIMESTAMP",
                                                        "CURRENT_USER",
                                                        "CURSOR",
                                                        "CURSOR_NAME",
                                                        "DATA",
                                                        "DATABASE",
                                                        "DATABASES",
                                                        "DATAFILE",
                                                        "DATE",
                                                        "DATETIME",
                                                        "DAY",
                                                        "DAY_HOUR",
                                                        "DAY_MICROSECOND",
                                                        "DAY_MINUTE",
                                                        "DAY_SECOND",
                                                        "DEALLOCATE",
                                                        "DEC",
                                                        "DECIMAL",
                                                        "DECLARE",
                                                        "DEFAULT",
                                                        "DEFAULT_AUTH",
                                                        "DEFINER",
                                                        "DELAYED",
                                                        "DELAY_KEY_WRITE",
                                                        "DELETE",
                                                        "DESC",
                                                        "DESCRIBE",
                                                        "DES_KEY_FILE",
                                                        "DETERMINISTIC",
                                                        "DIAGNOSTICS",
                                                        "DIRECTORY",
                                                        "DISABLE",
                                                        "DISCARD",
                                                        "DISK",
                                                        "DISTINCT",
                                                        "DISTINCTROW",
                                                        "DIV",
                                                        "DO",
                                                        "DOUBLE",
                                                        "DROP",
                                                        "DUAL",
                                                        "DUMPFILE",
                                                        "DUPLICATE",
                                                        "DYNAMIC",
                                                        "EACH",
                                                        "ELSE",
                                                        "ELSEIF",
                                                        "ENABLE",
                                                        "ENCLOSED",
                                                        "ENCRYPTION",
                                                        "END",
                                                        "ENDS",
                                                        "ENGINE",
                                                        "ENGINES",
                                                        "ENUM",
                                                        "ERROR",
                                                        "ERRORS",
                                                        "ESCAPE",
                                                        "ESCAPED",
                                                        "EVENT",
                                                        "EVENTS",
                                                        "EVERY",
                                                        "EXCHANGE",
                                                        "EXCLUSIVE",
                                                        "EXECUTE",
                                                        "EXISTS",
                                                        "EXIT",
                                                        "EXPANSION",
                                                        "EXPIRE",
                                                        "EXPLAIN",
                                                        "EXPORT",
                                                        "EXTENDED",
                                                        "EXTENT_SIZE",
                                                        "FALSE",
                                                        "FAST",
                                                        "FAULTS",
                                                        "FETCH",
                                                        "FIELDS",
                                                        "FILE",
                                                        "FILE_BLOCK_SIZE",
                                                        "FILTER",
                                                        "FIRST",
                                                        "FIXED",
                                                        "FLOAT",
                                                        "FLOAT4",
                                                        "FLOAT8",
                                                        "FLUSH",
                                                        "FOLLOWS",
                                                        "FOR",
                                                        "FORCE",
                                                        "FOREIGN",
                                                        "FORMAT",
                                                        "FOUND",
                                                        "FROM",
                                                        "FULL",
                                                        "FULLTEXT",
                                                        "FUNCTION",
                                                        "GENERAL",
                                                        "GENERATED",
                                                        "GEOMETRY",
                                                        "GEOMETRYCOLLECTION",
                                                        "GET",
                                                        "GET_FORMAT",
                                                        "GLOBAL",
                                                        "GRANT",
                                                        "GRANTS",
                                                        "GROUP",
                                                        "GROUP_REPLICATION",
                                                        "HANDLER",
                                                        "HASH",
                                                        "HAVING",
                                                        "HELP",
                                                        "HIGH_PRIORITY",
                                                        "HOST",
                                                        "HOSTS",
                                                        "HOUR",
                                                        "HOUR_MICROSECOND",
                                                        "HOUR_MINUTE",
                                                        "HOUR_SECOND",
                                                        "IDENTIFIED",
                                                        "IF",
                                                        "IGNORE",
                                                        "IGNORE_SERVER_IDS",
                                                        "IMPORT",
                                                        "IN",
                                                        "INDEX",
                                                        "INDEXES",
                                                        "INFILE",
                                                        "INITIAL_SIZE",
                                                        "INNER",
                                                        "INOUT",
                                                        "INPLACE",
                                                        "INSENSITIVE",
                                                        "INSERT",
                                                        "INSERT_METHOD",
                                                        "INSTALL",
                                                        "INSTANCE",
                                                        "INT",
                                                        "INT1",
                                                        "INT2",
                                                        "INT3",
                                                        "INT4",
                                                        "INT8",
                                                        "INTEGER",
                                                        "INTERVAL",
                                                        "INTO",
                                                        "INVOKER",
                                                        "IO",
                                                        "IO_AFTER_GTIDS",
                                                        "IO_BEFORE_GTIDS",
                                                        "IO_THREAD",
                                                        "IPC",
                                                        "IS",
                                                        "ISOLATION",
                                                        "ISSUER",
                                                        "ITERATE",
                                                        "JOIN",
                                                        "JSON",
                                                        "KEY",
                                                        "KEYS",
                                                        "KEY_BLOCK_SIZE",
                                                        "KILL",
                                                        "LANGUAGE",
                                                        "LAST",
                                                        "LEADING",
                                                        "LEAVE",
                                                        "LEAVES",
                                                        "LEFT",
                                                        "LESS",
                                                        "LEVEL",
                                                        "LIKE",
                                                        "LIMIT",
                                                        "LINEAR",
                                                        "LINES",
                                                        "LINESTRING",
                                                        "LIST",
                                                        "LOAD",
                                                        "LOCAL",
                                                        "LOCALTIME",
                                                        "LOCALTIMESTAMP",
                                                        "LOCK",
                                                        "LOCKS",
                                                        "LOGFILE",
                                                        "LOGS",
                                                        "LONG",
                                                        "LONGBLOB",
                                                        "LONGTEXT",
                                                        "LOOP",
                                                        "LOW_PRIORITY",
                                                        "MASTER",
                                                        "MASTER_AUTO_POSITION",
                                                        "MASTER_BIND",
                                                        "MASTER_CONNECT_RETRY",
                                                        "MASTER_DELAY",
                                                        "MASTER_HEARTBEAT_PERIOD",
                                                        "MASTER_HOST",
                                                        "MASTER_LOG_FILE",
                                                        "MASTER_LOG_POS",
                                                        "MASTER_PASSWORD",
                                                        "MASTER_PORT",
                                                        "MASTER_RETRY_COUNT",
                                                        "MASTER_SERVER_ID",
                                                        "MASTER_SSL",
                                                        "MASTER_SSL_CA",
                                                        "MASTER_SSL_CAPATH",
                                                        "MASTER_SSL_CERT",
                                                        "MASTER_SSL_CIPHER",
                                                        "MASTER_SSL_CRL",
                                                        "MASTER_SSL_CRLPATH",
                                                        "MASTER_SSL_KEY",
                                                        "MASTER_SSL_VERIFY_SERVER_CERT",
                                                        "MASTER_TLS_VERSION",
                                                        "MASTER_USER",
                                                        "MATCH",
                                                        "MAXVALUE",
                                                        "MAX_CONNECTIONS_PER_HOUR",
                                                        "MAX_QUERIES_PER_HOUR",
                                                        "MAX_ROWS",
                                                        "MAX_SIZE",
                                                        "MAX_STATEMENT_TIME",
                                                        "MAX_UPDATES_PER_HOUR",
                                                        "MAX_USER_CONNECTIONS",
                                                        "MEDIUM",
                                                        "MEDIUMBLOB",
                                                        "MEDIUMINT",
                                                        "MEDIUMTEXT",
                                                        "MEMORY",
                                                        "MERGE",
                                                        "MESSAGE_TEXT",
                                                        "MICROSECOND",
                                                        "MIDDLEINT",
                                                        "MIGRATE",
                                                        "MINUTE",
                                                        "MINUTE_MICROSECOND",
                                                        "MINUTE_SECOND",
                                                        "MIN_ROWS",
                                                        "MOD",
                                                        "MODE",
                                                        "MODIFIES",
                                                        "MODIFY",
                                                        "MONTH",
                                                        "MULTILINESTRING",
                                                        "MULTIPOINT",
                                                        "MULTIPOLYGON",
                                                        "MUTEX",
                                                        "MYSQL_ERRNO",
                                                        "NAME",
                                                        "NAMES",
                                                        "NATIONAL",
                                                        "NATURAL",
                                                        "NCHAR",
                                                        "NDB",
                                                        "NDBCLUSTER",
                                                        "NEVER",
                                                        "NEW",
                                                        "NEXT",
                                                        "NO",
                                                        "NODEGROUP",
                                                        "NONBLOCKING",
                                                        "NONE",
                                                        "NOT",
                                                        "NO_WAIT",
                                                        "NO_WRITE_TO_BINLOG",
                                                        "NULL",
                                                        "NUMBER",
                                                        "NUMERIC",
                                                        "NVARCHAR",
                                                        "OFFSET",
                                                        "OLD_PASSWORD",
                                                        "ON",
                                                        "ONE",
                                                        "ONLY",
                                                        "OPEN",
                                                        "OPTIMIZE",
                                                        "OPTIMIZER_COSTS",
                                                        "OPTION",
                                                        "OPTIONALLY",
                                                        "OPTIONS",
                                                        "OR",
                                                        "ORDER",
                                                        "OUT",
                                                        "OUTER",
                                                        "OUTFILE",
                                                        "OWNER",
                                                        "PACK_KEYS",
                                                        "PAGE",
                                                        "PARSER",
                                                        "PARSE_GCOL_EXPR",
                                                        "PARTIAL",
                                                        "PARTITION",
                                                        "PARTITIONING",
                                                        "PARTITIONS",
                                                        "PASSWORD",
                                                        "PHASE",
                                                        "PLUGIN",
                                                        "PLUGINS",
                                                        "PLUGIN_DIR",
                                                        "POINT",
                                                        "POLYGON",
                                                        "PORT",
                                                        "PRECEDES",
                                                        "PRECISION",
                                                        "PREPARE",
                                                        "PRESERVE",
                                                        "PREV",
                                                        "PRIMARY",
                                                        "PRIVILEGES",
                                                        "PROCEDURE",
                                                        "PROCESSLIST",
                                                        "PROFILE",
                                                        "PROFILES",
                                                        "PROXY",
                                                        "PURGE",
                                                        "QUARTER",
                                                        "QUERY",
                                                        "QUICK",
                                                        "RANGE",
                                                        "READ",
                                                        "READS",
                                                        "READ_ONLY",
                                                        "READ_WRITE",
                                                        "REAL",
                                                        "REBUILD",
                                                        "RECOVER",
                                                        "REDOFILE",
                                                        "REDO_BUFFER_SIZE",
                                                        "REDUNDANT",
                                                        "REFERENCES",
                                                        "REGEXP",
                                                        "RELAY",
                                                        "RELAYLOG",
                                                        "RELAY_LOG_FILE",
                                                        "RELAY_LOG_POS",
                                                        "RELAY_THREAD",
                                                        "RELEASE",
                                                        "RELOAD",
                                                        "REMOVE",
                                                        "RENAME",
                                                        "REORGANIZE",
                                                        "REPAIR",
                                                        "REPEAT",
                                                        "REPEATABLE",
                                                        "REPLACE",
                                                        "REPLICATE_DO_DB",
                                                        "REPLICATE_DO_TABLE",
                                                        "REPLICATE_IGNORE_DB",
                                                        "REPLICATE_IGNORE_TABLE",
                                                        "REPLICATE_REWRITE_DB",
                                                        "REPLICATE_WILD_DO_TABLE",
                                                        "REPLICATE_WILD_IGNORE_TABLE",
                                                        "REPLICATION",
                                                        "REQUIRE",
                                                        "RESET",
                                                        "RESIGNAL",
                                                        "RESTORE",
                                                        "RESTRICT",
                                                        "RESUME",
                                                        "RETURN",
                                                        "RETURNED_SQLSTATE",
                                                        "RETURNS",
                                                        "REVERSE",
                                                        "REVOKE",
                                                        "RIGHT",
                                                        "RLIKE",
                                                        "ROLLBACK",
                                                        "ROLLUP",
                                                        "ROTATE",
                                                        "ROUTINE",
                                                        "ROW",
                                                        "ROWS",
                                                        "ROW_COUNT",
                                                        "ROW_FORMAT",
                                                        "RTREE",
                                                        "SAVEPOINT",
                                                        "SCHEDULE",
                                                        "SCHEMA",
                                                        "SCHEMAS",
                                                        "SCHEMA_NAME",
                                                        "SECOND",
                                                        "SECOND_MICROSECOND",
                                                        "SECURITY",
                                                        "SELECT",
                                                        "SENSITIVE",
                                                        "SEPARATOR",
                                                        "SERIAL",
                                                        "SERIALIZABLE",
                                                        "SERVER",
                                                        "SESSION",
                                                        "SET",
                                                        "SHARE",
                                                        "SHARED",
                                                        "SHOW",
                                                        "SHUTDOWN",
                                                        "SIGNAL",
                                                        "SIGNED",
                                                        "SIMPLE",
                                                        "SLAVE",
                                                        "SLOW",
                                                        "SMALLINT",
                                                        "SNAPSHOT",
                                                        "SOCKET",
                                                        "SOME",
                                                        "SONAME",
                                                        "SOUNDS",
                                                        "SOURCE",
                                                        "SPATIAL",
                                                        "SPECIFIC",
                                                        "SQL",
                                                        "SQLEXCEPTION",
                                                        "SQLSTATE",
                                                        "SQLWARNING",
                                                        "SQL_AFTER_GTIDS",
                                                        "SQL_AFTER_MTS_GAPS",
                                                        "SQL_BEFORE_GTIDS",
                                                        "SQL_BIG_RESULT",
                                                        "SQL_BUFFER_RESULT",
                                                        "SQL_CACHE",
                                                        "SQL_CALC_FOUND_ROWS",
                                                        "SQL_NO_CACHE",
                                                        "SQL_SMALL_RESULT",
                                                        "SQL_THREAD",
                                                        "SQL_TSI_DAY",
                                                        "SQL_TSI_HOUR",
                                                        "SQL_TSI_MINUTE",
                                                        "SQL_TSI_MONTH",
                                                        "SQL_TSI_QUARTER",
                                                        "SQL_TSI_SECOND",
                                                        "SQL_TSI_WEEK",
                                                        "SQL_TSI_YEAR",
                                                        "SSL",
                                                        "STACKED",
                                                        "START",
                                                        "STARTING",
                                                        "STARTS",
                                                        "STATS_AUTO_RECALC",
                                                        "STATS_PERSISTENT",
                                                        "STATS_SAMPLE_PAGES",
                                                        "STATUS",
                                                        "STOP",
                                                        "STORAGE",
                                                        "STORED",
                                                        "STRAIGHT_JOIN",
                                                        "STRING",
                                                        "SUBCLASS_ORIGIN",
                                                        "SUBJECT",
                                                        "SUBPARTITION",
                                                        "SUBPARTITIONS",
                                                        "SUPER",
                                                        "SUSPEND",
                                                        "SWAPS",
                                                        "SWITCHES",
                                                        "TABLE",
                                                        "TABLES",
                                                        "TABLESPACE",
                                                        "TABLE_CHECKSUM",
                                                        "TABLE_NAME",
                                                        "TEMPORARY",
                                                        "TEMPTABLE",
                                                        "TERMINATED",
                                                        "TEXT",
                                                        "THAN",
                                                        "THEN",
                                                        "TIME",
                                                        "TIMESTAMP",
                                                        "TIMESTAMPADD",
                                                        "TIMESTAMPDIFF",
                                                        "TINYBLOB",
                                                        "TINYINT",
                                                        "TINYTEXT",
                                                        "TO",
                                                        "TRAILING",
                                                        "TRANSACTION",
                                                        "TRIGGER",
                                                        "TRIGGERS",
                                                        "TRUE",
                                                        "TRUNCATE",
                                                        "TYPE",
                                                        "TYPES",
                                                        "UNCOMMITTED",
                                                        "UNDEFINED",
                                                        "UNDO",
                                                        "UNDOFILE",
                                                        "UNDO_BUFFER_SIZE",
                                                        "UNICODE",
                                                        "UNINSTALL",
                                                        "UNION",
                                                        "UNIQUE",
                                                        "UNKNOWN",
                                                        "UNLOCK",
                                                        "UNSIGNED",
                                                        "UNTIL",
                                                        "UPDATE",
                                                        "UPGRADE",
                                                        "USAGE",
                                                        "USE",
                                                        "USER",
                                                        "USER_RESOURCES",
                                                        "USE_FRM",
                                                        "USING",
                                                        "UTC_DATE",
                                                        "UTC_TIME",
                                                        "UTC_TIMESTAMP",
                                                        "VALIDATION",
                                                        "VALUE",
                                                        "VALUES",
                                                        "VARBINARY",
                                                        "VARCHAR",
                                                        "VARCHARACTER",
                                                        "VARIABLES",
                                                        "VARYING",
                                                        "VIEW",
                                                        "VIRTUAL",
                                                        "WAIT",
                                                        "WARNINGS",
                                                        "WEEK",
                                                        "WEIGHT_STRING",
                                                        "WHEN",
                                                        "WHERE",
                                                        "WHILE",
                                                        "WITH",
                                                        "WITHOUT",
                                                        "WORK",
                                                        "WRAPPER",
                                                        "WRITE",
                                                        "X509",
                                                        "XA",
                                                        "XID",
                                                        "XML",
                                                        "XOR",
                                                        "YEAR",
                                                        "YEAR_MONTH",
                                                        "ZEROFILL",
                                                        "ID",
                                                        "FLOAT_NUMBER",
                                                        "INT_NUMBER",
                                                        "SQUOTED_STRING",
                                                        "DQUOTED_STRING",
                                                        "BQUOTED_STRING",
                                                        "NON_DIGIT",
                                                        "BLOCK_COMMENT",
                                                        "LINE_COMMENT",
                                                        "WHITE_SPACE",
                                                        "LPAREN",
                                                        "RPAREN",
                                                        "PERIOD",
                                                        "COMMA",
                                                        "COLON",
                                                        "SEMI",
                                                        "EQUAL"};

dfa::Vocabulary mysqlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> mysqlParser::_tokenNames;

mysqlParser::Initializer::Initializer()
{
    for (size_t i = 0; i < _symbolicNames.size(); ++i)
    {
        std::string name = _vocabulary.getLiteralName(i);
        if (name.empty())
        {
            name = _vocabulary.getSymbolicName(i);
        }

        if (name.empty())
        {
            _tokenNames.push_back("<INVALID>");
        }
        else
        {
            _tokenNames.push_back(name);
        }
    }

    _serializedATN = {
        0x3,   0x430, 0xd6d1, 0x8206, 0xad2d, 0x4417, 0xaef1, 0x8d80, 0xaadd, 0x3,   0x285, 0x607,
        0x4,   0x2,   0x9,    0x2,    0x4,    0x3,    0x9,    0x3,    0x4,    0x4,   0x9,   0x4,
        0x4,   0x5,   0x9,    0x5,    0x4,    0x6,    0x9,    0x6,    0x4,    0x7,   0x9,   0x7,
        0x4,   0x8,   0x9,    0x8,    0x4,    0x9,    0x9,    0x9,    0x4,    0xa,   0x9,   0xa,
        0x4,   0xb,   0x9,    0xb,    0x4,    0xc,    0x9,    0xc,    0x4,    0xd,   0x9,   0xd,
        0x4,   0xe,   0x9,    0xe,    0x4,    0xf,    0x9,    0xf,    0x4,    0x10,  0x9,   0x10,
        0x4,   0x11,  0x9,    0x11,   0x4,    0x12,   0x9,    0x12,   0x4,    0x13,  0x9,   0x13,
        0x4,   0x14,  0x9,    0x14,   0x4,    0x15,   0x9,    0x15,   0x4,    0x16,  0x9,   0x16,
        0x4,   0x17,  0x9,    0x17,   0x4,    0x18,   0x9,    0x18,   0x4,    0x19,  0x9,   0x19,
        0x4,   0x1a,  0x9,    0x1a,   0x4,    0x1b,   0x9,    0x1b,   0x4,    0x1c,  0x9,   0x1c,
        0x4,   0x1d,  0x9,    0x1d,   0x4,    0x1e,   0x9,    0x1e,   0x4,    0x1f,  0x9,   0x1f,
        0x4,   0x20,  0x9,    0x20,   0x4,    0x21,   0x9,    0x21,   0x4,    0x22,  0x9,   0x22,
        0x4,   0x23,  0x9,    0x23,   0x4,    0x24,   0x9,    0x24,   0x4,    0x25,  0x9,   0x25,
        0x4,   0x26,  0x9,    0x26,   0x4,    0x27,   0x9,    0x27,   0x4,    0x28,  0x9,   0x28,
        0x4,   0x29,  0x9,    0x29,   0x4,    0x2a,   0x9,    0x2a,   0x4,    0x2b,  0x9,   0x2b,
        0x4,   0x2c,  0x9,    0x2c,   0x4,    0x2d,   0x9,    0x2d,   0x4,    0x2e,  0x9,   0x2e,
        0x4,   0x2f,  0x9,    0x2f,   0x4,    0x30,   0x9,    0x30,   0x4,    0x31,  0x9,   0x31,
        0x4,   0x32,  0x9,    0x32,   0x4,    0x33,   0x9,    0x33,   0x4,    0x34,  0x9,   0x34,
        0x4,   0x35,  0x9,    0x35,   0x4,    0x36,   0x9,    0x36,   0x4,    0x37,  0x9,   0x37,
        0x4,   0x38,  0x9,    0x38,   0x4,    0x39,   0x9,    0x39,   0x4,    0x3a,  0x9,   0x3a,
        0x4,   0x3b,  0x9,    0x3b,   0x4,    0x3c,   0x9,    0x3c,   0x4,    0x3d,  0x9,   0x3d,
        0x4,   0x3e,  0x9,    0x3e,   0x4,    0x3f,   0x9,    0x3f,   0x4,    0x40,  0x9,   0x40,
        0x4,   0x41,  0x9,    0x41,   0x4,    0x42,   0x9,    0x42,   0x4,    0x43,  0x9,   0x43,
        0x4,   0x44,  0x9,    0x44,   0x4,    0x45,   0x9,    0x45,   0x4,    0x46,  0x9,   0x46,
        0x4,   0x47,  0x9,    0x47,   0x4,    0x48,   0x9,    0x48,   0x4,    0x49,  0x9,   0x49,
        0x4,   0x4a,  0x9,    0x4a,   0x4,    0x4b,   0x9,    0x4b,   0x4,    0x4c,  0x9,   0x4c,
        0x4,   0x4d,  0x9,    0x4d,   0x4,    0x4e,   0x9,    0x4e,   0x4,    0x4f,  0x9,   0x4f,
        0x4,   0x50,  0x9,    0x50,   0x4,    0x51,   0x9,    0x51,   0x4,    0x52,  0x9,   0x52,
        0x4,   0x53,  0x9,    0x53,   0x4,    0x54,   0x9,    0x54,   0x4,    0x55,  0x9,   0x55,
        0x4,   0x56,  0x9,    0x56,   0x4,    0x57,   0x9,    0x57,   0x4,    0x58,  0x9,   0x58,
        0x4,   0x59,  0x9,    0x59,   0x4,    0x5a,   0x9,    0x5a,   0x4,    0x5b,  0x9,   0x5b,
        0x4,   0x5c,  0x9,    0x5c,   0x4,    0x5d,   0x9,    0x5d,   0x4,    0x5e,  0x9,   0x5e,
        0x4,   0x5f,  0x9,    0x5f,   0x4,    0x60,   0x9,    0x60,   0x4,    0x61,  0x9,   0x61,
        0x4,   0x62,  0x9,    0x62,   0x4,    0x63,   0x9,    0x63,   0x4,    0x64,  0x9,   0x64,
        0x4,   0x65,  0x9,    0x65,   0x4,    0x66,   0x9,    0x66,   0x4,    0x67,  0x9,   0x67,
        0x4,   0x68,  0x9,    0x68,   0x4,    0x69,   0x9,    0x69,   0x4,    0x6a,  0x9,   0x6a,
        0x4,   0x6b,  0x9,    0x6b,   0x4,    0x6c,   0x9,    0x6c,   0x4,    0x6d,  0x9,   0x6d,
        0x4,   0x6e,  0x9,    0x6e,   0x4,    0x6f,   0x9,    0x6f,   0x4,    0x70,  0x9,   0x70,
        0x4,   0x71,  0x9,    0x71,   0x4,    0x72,   0x9,    0x72,   0x4,    0x73,  0x9,   0x73,
        0x4,   0x74,  0x9,    0x74,   0x4,    0x75,   0x9,    0x75,   0x4,    0x76,  0x9,   0x76,
        0x4,   0x77,  0x9,    0x77,   0x4,    0x78,   0x9,    0x78,   0x4,    0x79,  0x9,   0x79,
        0x4,   0x7a,  0x9,    0x7a,   0x4,    0x7b,   0x9,    0x7b,   0x4,    0x7c,  0x9,   0x7c,
        0x4,   0x7d,  0x9,    0x7d,   0x4,    0x7e,   0x9,    0x7e,   0x4,    0x7f,  0x9,   0x7f,
        0x4,   0x80,  0x9,    0x80,   0x4,    0x81,   0x9,    0x81,   0x3,    0x2,   0x3,   0x2,
        0x3,   0x2,   0x7,    0x2,    0x106,  0xa,    0x2,    0xc,    0x2,    0xe,   0x2,   0x109,
        0xb,   0x2,   0x3,    0x2,    0x3,    0x2,    0x3,    0x3,    0x3,    0x3,   0x3,   0x3,
        0x3,   0x3,   0x5,    0x3,    0x111,  0xa,    0x3,    0x3,    0x4,    0x3,   0x4,   0x3,
        0x4,   0x3,   0x4,    0x3,    0x4,    0x3,    0x5,    0x3,    0x5,    0x5,   0x5,   0x11a,
        0xa,   0x5,   0x3,    0x5,    0x3,    0x5,    0x3,    0x5,    0x5,    0x5,   0x11f, 0xa,
        0x5,   0x3,   0x5,    0x3,    0x5,    0x5,    0x5,    0x123,  0xa,    0x5,   0x3,   0x6,
        0x3,   0x6,   0x3,    0x6,    0x7,    0x6,    0x128,  0xa,    0x6,    0xc,   0x6,   0xe,
        0x6,   0x12b, 0xb,    0x6,    0x3,    0x7,    0x3,    0x7,    0x5,    0x7,   0x12f, 0xa,
        0x7,   0x3,   0x7,    0x3,    0x7,    0x3,    0x7,    0x3,    0x7,    0x5,   0x7,   0x135,
        0xa,   0x7,   0x3,    0x7,    0x3,    0x7,    0x3,    0x7,    0x5,    0x7,   0x13a, 0xa,
        0x7,   0x3,   0x7,    0x5,    0x7,    0x13d,  0xa,    0x7,    0x3,    0x7,   0x3,   0x7,
        0x5,   0x7,   0x141,  0xa,    0x7,    0x3,    0x7,    0x3,    0x7,    0x3,   0x7,   0x3,
        0x7,   0x5,   0x7,    0x147,  0xa,    0x7,    0x3,    0x7,    0x3,    0x7,   0x3,   0x7,
        0x3,   0x7,   0x3,    0x7,    0x3,    0x7,    0x3,    0x7,    0x3,    0x7,   0x5,   0x7,
        0x151, 0xa,   0x7,    0x3,    0x7,    0x3,    0x7,    0x5,    0x7,    0x155, 0xa,   0x7,
        0x3,   0x7,   0x3,    0x7,    0x3,    0x7,    0x3,    0x7,    0x5,    0x7,   0x15b, 0xa,
        0x7,   0x3,   0x7,    0x3,    0x7,    0x5,    0x7,    0x15f,  0xa,    0x7,   0x3,   0x7,
        0x5,   0x7,   0x162,  0xa,    0x7,    0x3,    0x7,    0x5,    0x7,    0x165, 0xa,   0x7,
        0x3,   0x7,   0x5,    0x7,    0x168,  0xa,    0x7,    0x3,    0x7,    0x5,   0x7,   0x16b,
        0xa,   0x7,   0x3,    0x7,    0x3,    0x7,    0x5,    0x7,    0x16f,  0xa,   0x7,   0x3,
        0x8,   0x3,   0x8,    0x3,    0x8,    0x3,    0x8,    0x3,    0x8,    0x3,   0x8,   0x5,
        0x8,   0x177, 0xa,    0x8,    0x3,    0x9,    0x5,    0x9,    0x17a,  0xa,   0x9,   0x3,
        0x9,   0x3,   0x9,    0x3,    0x9,    0x5,    0x9,    0x17f,  0xa,    0x9,   0x3,   0x9,
        0x3,   0x9,   0x3,    0x9,    0x3,    0x9,    0x3,    0x9,    0x5,    0x9,   0x186, 0xa,
        0x9,   0x3,   0x9,    0x5,    0x9,    0x189,  0xa,    0x9,    0x3,    0x9,   0x3,   0x9,
        0x3,   0x9,   0x3,    0x9,    0x5,    0x9,    0x18f,  0xa,    0x9,    0x3,   0x9,   0x3,
        0x9,   0x5,   0x9,    0x193,  0xa,    0x9,    0x3,    0x9,    0x5,    0x9,   0x196, 0xa,
        0x9,   0x3,   0x9,    0x5,    0x9,    0x199,  0xa,    0x9,    0x3,    0x9,   0x3,   0x9,
        0x3,   0x9,   0x3,    0x9,    0x3,    0x9,    0x5,    0x9,    0x1a0,  0xa,   0x9,   0x3,
        0x9,   0x5,   0x9,    0x1a3,  0xa,    0x9,    0x3,    0x9,    0x3,    0x9,   0x3,   0x9,
        0x3,   0x9,   0x5,    0x9,    0x1a9,  0xa,    0x9,    0x3,    0x9,    0x3,   0x9,   0x3,
        0x9,   0x5,   0x9,    0x1ae,  0xa,    0x9,    0x3,    0x9,    0x3,    0x9,   0x3,   0x9,
        0x5,   0x9,   0x1b3,  0xa,    0x9,    0x3,    0xa,    0x3,    0xa,    0x3,   0xa,   0x5,
        0xa,   0x1b8, 0xa,    0xa,    0x3,    0xa,    0x3,    0xa,    0x3,    0xa,   0x5,   0xa,
        0x1bd, 0xa,   0xa,    0x3,    0xb,    0x3,    0xb,    0x3,    0xb,    0x5,   0xb,   0x1c2,
        0xa,   0xb,   0x3,    0xb,    0x3,    0xb,    0x5,    0xb,    0x1c6,  0xa,   0xb,   0x3,
        0xb,   0x5,   0xb,    0x1c9,  0xa,    0xb,    0x3,    0xb,    0x3,    0xb,   0x5,   0xb,
        0x1cd, 0xa,   0xb,    0x3,    0xb,    0x5,    0xb,    0x1d0,  0xa,    0xb,   0x3,   0xb,
        0x5,   0xb,   0x1d3,  0xa,    0xb,    0x3,    0xb,    0x3,    0xb,    0x5,   0xb,   0x1d7,
        0xa,   0xb,   0x3,    0xb,    0x3,    0xb,    0x5,    0xb,    0x1db,  0xa,   0xb,   0x3,
        0xb,   0x3,   0xb,    0x5,    0xb,    0x1df,  0xa,    0xb,    0x3,    0xb,   0x3,   0xb,
        0x3,   0xb,   0x5,    0xb,    0x1e4,  0xa,    0xb,    0x3,    0xc,    0x3,   0xc,   0x5,
        0xc,   0x1e8, 0xa,    0xc,    0x3,    0xc,    0x3,    0xc,    0x3,    0xc,   0x5,   0xc,
        0x1ed, 0xa,   0xc,    0x3,    0xc,    0x3,    0xc,    0x5,    0xc,    0x1f1, 0xa,   0xc,
        0x5,   0xc,   0x1f3,  0xa,    0xc,    0x3,    0xc,    0x3,    0xc,    0x5,   0xc,   0x1f7,
        0xa,   0xc,   0x3,    0xc,    0x3,    0xc,    0x3,    0xc,    0x5,    0xc,   0x1fc, 0xa,
        0xc,   0x3,   0xc,    0x5,    0xc,    0x1ff,  0xa,    0xc,    0x3,    0xc,   0x5,   0xc,
        0x202, 0xa,   0xc,    0x3,    0xd,    0x3,    0xd,    0x3,    0xd,    0x3,   0xd,   0x3,
        0xd,   0x5,   0xd,    0x209,  0xa,    0xd,    0x3,    0xd,    0x5,    0xd,   0x20c, 0xa,
        0xd,   0x3,   0xd,    0x5,    0xd,    0x20f,  0xa,    0xd,    0x3,    0xd,   0x3,   0xd,
        0x3,   0xd,   0x3,    0xd,    0x3,    0xd,    0x5,    0xd,    0x216,  0xa,   0xd,   0x3,
        0xd,   0x3,   0xd,    0x5,    0xd,    0x21a,  0xa,    0xd,    0x3,    0xd,   0x5,   0xd,
        0x21d, 0xa,   0xd,    0x3,    0xd,    0x5,    0xd,    0x220,  0xa,    0xd,   0x3,   0xd,
        0x3,   0xd,   0x3,    0xd,    0x3,    0xd,    0x3,    0xd,    0x5,    0xd,   0x227, 0xa,
        0xd,   0x3,   0xd,    0x3,    0xd,    0x3,    0xd,    0x3,    0xd,    0x3,   0xd,   0x5,
        0xd,   0x22e, 0xa,    0xd,    0x3,    0xd,    0x5,    0xd,    0x231,  0xa,   0xd,   0x3,
        0xd,   0x5,   0xd,    0x234,  0xa,    0xd,    0x3,    0xd,    0x5,    0xd,   0x237, 0xa,
        0xd,   0x3,   0xd,    0x3,    0xd,    0x3,    0xd,    0x3,    0xd,    0x3,   0xd,   0x5,
        0xd,   0x23e, 0xa,    0xd,    0x3,    0xd,    0x3,    0xd,    0x3,    0xd,   0x3,   0xd,
        0x3,   0xd,   0x3,    0xd,    0x5,    0xd,    0x246,  0xa,    0xd,    0x3,   0xd,   0x5,
        0xd,   0x249, 0xa,    0xd,    0x3,    0xd,    0x5,    0xd,    0x24c,  0xa,   0xd,   0x3,
        0xd,   0x5,   0xd,    0x24f,  0xa,    0xd,    0x3,    0xd,    0x3,    0xd,   0x3,   0xd,
        0x5,   0xd,   0x254,  0xa,    0xd,    0x3,    0xd,    0x5,    0xd,    0x257, 0xa,   0xd,
        0x3,   0xd,   0x3,    0xd,    0x5,    0xd,    0x25b,  0xa,    0xd,    0x3,   0xe,   0x3,
        0xe,   0x5,   0xe,    0x25f,  0xa,    0xe,    0x3,    0xe,    0x3,    0xe,   0x3,   0xe,
        0x5,   0xe,   0x264,  0xa,    0xe,    0x3,    0xe,    0x3,    0xe,    0x3,   0xe,   0x5,
        0xe,   0x269, 0xa,    0xe,    0x3,    0xe,    0x3,    0xe,    0x5,    0xe,   0x26d, 0xa,
        0xe,   0x3,   0xe,    0x3,    0xe,    0x3,    0xe,    0x5,    0xe,    0x272, 0xa,   0xe,
        0x3,   0xe,   0x3,    0xe,    0x5,    0xe,    0x276,  0xa,    0xe,    0x3,   0xe,   0x3,
        0xe,   0x3,   0xe,    0x5,    0xe,    0x27b,  0xa,    0xe,    0x3,    0xe,   0x3,   0xe,
        0x3,   0xe,   0x5,    0xe,    0x280,  0xa,    0xe,    0x3,    0xe,    0x3,   0xe,   0x3,
        0xe,   0x5,   0xe,    0x285,  0xa,    0xe,    0x3,    0xe,    0x3,    0xe,   0x3,   0xe,
        0x3,   0xe,   0x5,    0xe,    0x28b,  0xa,    0xe,    0x3,    0xe,    0x3,   0xe,   0x3,
        0xe,   0x5,   0xe,    0x290,  0xa,    0xe,    0x3,    0xe,    0x3,    0xe,   0x3,   0xe,
        0x5,   0xe,   0x295,  0xa,    0xe,    0x3,    0xe,    0x3,    0xe,    0x3,   0xe,   0x3,
        0xe,   0x5,   0xe,    0x29b,  0xa,    0xe,    0x3,    0xe,    0x3,    0xe,   0x3,   0xe,
        0x5,   0xe,   0x2a0,  0xa,    0xe,    0x3,    0xe,    0x3,    0xe,    0x3,   0xe,   0x5,
        0xe,   0x2a5, 0xa,    0xe,    0x3,    0xe,    0x3,    0xe,    0x3,    0xe,   0x5,   0xe,
        0x2aa, 0xa,   0xe,    0x3,    0xe,    0x3,    0xe,    0x3,    0xe,    0x5,   0xe,   0x2af,
        0xa,   0xe,   0x3,    0xe,    0x3,    0xe,    0x3,    0xe,    0x5,    0xe,   0x2b4, 0xa,
        0xe,   0x3,   0xe,    0x3,    0xe,    0x3,    0xe,    0x5,    0xe,    0x2b9, 0xa,   0xe,
        0x3,   0xe,   0x3,    0xe,    0x3,    0xe,    0x5,    0xe,    0x2be,  0xa,   0xe,   0x3,
        0xe,   0x3,   0xe,    0x3,    0xe,    0x5,    0xe,    0x2c3,  0xa,    0xe,   0x3,   0xe,
        0x3,   0xe,   0x3,    0xe,    0x5,    0xe,    0x2c8,  0xa,    0xe,    0x3,   0xe,   0x3,
        0xe,   0x3,   0xe,    0x5,    0xe,    0x2cd,  0xa,    0xe,    0x3,    0xe,   0x3,   0xe,
        0x3,   0xe,   0x3,    0xe,    0x3,    0xe,    0x5,    0xe,    0x2d4,  0xa,   0xe,   0x3,
        0xe,   0x5,   0xe,    0x2d7,  0xa,    0xe,    0x3,    0xf,    0x3,    0xf,   0x3,   0xf,
        0x3,   0xf,   0x3,    0xf,    0x5,    0xf,    0x2de,  0xa,    0xf,    0x3,   0xf,   0x3,
        0xf,   0x3,   0xf,    0x3,    0xf,    0x3,    0xf,    0x5,    0xf,    0x2e5, 0xa,   0xf,
        0x5,   0xf,   0x2e7,  0xa,    0xf,    0x3,    0xf,    0x5,    0xf,    0x2ea, 0xa,   0xf,
        0x3,   0x10,  0x3,    0x10,   0x3,    0x10,   0x3,    0x10,   0x7,    0x10,  0x2f0, 0xa,
        0x10,  0xc,   0x10,   0xe,    0x10,   0x2f3,  0xb,    0x10,   0x3,    0x10,  0x3,   0x10,
        0x3,   0x11,  0x5,    0x11,   0x2f8,  0xa,    0x11,   0x3,    0x11,   0x3,   0x11,  0x3,
        0x11,  0x5,   0x11,   0x2fd,  0xa,    0x11,   0x3,    0x11,   0x3,    0x11,  0x3,   0x11,
        0x3,   0x11,  0x5,    0x11,   0x303,  0xa,    0x11,   0x3,    0x11,   0x3,   0x11,  0x3,
        0x11,  0x3,   0x11,   0x3,    0x11,   0x5,    0x11,   0x30a,  0xa,    0x11,  0x3,   0x11,
        0x3,   0x11,  0x3,    0x11,   0x3,    0x11,   0x5,    0x11,   0x310,  0xa,   0x11,  0x5,
        0x11,  0x312, 0xa,    0x11,   0x3,    0x12,   0x5,    0x12,   0x315,  0xa,   0x12,  0x3,
        0x12,  0x3,   0x12,   0x3,    0x12,   0x5,    0x12,   0x31a,  0xa,    0x12,  0x3,   0x12,
        0x3,   0x12,  0x3,    0x12,   0x3,    0x12,   0x5,    0x12,   0x320,  0xa,   0x12,  0x3,
        0x12,  0x5,   0x12,   0x323,  0xa,    0x12,   0x3,    0x13,   0x3,    0x13,  0x3,   0x13,
        0x5,   0x13,  0x328,  0xa,    0x13,   0x3,    0x13,   0x3,    0x13,   0x5,   0x13,  0x32c,
        0xa,   0x13,  0x3,    0x14,   0x3,    0x14,   0x3,    0x14,   0x3,    0x14,  0x7,   0x14,
        0x332, 0xa,   0x14,   0xc,    0x14,   0xe,    0x14,   0x335,  0xb,    0x14,  0x3,   0x14,
        0x3,   0x14,  0x3,    0x15,   0x3,    0x15,   0x3,    0x15,   0x3,    0x15,  0x3,   0x15,
        0x3,   0x15,  0x5,    0x15,   0x33f,  0xa,    0x15,   0x3,    0x15,   0x3,   0x15,  0x5,
        0x15,  0x343, 0xa,    0x15,   0x3,    0x16,   0x3,    0x16,   0x3,    0x16,  0x3,   0x16,
        0x3,   0x17,  0x5,    0x17,   0x34a,  0xa,    0x17,   0x3,    0x17,   0x3,   0x17,  0x5,
        0x17,  0x34e, 0xa,    0x17,   0x3,    0x17,   0x5,    0x17,   0x351,  0xa,   0x17,  0x3,
        0x17,  0x3,   0x17,   0x5,    0x17,   0x355,  0xa,    0x17,   0x3,    0x17,  0x5,   0x17,
        0x358, 0xa,   0x17,   0x3,    0x17,   0x3,    0x17,   0x3,    0x17,   0x5,   0x17,  0x35d,
        0xa,   0x17,  0x3,    0x17,   0x5,    0x17,   0x360,  0xa,    0x17,   0x3,   0x17,  0x3,
        0x17,  0x3,   0x17,   0x5,    0x17,   0x365,  0xa,    0x17,   0x3,    0x17,  0x5,   0x17,
        0x368, 0xa,   0x17,   0x3,    0x17,   0x3,    0x17,   0x5,    0x17,   0x36c, 0xa,   0x17,
        0x3,   0x17,  0x5,    0x17,   0x36f,  0xa,    0x17,   0x3,    0x17,   0x3,   0x17,  0x5,
        0x17,  0x373, 0xa,    0x17,   0x3,    0x17,   0x5,    0x17,   0x376,  0xa,   0x17,  0x3,
        0x17,  0x3,   0x17,   0x5,    0x17,   0x37a,  0xa,    0x17,   0x3,    0x17,  0x5,   0x17,
        0x37d, 0xa,   0x17,   0x3,    0x18,   0x3,    0x18,   0x5,    0x18,   0x381, 0xa,   0x18,
        0x3,   0x18,  0x3,    0x18,   0x3,    0x18,   0x3,    0x18,   0x3,    0x18,  0x3,   0x18,
        0x3,   0x18,  0x3,    0x18,   0x5,    0x18,   0x38b,  0xa,    0x18,   0x3,   0x19,  0x3,
        0x19,  0x3,   0x19,   0x5,    0x19,   0x390,  0xa,    0x19,   0x3,    0x19,  0x3,   0x19,
        0x5,   0x19,  0x394,  0xa,    0x19,   0x3,    0x19,   0x3,    0x19,   0x3,   0x19,  0x5,
        0x19,  0x399, 0xa,    0x19,   0x3,    0x19,   0x3,    0x19,   0x3,    0x19,  0x5,   0x19,
        0x39e, 0xa,   0x19,   0x3,    0x1a,   0x3,    0x1a,   0x3,    0x1a,   0x3,   0x1a,  0x7,
        0x1a,  0x3a4, 0xa,    0x1a,   0xc,    0x1a,   0xe,    0x1a,   0x3a7,  0xb,   0x1a,  0x3,
        0x1a,  0x3,   0x1a,   0x3,    0x1b,   0x3,    0x1b,   0x5,    0x1b,   0x3ad, 0xa,   0x1b,
        0x3,   0x1b,  0x7,    0x1b,   0x3b0,  0xa,    0x1b,   0xc,    0x1b,   0xe,   0x1b,  0x3b3,
        0xb,   0x1b,  0x3,    0x1c,   0x7,    0x1c,   0x3b6,  0xa,    0x1c,   0xc,   0x1c,  0xe,
        0x1c,  0x3b9, 0xb,    0x1c,   0x3,    0x1d,   0x3,    0x1d,   0x3,    0x1d,  0x3,   0x1d,
        0x7,   0x1d,  0x3bf,  0xa,    0x1d,   0xc,    0x1d,   0xe,    0x1d,   0x3c2, 0xb,   0x1d,
        0x3,   0x1d,  0x3,    0x1d,   0x3,    0x1e,   0x3,    0x1e,   0x3,    0x1e,  0x3,   0x1e,
        0x7,   0x1e,  0x3ca,  0xa,    0x1e,   0xc,    0x1e,   0xe,    0x1e,   0x3cd, 0xb,   0x1e,
        0x3,   0x1e,  0x3,    0x1e,   0x3,    0x1f,   0x3,    0x1f,   0x3,    0x1f,  0x3,   0x1f,
        0x7,   0x1f,  0x3d5,  0xa,    0x1f,   0xc,    0x1f,   0xe,    0x1f,   0x3d8, 0xb,   0x1f,
        0x3,   0x1f,  0x3,    0x1f,   0x3,    0x20,   0x3,    0x20,   0x3,    0x20,  0x3,   0x20,
        0x7,   0x20,  0x3e0,  0xa,    0x20,   0xc,    0x20,   0xe,    0x20,   0x3e3, 0xb,   0x20,
        0x3,   0x20,  0x3,    0x20,   0x3,    0x21,   0x3,    0x21,   0x3,    0x21,  0x3,   0x21,
        0x7,   0x21,  0x3eb,  0xa,    0x21,   0xc,    0x21,   0xe,    0x21,   0x3ee, 0xb,   0x21,
        0x3,   0x21,  0x3,    0x21,   0x3,    0x22,   0x3,    0x22,   0x3,    0x22,  0x3,   0x22,
        0x7,   0x22,  0x3f6,  0xa,    0x22,   0xc,    0x22,   0xe,    0x22,   0x3f9, 0xb,   0x22,
        0x3,   0x22,  0x3,    0x22,   0x3,    0x23,   0x3,    0x23,   0x3,    0x23,  0x3,   0x23,
        0x7,   0x23,  0x401,  0xa,    0x23,   0xc,    0x23,   0xe,    0x23,   0x404, 0xb,   0x23,
        0x3,   0x23,  0x3,    0x23,   0x3,    0x24,   0x3,    0x24,   0x3,    0x24,  0x3,   0x24,
        0x7,   0x24,  0x40c,  0xa,    0x24,   0xc,    0x24,   0xe,    0x24,   0x40f, 0xb,   0x24,
        0x3,   0x24,  0x3,    0x24,   0x3,    0x25,   0x3,    0x25,   0x3,    0x25,  0x3,   0x25,
        0x7,   0x25,  0x417,  0xa,    0x25,   0xc,    0x25,   0xe,    0x25,   0x41a, 0xb,   0x25,
        0x3,   0x25,  0x3,    0x25,   0x3,    0x26,   0x3,    0x26,   0x5,    0x26,  0x420, 0xa,
        0x26,  0x3,   0x27,   0x3,    0x27,   0x3,    0x27,   0x5,    0x27,   0x425, 0xa,   0x27,
        0x3,   0x27,  0x5,    0x27,   0x428,  0xa,    0x27,   0x3,    0x27,   0x3,   0x27,  0x3,
        0x28,  0x3,   0x28,   0x5,    0x28,   0x42e,  0xa,    0x28,   0x3,    0x28,  0x3,   0x28,
        0x3,   0x29,  0x3,    0x29,   0x3,    0x2a,   0x3,    0x2a,   0x3,    0x2a,  0x3,   0x2a,
        0x3,   0x2a,  0x5,    0x2a,   0x439,  0xa,    0x2a,   0x3,    0x2a,   0x5,   0x2a,  0x43c,
        0xa,   0x2a,  0x3,    0x2b,   0x3,    0x2b,   0x3,    0x2b,   0x3,    0x2b,  0x3,   0x2b,
        0x5,   0x2b,  0x443,  0xa,    0x2b,   0x3,    0x2b,   0x5,    0x2b,   0x446, 0xa,   0x2b,
        0x3,   0x2c,  0x3,    0x2c,   0x3,    0x2d,   0x3,    0x2d,   0x3,    0x2e,  0x3,   0x2e,
        0x3,   0x2f,  0x3,    0x2f,   0x3,    0x30,   0x3,    0x30,   0x3,    0x31,  0x3,   0x31,
        0x3,   0x32,  0x3,    0x32,   0x3,    0x33,   0x3,    0x33,   0x3,    0x34,  0x3,   0x34,
        0x3,   0x35,  0x3,    0x35,   0x3,    0x36,   0x3,    0x36,   0x3,    0x37,  0x3,   0x37,
        0x3,   0x38,  0x3,    0x38,   0x3,    0x39,   0x3,    0x39,   0x3,    0x3a,  0x3,   0x3a,
        0x3,   0x3b,  0x3,    0x3b,   0x3,    0x3c,   0x3,    0x3c,   0x5,    0x3c,  0x46a, 0xa,
        0x3c,  0x3,   0x3d,   0x3,    0x3d,   0x3,    0x3e,   0x3,    0x3e,   0x5,   0x3e,  0x470,
        0xa,   0x3e,  0x3,    0x3f,   0x3,    0x3f,   0x5,    0x3f,   0x474,  0xa,   0x3f,  0x3,
        0x40,  0x3,   0x40,   0x3,    0x41,   0x3,    0x41,   0x3,    0x42,   0x3,   0x42,  0x3,
        0x42,  0x3,   0x42,   0x3,    0x42,   0x3,    0x42,   0x5,    0x42,   0x480, 0xa,   0x42,
        0x3,   0x43,  0x3,    0x43,   0x3,    0x43,   0x3,    0x43,   0x3,    0x43,  0x3,   0x43,
        0x5,   0x43,  0x488,  0xa,    0x43,   0x3,    0x44,   0x3,    0x44,   0x3,   0x45,  0x3,
        0x45,  0x3,   0x46,   0x3,    0x46,   0x3,    0x47,   0x3,    0x47,   0x3,   0x47,  0x5,
        0x47,  0x493, 0xa,    0x47,   0x3,    0x47,   0x3,    0x47,   0x3,    0x47,  0x5,   0x47,
        0x498, 0xa,   0x47,   0x3,    0x48,   0x3,    0x48,   0x3,    0x49,   0x3,   0x49,  0x3,
        0x4a,  0x3,   0x4a,   0x3,    0x4b,   0x3,    0x4b,   0x3,    0x4c,   0x3,   0x4c,  0x3,
        0x4d,  0x3,   0x4d,   0x3,    0x4e,   0x3,    0x4e,   0x3,    0x4f,   0x3,   0x4f,  0x3,
        0x50,  0x3,   0x50,   0x3,    0x51,   0x3,    0x51,   0x3,    0x52,   0x3,   0x52,  0x3,
        0x53,  0x3,   0x53,   0x3,    0x54,   0x3,    0x54,   0x3,    0x55,   0x3,   0x55,  0x3,
        0x56,  0x3,   0x56,   0x3,    0x57,   0x3,    0x57,   0x3,    0x58,   0x3,   0x58,  0x3,
        0x59,  0x3,   0x59,   0x3,    0x5a,   0x3,    0x5a,   0x3,    0x5b,   0x3,   0x5b,  0x3,
        0x5c,  0x3,   0x5c,   0x3,    0x5d,   0x3,    0x5d,   0x3,    0x5d,   0x3,   0x5d,  0x3,
        0x5e,  0x3,   0x5e,   0x3,    0x5f,   0x3,    0x5f,   0x3,    0x60,   0x3,   0x60,  0x3,
        0x61,  0x3,   0x61,   0x3,    0x62,   0x3,    0x62,   0x3,    0x63,   0x3,   0x63,  0x3,
        0x64,  0x3,   0x64,   0x3,    0x64,   0x5,    0x64,   0x4d7,  0xa,    0x64,  0x3,   0x64,
        0x3,   0x64,  0x3,    0x65,   0x3,    0x65,   0x3,    0x66,   0x3,    0x66,  0x3,   0x67,
        0x3,   0x67,  0x3,    0x68,   0x3,    0x68,   0x3,    0x69,   0x3,    0x69,  0x3,   0x6a,
        0x3,   0x6a,  0x3,    0x6b,   0x3,    0x6b,   0x3,    0x6b,   0x3,    0x6b,  0x3,   0x6b,
        0x3,   0x6b,  0x5,    0x6b,   0x4ed,  0xa,    0x6b,   0x3,    0x6c,   0x3,   0x6c,  0x3,
        0x6d,  0x3,   0x6d,   0x3,    0x6e,   0x3,    0x6e,   0x3,    0x6f,   0x3,   0x6f,  0x3,
        0x70,  0x3,   0x70,   0x3,    0x71,   0x3,    0x71,   0x3,    0x72,   0x3,   0x72,  0x5,
        0x72,  0x4fd, 0xa,    0x72,   0x3,    0x72,   0x3,    0x72,   0x3,    0x72,  0x5,   0x72,
        0x502, 0xa,   0x72,   0x3,    0x72,   0x5,    0x72,   0x505,  0xa,    0x72,  0x3,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x5,    0x73,   0x50a,  0xa,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x5,    0x73,   0x50f,  0xa,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x5,   0x73,  0x513,  0xa,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x5,    0x73,   0x51a,  0xa,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x3,   0x73,  0x5,    0x73,   0x51f,  0xa,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x3,    0x73,   0x3,    0x73,   0x5,    0x73,   0x527, 0xa,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x5,    0x73,   0x52b,  0xa,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x3,    0x73,   0x5,    0x73,   0x531,  0xa,    0x73,  0x3,   0x73,
        0x3,   0x73,  0x5,    0x73,   0x535,  0xa,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x5,   0x73,   0x53a,  0xa,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x5,   0x73,  0x53f,  0xa,    0x73,   0x3,    0x73,   0x3,    0x73,   0x5,   0x73,  0x543,
        0xa,   0x73,  0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x5,   0x73,  0x556,  0xa,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x5,   0x73,  0x566,
        0xa,   0x73,  0x3,    0x73,   0x5,    0x73,   0x569,  0xa,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x5,   0x73,   0x56d,  0xa,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,  0x5,   0x73,
        0x583, 0xa,   0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x5,   0x73,   0x58a,  0xa,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x5,    0x73,   0x591,  0xa,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x3,   0x73,   0x3,    0x73,   0x3,    0x73,   0x5,    0x73,   0x5a4, 0xa,   0x73,
        0x3,   0x73,  0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x5,    0x73,  0x5aa, 0xa,
        0x73,  0x3,   0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x5,   0x73,  0x5b0,
        0xa,   0x73,  0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,  0x5,   0x73,
        0x5b6, 0xa,   0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,   0x73,  0x5,
        0x73,  0x5bc, 0xa,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,    0x73,  0x3,   0x73,
        0x5,   0x73,  0x5c2,  0xa,    0x73,   0x3,    0x73,   0x3,    0x73,   0x3,   0x73,  0x3,
        0x73,  0x5,   0x73,   0x5c8,  0xa,    0x73,   0x3,    0x74,   0x3,    0x74,  0x3,   0x74,
        0x7,   0x74,  0x5cd,  0xa,    0x74,   0xc,    0x74,   0xe,    0x74,   0x5d0, 0xb,   0x74,
        0x3,   0x75,  0x3,    0x75,   0x3,    0x75,   0x7,    0x75,   0x5d5,  0xa,   0x75,  0xc,
        0x75,  0xe,   0x75,   0x5d8,  0xb,    0x75,   0x3,    0x76,   0x3,    0x76,  0x3,   0x76,
        0x7,   0x76,  0x5dd,  0xa,    0x76,   0xc,    0x76,   0xe,    0x76,   0x5e0, 0xb,   0x76,
        0x3,   0x77,  0x3,    0x77,   0x3,    0x77,   0x3,    0x77,   0x3,    0x77,  0x3,   0x77,
        0x3,   0x77,  0x7,    0x77,   0x5e9,  0xa,    0x77,   0xc,    0x77,   0xe,   0x77,  0x5ec,
        0xb,   0x77,  0x3,    0x77,   0x3,    0x77,   0x3,    0x78,   0x3,    0x78,  0x3,   0x79,
        0x3,   0x79,  0x3,    0x7a,   0x3,    0x7a,   0x3,    0x7a,   0x5,    0x7a,  0x5f7, 0xa,
        0x7a,  0x3,   0x7b,   0x3,    0x7b,   0x3,    0x7c,   0x3,    0x7c,   0x3,   0x7d,  0x3,
        0x7d,  0x3,   0x7e,   0x3,    0x7e,   0x3,    0x7f,   0x3,    0x7f,   0x3,   0x80,  0x3,
        0x80,  0x3,   0x81,   0x3,    0x81,   0x3,    0x81,   0x2,    0x2,    0x82,  0x2,   0x4,
        0x6,   0x8,   0xa,    0xc,    0xe,    0x10,   0x12,   0x14,   0x16,   0x18,  0x1a,  0x1c,
        0x1e,  0x20,  0x22,   0x24,   0x26,   0x28,   0x2a,   0x2c,   0x2e,   0x30,  0x32,  0x34,
        0x36,  0x38,  0x3a,   0x3c,   0x3e,   0x40,   0x42,   0x44,   0x46,   0x48,  0x4a,  0x4c,
        0x4e,  0x50,  0x52,   0x54,   0x56,   0x58,   0x5a,   0x5c,   0x5e,   0x60,  0x62,  0x64,
        0x66,  0x68,  0x6a,   0x6c,   0x6e,   0x70,   0x72,   0x74,   0x76,   0x78,  0x7a,  0x7c,
        0x7e,  0x80,  0x82,   0x84,   0x86,   0x88,   0x8a,   0x8c,   0x8e,   0x90,  0x92,  0x94,
        0x96,  0x98,  0x9a,   0x9c,   0x9e,   0xa0,   0xa2,   0xa4,   0xa6,   0xa8,  0xaa,  0xac,
        0xae,  0xb0,  0xb2,   0xb4,   0xb6,   0xb8,   0xba,   0xbc,   0xbe,   0xc0,  0xc2,  0xc4,
        0xc6,  0xc8,  0xca,   0xcc,   0xce,   0xd0,   0xd2,   0xd4,   0xd6,   0xd8,  0xda,  0xdc,
        0xde,  0xe0,  0xe2,   0xe4,   0xe6,   0xe8,   0xea,   0xec,   0xee,   0xf0,  0xf2,  0xf4,
        0xf6,  0xf8,  0xfa,   0xfc,   0xfe,   0x100,  0x2,    0x1e,   0x4,    0x2,   0x2d,  0x2d,
        0x1c4, 0x1c4, 0x4,    0x2,    0xda,   0xda,   0x1b7,  0x1b7,  0x4,    0x2,   0xde,  0xde,
        0xff,  0xff,  0x4,    0x2,    0xc0,   0xc0,   0x1f6,  0x1f6,  0x4,    0x2,   0x219, 0x219,
        0x260, 0x260, 0x4,    0x2,    0x28,   0x28,   0xce,   0xce,   0x4,    0x2,   0x13,  0x13,
        0x7a,  0x7a,  0x5,    0x2,    0xb2,   0xb2,   0x104,  0x104,  0x161,  0x161, 0x8,   0x2,
        0x49,  0x49,  0x4b,   0x4b,   0x74,   0x74,   0x8c,   0x8c,   0xb3,   0xb3,  0x1a7, 0x1a7,
        0x5,   0x2,   0xbf,   0xbf,   0x181,  0x181,  0x1ec,  0x1ec,  0x5,    0x2,   0x74,  0x74,
        0x8c,  0x8c,  0xb3,   0xb3,   0x5,    0x2,    0x74,   0x74,   0x82,   0x82,  0x143, 0x143,
        0x8,   0x2,   0x1f,   0x1f,   0xea,   0xea,   0xf0,   0xf0,   0x141,  0x141, 0x1ef, 0x1ef,
        0x234, 0x234, 0x6,    0x2,    0x11b,  0x11b,  0x142,  0x142,  0x22c,  0x22c, 0x235, 0x235,
        0x6,   0x2,   0x23,   0x23,   0x11a,  0x11a,  0x140,  0x140,  0x233,  0x233, 0x6,   0x2,
        0xc4,  0xc5,  0x10f,  0x10f,  0x152,  0x154,  0x18a,  0x18b,  0x4,    0x2,   0x97,  0x97,
        0x1e5, 0x1e5, 0x5,    0x2,    0x20,   0x20,   0x22,   0x22,   0x25a,  0x25a, 0x4,   0x2,
        0x35,  0x35,  0x25b,  0x25b,  0x5,    0x2,    0x69,   0x6a,   0x22f,  0x230, 0x272, 0x272,
        0x4,   0x2,   0x275,  0x275,  0x27a,  0x27a,  0x4,    0x2,    0xaa,   0xaa,  0x23b, 0x23b,
        0x3,   0x2,   0x278,  0x279,  0x3,    0x2,    0x5f,   0x61,   0x4,    0x2,   0x12,  0x12,
        0x236, 0x236, 0x3,    0x2,    0x268,  0x269,  0x5,    0x2,    0x59,   0x59,  0x74,  0x74,
        0xe4,  0xe4,  0x6,    0x2,    0x74,   0x74,   0xa0,   0xa0,   0x164,  0x164, 0x1e7, 0x1e7,
        0x6b1, 0x2,   0x107,  0x3,    0x2,    0x2,    0x2,    0x4,    0x110,  0x3,   0x2,   0x2,
        0x2,   0x6,   0x112,  0x3,    0x2,    0x2,    0x2,    0x8,    0x117,  0x3,   0x2,   0x2,
        0x2,   0xa,   0x124,  0x3,    0x2,    0x2,    0x2,    0xc,    0x16e,  0x3,   0x2,   0x2,
        0x2,   0xe,   0x176,  0x3,    0x2,    0x2,    0x2,    0x10,   0x1b2,  0x3,   0x2,   0x2,
        0x2,   0x12,  0x1bc,  0x3,    0x2,    0x2,    0x2,    0x14,   0x1c1,  0x3,   0x2,   0x2,
        0x2,   0x16,  0x1e7,  0x3,    0x2,    0x2,    0x2,    0x18,   0x25a,  0x3,   0x2,   0x2,
        0x2,   0x1a,  0x2d6,  0x3,    0x2,    0x2,    0x2,    0x1c,   0x2d8,  0x3,   0x2,   0x2,
        0x2,   0x1e,  0x2eb,  0x3,    0x2,    0x2,    0x2,    0x20,   0x311,  0x3,   0x2,   0x2,
        0x2,   0x22,  0x322,  0x3,    0x2,    0x2,    0x2,    0x24,   0x324,  0x3,   0x2,   0x2,
        0x2,   0x26,  0x32d,  0x3,    0x2,    0x2,    0x2,    0x28,   0x338,  0x3,   0x2,   0x2,
        0x2,   0x2a,  0x344,  0x3,    0x2,    0x2,    0x2,    0x2c,   0x350,  0x3,   0x2,   0x2,
        0x2,   0x2e,  0x38a,  0x3,    0x2,    0x2,    0x2,    0x30,   0x38c,  0x3,   0x2,   0x2,
        0x2,   0x32,  0x39f,  0x3,    0x2,    0x2,    0x2,    0x34,   0x3aa,  0x3,   0x2,   0x2,
        0x2,   0x36,  0x3b7,  0x3,    0x2,    0x2,    0x2,    0x38,   0x3ba,  0x3,   0x2,   0x2,
        0x2,   0x3a,  0x3c5,  0x3,    0x2,    0x2,    0x2,    0x3c,   0x3d0,  0x3,   0x2,   0x2,
        0x2,   0x3e,  0x3db,  0x3,    0x2,    0x2,    0x2,    0x40,   0x3e6,  0x3,   0x2,   0x2,
        0x2,   0x42,  0x3f1,  0x3,    0x2,    0x2,    0x2,    0x44,   0x3fc,  0x3,   0x2,   0x2,
        0x2,   0x46,  0x407,  0x3,    0x2,    0x2,    0x2,    0x48,   0x412,  0x3,   0x2,   0x2,
        0x2,   0x4a,  0x41d,  0x3,    0x2,    0x2,    0x2,    0x4c,   0x424,  0x3,   0x2,   0x2,
        0x2,   0x4e,  0x42b,  0x3,    0x2,    0x2,    0x2,    0x50,   0x431,  0x3,   0x2,   0x2,
        0x2,   0x52,  0x433,  0x3,    0x2,    0x2,    0x2,    0x54,   0x43d,  0x3,   0x2,   0x2,
        0x2,   0x56,  0x447,  0x3,    0x2,    0x2,    0x2,    0x58,   0x449,  0x3,   0x2,   0x2,
        0x2,   0x5a,  0x44b,  0x3,    0x2,    0x2,    0x2,    0x5c,   0x44d,  0x3,   0x2,   0x2,
        0x2,   0x5e,  0x44f,  0x3,    0x2,    0x2,    0x2,    0x60,   0x451,  0x3,   0x2,   0x2,
        0x2,   0x62,  0x453,  0x3,    0x2,    0x2,    0x2,    0x64,   0x455,  0x3,   0x2,   0x2,
        0x2,   0x66,  0x457,  0x3,    0x2,    0x2,    0x2,    0x68,   0x459,  0x3,   0x2,   0x2,
        0x2,   0x6a,  0x45b,  0x3,    0x2,    0x2,    0x2,    0x6c,   0x45d,  0x3,   0x2,   0x2,
        0x2,   0x6e,  0x45f,  0x3,    0x2,    0x2,    0x2,    0x70,   0x461,  0x3,   0x2,   0x2,
        0x2,   0x72,  0x463,  0x3,    0x2,    0x2,    0x2,    0x74,   0x465,  0x3,   0x2,   0x2,
        0x2,   0x76,  0x469,  0x3,    0x2,    0x2,    0x2,    0x78,   0x46b,  0x3,   0x2,   0x2,
        0x2,   0x7a,  0x46f,  0x3,    0x2,    0x2,    0x2,    0x7c,   0x473,  0x3,   0x2,   0x2,
        0x2,   0x7e,  0x475,  0x3,    0x2,    0x2,    0x2,    0x80,   0x477,  0x3,   0x2,   0x2,
        0x2,   0x82,  0x47f,  0x3,    0x2,    0x2,    0x2,    0x84,   0x487,  0x3,   0x2,   0x2,
        0x2,   0x86,  0x489,  0x3,    0x2,    0x2,    0x2,    0x88,   0x48b,  0x3,   0x2,   0x2,
        0x2,   0x8a,  0x48d,  0x3,    0x2,    0x2,    0x2,    0x8c,   0x497,  0x3,   0x2,   0x2,
        0x2,   0x8e,  0x499,  0x3,    0x2,    0x2,    0x2,    0x90,   0x49b,  0x3,   0x2,   0x2,
        0x2,   0x92,  0x49d,  0x3,    0x2,    0x2,    0x2,    0x94,   0x49f,  0x3,   0x2,   0x2,
        0x2,   0x96,  0x4a1,  0x3,    0x2,    0x2,    0x2,    0x98,   0x4a3,  0x3,   0x2,   0x2,
        0x2,   0x9a,  0x4a5,  0x3,    0x2,    0x2,    0x2,    0x9c,   0x4a7,  0x3,   0x2,   0x2,
        0x2,   0x9e,  0x4a9,  0x3,    0x2,    0x2,    0x2,    0xa0,   0x4ab,  0x3,   0x2,   0x2,
        0x2,   0xa2,  0x4ad,  0x3,    0x2,    0x2,    0x2,    0xa4,   0x4af,  0x3,   0x2,   0x2,
        0x2,   0xa6,  0x4b1,  0x3,    0x2,    0x2,    0x2,    0xa8,   0x4b3,  0x3,   0x2,   0x2,
        0x2,   0xaa,  0x4b5,  0x3,    0x2,    0x2,    0x2,    0xac,   0x4b7,  0x3,   0x2,   0x2,
        0x2,   0xae,  0x4b9,  0x3,    0x2,    0x2,    0x2,    0xb0,   0x4bb,  0x3,   0x2,   0x2,
        0x2,   0xb2,  0x4bd,  0x3,    0x2,    0x2,    0x2,    0xb4,   0x4bf,  0x3,   0x2,   0x2,
        0x2,   0xb6,  0x4c1,  0x3,    0x2,    0x2,    0x2,    0xb8,   0x4c3,  0x3,   0x2,   0x2,
        0x2,   0xba,  0x4c7,  0x3,    0x2,    0x2,    0x2,    0xbc,   0x4c9,  0x3,   0x2,   0x2,
        0x2,   0xbe,  0x4cb,  0x3,    0x2,    0x2,    0x2,    0xc0,   0x4cd,  0x3,   0x2,   0x2,
        0x2,   0xc2,  0x4cf,  0x3,    0x2,    0x2,    0x2,    0xc4,   0x4d1,  0x3,   0x2,   0x2,
        0x2,   0xc6,  0x4d6,  0x3,    0x2,    0x2,    0x2,    0xc8,   0x4da,  0x3,   0x2,   0x2,
        0x2,   0xca,  0x4dc,  0x3,    0x2,    0x2,    0x2,    0xcc,   0x4de,  0x3,   0x2,   0x2,
        0x2,   0xce,  0x4e0,  0x3,    0x2,    0x2,    0x2,    0xd0,   0x4e2,  0x3,   0x2,   0x2,
        0x2,   0xd2,  0x4e4,  0x3,    0x2,    0x2,    0x2,    0xd4,   0x4ec,  0x3,   0x2,   0x2,
        0x2,   0xd6,  0x4ee,  0x3,    0x2,    0x2,    0x2,    0xd8,   0x4f0,  0x3,   0x2,   0x2,
        0x2,   0xda,  0x4f2,  0x3,    0x2,    0x2,    0x2,    0xdc,   0x4f4,  0x3,   0x2,   0x2,
        0x2,   0xde,  0x4f6,  0x3,    0x2,    0x2,    0x2,    0xe0,   0x4f8,  0x3,   0x2,   0x2,
        0x2,   0xe2,  0x4fa,  0x3,    0x2,    0x2,    0x2,    0xe4,   0x5c7,  0x3,   0x2,   0x2,
        0x2,   0xe6,  0x5c9,  0x3,    0x2,    0x2,    0x2,    0xe8,   0x5d1,  0x3,   0x2,   0x2,
        0x2,   0xea,  0x5d9,  0x3,    0x2,    0x2,    0x2,    0xec,   0x5e1,  0x3,   0x2,   0x2,
        0x2,   0xee,  0x5ef,  0x3,    0x2,    0x2,    0x2,    0xf0,   0x5f1,  0x3,   0x2,   0x2,
        0x2,   0xf2,  0x5f6,  0x3,    0x2,    0x2,    0x2,    0xf4,   0x5f8,  0x3,   0x2,   0x2,
        0x2,   0xf6,  0x5fa,  0x3,    0x2,    0x2,    0x2,    0xf8,   0x5fc,  0x3,   0x2,   0x2,
        0x2,   0xfa,  0x5fe,  0x3,    0x2,    0x2,    0x2,    0xfc,   0x600,  0x3,   0x2,   0x2,
        0x2,   0xfe,  0x602,  0x3,    0x2,    0x2,    0x2,    0x100,  0x604,  0x3,   0x2,   0x2,
        0x2,   0x102, 0x103,  0x5,    0x4,    0x3,    0x2,    0x103,  0x104,  0x7,   0x284, 0x2,
        0x2,   0x104, 0x106,  0x3,    0x2,    0x2,    0x2,    0x105,  0x102,  0x3,   0x2,   0x2,
        0x2,   0x106, 0x109,  0x3,    0x2,    0x2,    0x2,    0x107,  0x105,  0x3,   0x2,   0x2,
        0x2,   0x107, 0x108,  0x3,    0x2,    0x2,    0x2,    0x108,  0x10a,  0x3,   0x2,   0x2,
        0x2,   0x109, 0x107,  0x3,    0x2,    0x2,    0x2,    0x10a,  0x10b,  0x7,   0x2,   0x2,
        0x3,   0x10b, 0x3,    0x3,    0x2,    0x2,    0x2,    0x10c,  0x111,  0x5,   0x6,   0x4,
        0x2,   0x10d, 0x111,  0x5,    0x8,    0x5,    0x2,    0x10e,  0x111,  0x5,   0xe2,  0x72,
        0x2,   0x10f, 0x111,  0x5,    0xc,    0x7,    0x2,    0x110,  0x10c,  0x3,   0x2,   0x2,
        0x2,   0x110, 0x10d,  0x3,    0x2,    0x2,    0x2,    0x110,  0x10e,  0x3,   0x2,   0x2,
        0x2,   0x110, 0x10f,  0x3,    0x2,    0x2,    0x2,    0x111,  0x5,    0x3,   0x2,   0x2,
        0x2,   0x112, 0x113,  0x7,    0x1e5,  0x2,    0x2,    0x113,  0x114,  0x5,   0xd6,  0x6c,
        0x2,   0x114, 0x115,  0x7,    0x285,  0x2,    0x2,    0x115,  0x116,  0x5,   0xd4,  0x6b,
        0x2,   0x116, 0x7,    0x3,    0x2,    0x2,    0x2,    0x117,  0x119,  0x7,   0x88,  0x2,
        0x2,   0x118, 0x11a,  0x7,    0x229,  0x2,    0x2,    0x119,  0x118,  0x3,   0x2,   0x2,
        0x2,   0x119, 0x11a,  0x3,    0x2,    0x2,    0x2,    0x11a,  0x11b,  0x3,   0x2,   0x2,
        0x2,   0x11b, 0x11e,  0x7,    0x224,  0x2,    0x2,    0x11c,  0x11d,  0x7,   0xd9,  0x2,
        0x2,   0x11d, 0x11f,  0x7,    0xa2,   0x2,    0x2,    0x11e,  0x11c,  0x3,   0x2,   0x2,
        0x2,   0x11e, 0x11f,  0x3,    0x2,    0x2,    0x2,    0x11f,  0x120,  0x3,   0x2,   0x2,
        0x2,   0x120, 0x122,  0x5,    0xa,    0x6,    0x2,    0x121,  0x123,  0x9,   0x2,   0x2,
        0x2,   0x122, 0x121,  0x3,    0x2,    0x2,    0x2,    0x122,  0x123,  0x3,   0x2,   0x2,
        0x2,   0x123, 0x9,    0x3,    0x2,    0x2,    0x2,    0x124,  0x129,  0x5,   0xc6,  0x64,
        0x2,   0x125, 0x126,  0x7,    0x282,  0x2,    0x2,    0x126,  0x128,  0x5,   0xc6,  0x64,
        0x2,   0x127, 0x125,  0x3,    0x2,    0x2,    0x2,    0x128,  0x12b,  0x3,   0x2,   0x2,
        0x2,   0x129, 0x127,  0x3,    0x2,    0x2,    0x2,    0x129,  0x12a,  0x3,   0x2,   0x2,
        0x2,   0x12a, 0xb,    0x3,    0x2,    0x2,    0x2,    0x12b,  0x129,  0x3,   0x2,   0x2,
        0x2,   0x12c, 0x12e,  0x7,    0x5b,   0x2,    0x2,    0x12d,  0x12f,  0x7,   0x229, 0x2,
        0x2,   0x12e, 0x12d,  0x3,    0x2,    0x2,    0x2,    0x12e,  0x12f,  0x3,   0x2,   0x2,
        0x2,   0x12f, 0x130,  0x3,    0x2,    0x2,    0x2,    0x130,  0x134,  0x7,   0x224, 0x2,
        0x2,   0x131, 0x132,  0x7,    0xd9,   0x2,    0x2,    0x132,  0x133,  0x7,   0x165, 0x2,
        0x2,   0x133, 0x135,  0x7,    0xa2,   0x2,    0x2,    0x134,  0x131,  0x3,   0x2,   0x2,
        0x2,   0x134, 0x135,  0x3,    0x2,    0x2,    0x2,    0x135,  0x136,  0x3,   0x2,   0x2,
        0x2,   0x136, 0x137,  0x5,    0xc6,   0x64,   0x2,    0x137,  0x139,  0x5,   0x32,  0x1a,
        0x2,   0x138, 0x13a,  0x5,    0x34,   0x1b,   0x2,    0x139,  0x138,  0x3,   0x2,   0x2,
        0x2,   0x139, 0x13a,  0x3,    0x2,    0x2,    0x2,    0x13a,  0x13c,  0x3,   0x2,   0x2,
        0x2,   0x13b, 0x13d,  0x5,    0x1c,   0xf,    0x2,    0x13c,  0x13b,  0x3,   0x2,   0x2,
        0x2,   0x13c, 0x13d,  0x3,    0x2,    0x2,    0x2,    0x13d,  0x16f,  0x3,   0x2,   0x2,
        0x2,   0x13e, 0x140,  0x7,    0x5b,   0x2,    0x2,    0x13f,  0x141,  0x7,   0x229, 0x2,
        0x2,   0x140, 0x13f,  0x3,    0x2,    0x2,    0x2,    0x140,  0x141,  0x3,   0x2,   0x2,
        0x2,   0x141, 0x142,  0x3,    0x2,    0x2,    0x2,    0x142,  0x146,  0x7,   0x224, 0x2,
        0x2,   0x143, 0x144,  0x7,    0xd9,   0x2,    0x2,    0x144,  0x145,  0x7,   0x165, 0x2,
        0x2,   0x145, 0x147,  0x7,    0xa2,   0x2,    0x2,    0x146,  0x143,  0x3,   0x2,   0x2,
        0x2,   0x146, 0x147,  0x3,    0x2,    0x2,    0x2,    0x147,  0x148,  0x3,   0x2,   0x2,
        0x2,   0x148, 0x150,  0x5,    0xc6,   0x64,   0x2,    0x149,  0x14a,  0x7,   0x10b, 0x2,
        0x2,   0x14a, 0x151,  0x5,    0xbe,   0x60,   0x2,    0x14b,  0x14c,  0x7,   0x27f, 0x2,
        0x2,   0x14c, 0x14d,  0x7,    0x10b,  0x2,    0x2,    0x14d,  0x14e,  0x5,   0xbe,  0x60,
        0x2,   0x14e, 0x14f,  0x7,    0x280,  0x2,    0x2,    0x14f,  0x151,  0x3,   0x2,   0x2,
        0x2,   0x150, 0x149,  0x3,    0x2,    0x2,    0x2,    0x150,  0x14b,  0x3,   0x2,   0x2,
        0x2,   0x151, 0x16f,  0x3,    0x2,    0x2,    0x2,    0x152,  0x154,  0x7,   0x5b,  0x2,
        0x2,   0x153, 0x155,  0x7,    0x229,  0x2,    0x2,    0x154,  0x153,  0x3,   0x2,   0x2,
        0x2,   0x154, 0x155,  0x3,    0x2,    0x2,    0x2,    0x155,  0x156,  0x3,   0x2,   0x2,
        0x2,   0x156, 0x15a,  0x7,    0x224,  0x2,    0x2,    0x157,  0x158,  0x7,   0xd9,  0x2,
        0x2,   0x158, 0x159,  0x7,    0x165,  0x2,    0x2,    0x159,  0x15b,  0x7,   0xa2,  0x2,
        0x2,   0x15a, 0x157,  0x3,    0x2,    0x2,    0x2,    0x15a,  0x15b,  0x3,   0x2,   0x2,
        0x2,   0x15b, 0x15c,  0x3,    0x2,    0x2,    0x2,    0x15c,  0x15e,  0x5,   0xc6,  0x64,
        0x2,   0x15d, 0x15f,  0x5,    0x32,   0x1a,   0x2,    0x15e,  0x15d,  0x3,   0x2,   0x2,
        0x2,   0x15e, 0x15f,  0x3,    0x2,    0x2,    0x2,    0x15f,  0x161,  0x3,   0x2,   0x2,
        0x2,   0x160, 0x162,  0x5,    0x34,   0x1b,   0x2,    0x161,  0x160,  0x3,   0x2,   0x2,
        0x2,   0x161, 0x162,  0x3,    0x2,    0x2,    0x2,    0x162,  0x164,  0x3,   0x2,   0x2,
        0x2,   0x163, 0x165,  0x5,    0x1c,   0xf,    0x2,    0x164,  0x163,  0x3,   0x2,   0x2,
        0x2,   0x164, 0x165,  0x3,    0x2,    0x2,    0x2,    0x165,  0x167,  0x3,   0x2,   0x2,
        0x2,   0x166, 0x168,  0x9,    0x3,    0x2,    0x2,    0x167,  0x166,  0x3,   0x2,   0x2,
        0x2,   0x167, 0x168,  0x3,    0x2,    0x2,    0x2,    0x168,  0x16a,  0x3,   0x2,   0x2,
        0x2,   0x169, 0x16b,  0x7,    0x12,   0x2,    0x2,    0x16a,  0x169,  0x3,   0x2,   0x2,
        0x2,   0x16a, 0x16b,  0x3,    0x2,    0x2,    0x2,    0x16b,  0x16c,  0x3,   0x2,   0x2,
        0x2,   0x16c, 0x16d,  0x5,    0xac,   0x57,   0x2,    0x16d,  0x16f,  0x3,   0x2,   0x2,
        0x2,   0x16e, 0x12c,  0x3,    0x2,    0x2,    0x2,    0x16e,  0x13e,  0x3,   0x2,   0x2,
        0x2,   0x16e, 0x152,  0x3,    0x2,    0x2,    0x2,    0x16f,  0xd,    0x3,   0x2,   0x2,
        0x2,   0x170, 0x171,  0x5,    0xc0,   0x61,   0x2,    0x171,  0x172,  0x5,   0x12,  0xa,
        0x2,   0x172, 0x177,  0x3,    0x2,    0x2,    0x2,    0x173,  0x177,  0x5,   0x10,  0x9,
        0x2,   0x174, 0x175,  0x7,    0x38,   0x2,    0x2,    0x175,  0x177,  0x5,   0xae,  0x58,
        0x2,   0x176, 0x170,  0x3,    0x2,    0x2,    0x2,    0x176,  0x173,  0x3,   0x2,   0x2,
        0x2,   0x176, 0x174,  0x3,    0x2,    0x2,    0x2,    0x177,  0xf,    0x3,   0x2,   0x2,
        0x2,   0x178, 0x17a,  0x5,    0x4a,   0x26,   0x2,    0x179,  0x178,  0x3,   0x2,   0x2,
        0x2,   0x179, 0x17a,  0x3,    0x2,    0x2,    0x2,    0x17a,  0x17b,  0x3,   0x2,   0x2,
        0x2,   0x17b, 0x17c,  0x7,    0x192,  0x2,    0x2,    0x17c,  0x17e,  0x7,   0xff,  0x2,
        0x2,   0x17d, 0x17f,  0x5,    0x50,   0x29,   0x2,    0x17e,  0x17d,  0x3,   0x2,   0x2,
        0x2,   0x17e, 0x17f,  0x3,    0x2,    0x2,    0x2,    0x17f,  0x180,  0x3,   0x2,   0x2,
        0x2,   0x180, 0x181,  0x5,    0x38,   0x1d,   0x2,    0x181,  0x182,  0x5,   0x36,  0x1c,
        0x2,   0x182, 0x1b3,  0x3,    0x2,    0x2,    0x2,    0x183,  0x185,  0x9,   0x4,   0x2,
        0x2,   0x184, 0x186,  0x5,    0xc2,   0x62,   0x2,    0x185,  0x184,  0x3,   0x2,   0x2,
        0x2,   0x185, 0x186,  0x3,    0x2,    0x2,    0x2,    0x186,  0x188,  0x3,   0x2,   0x2,
        0x2,   0x187, 0x189,  0x5,    0x50,   0x29,   0x2,    0x188,  0x187,  0x3,   0x2,   0x2,
        0x2,   0x188, 0x189,  0x3,    0x2,    0x2,    0x2,    0x189,  0x18a,  0x3,   0x2,   0x2,
        0x2,   0x18a, 0x18b,  0x5,    0x38,   0x1d,   0x2,    0x18b,  0x18c,  0x5,   0x36,  0x1c,
        0x2,   0x18c, 0x1b3,  0x3,    0x2,    0x2,    0x2,    0x18d,  0x18f,  0x5,   0x4a,  0x26,
        0x2,   0x18e, 0x18d,  0x3,    0x2,    0x2,    0x2,    0x18e,  0x18f,  0x3,   0x2,   0x2,
        0x2,   0x18f, 0x190,  0x3,    0x2,    0x2,    0x2,    0x190,  0x192,  0x7,   0x247, 0x2,
        0x2,   0x191, 0x193,  0x9,    0x4,    0x2,    0x2,    0x192,  0x191,  0x3,   0x2,   0x2,
        0x2,   0x192, 0x193,  0x3,    0x2,    0x2,    0x2,    0x193,  0x195,  0x3,   0x2,   0x2,
        0x2,   0x194, 0x196,  0x5,    0xc2,   0x62,   0x2,    0x195,  0x194,  0x3,   0x2,   0x2,
        0x2,   0x195, 0x196,  0x3,    0x2,    0x2,    0x2,    0x196,  0x198,  0x3,   0x2,   0x2,
        0x2,   0x197, 0x199,  0x5,    0x50,   0x29,   0x2,    0x198,  0x197,  0x3,   0x2,   0x2,
        0x2,   0x198, 0x199,  0x3,    0x2,    0x2,    0x2,    0x199,  0x19a,  0x3,   0x2,   0x2,
        0x2,   0x19a, 0x19b,  0x5,    0x38,   0x1d,   0x2,    0x19b,  0x19c,  0x5,   0x36,  0x1c,
        0x2,   0x19c, 0x1b3,  0x3,    0x2,    0x2,    0x2,    0x19d,  0x19f,  0x9,   0x5,   0x2,
        0x2,   0x19e, 0x1a0,  0x9,    0x4,    0x2,    0x2,    0x19f,  0x19e,  0x3,   0x2,   0x2,
        0x2,   0x19f, 0x1a0,  0x3,    0x2,    0x2,    0x2,    0x1a0,  0x1a2,  0x3,   0x2,   0x2,
        0x2,   0x1a1, 0x1a3,  0x5,    0xc2,   0x62,   0x2,    0x1a2,  0x1a1,  0x3,   0x2,   0x2,
        0x2,   0x1a2, 0x1a3,  0x3,    0x2,    0x2,    0x2,    0x1a3,  0x1a4,  0x3,   0x2,   0x2,
        0x2,   0x1a4, 0x1a5,  0x5,    0x38,   0x1d,   0x2,    0x1a5,  0x1a6,  0x5,   0x36,  0x1c,
        0x2,   0x1a6, 0x1b3,  0x3,    0x2,    0x2,    0x2,    0x1a7,  0x1a9,  0x5,   0x4a,  0x26,
        0x2,   0x1a8, 0x1a7,  0x3,    0x2,    0x2,    0x2,    0x1a8,  0x1a9,  0x3,   0x2,   0x2,
        0x2,   0x1a9, 0x1aa,  0x3,    0x2,    0x2,    0x2,    0x1aa,  0x1ab,  0x7,   0xbb,  0x2,
        0x2,   0x1ab, 0x1ad,  0x7,    0xff,   0x2,    0x2,    0x1ac,  0x1ae,  0x5,   0xc2,  0x62,
        0x2,   0x1ad, 0x1ac,  0x3,    0x2,    0x2,    0x2,    0x1ad,  0x1ae,  0x3,   0x2,   0x2,
        0x2,   0x1ae, 0x1af,  0x3,    0x2,    0x2,    0x2,    0x1af,  0x1b0,  0x5,   0x38,  0x1d,
        0x2,   0x1b0, 0x1b1,  0x5,    0x30,   0x19,   0x2,    0x1b1,  0x1b3,  0x3,   0x2,   0x2,
        0x2,   0x1b2, 0x179,  0x3,    0x2,    0x2,    0x2,    0x1b2,  0x183,  0x3,   0x2,   0x2,
        0x2,   0x1b2, 0x18e,  0x3,    0x2,    0x2,    0x2,    0x1b2,  0x19d,  0x3,   0x2,   0x2,
        0x2,   0x1b2, 0x1a8,  0x3,    0x2,    0x2,    0x2,    0x1b3,  0x11,   0x3,   0x2,   0x2,
        0x2,   0x1b4, 0x1b5,  0x5,    0x18,   0xd,    0x2,    0x1b5,  0x1b7,  0x5,   0x14,  0xb,
        0x2,   0x1b6, 0x1b8,  0x5,    0x30,   0x19,   0x2,    0x1b7,  0x1b6,  0x3,   0x2,   0x2,
        0x2,   0x1b7, 0x1b8,  0x3,    0x2,    0x2,    0x2,    0x1b8,  0x1bd,  0x3,   0x2,   0x2,
        0x2,   0x1b9, 0x1ba,  0x5,    0x18,   0xd,    0x2,    0x1ba,  0x1bb,  0x5,   0x16,  0xc,
        0x2,   0x1bb, 0x1bd,  0x3,    0x2,    0x2,    0x2,    0x1bc,  0x1b4,  0x3,   0x2,   0x2,
        0x2,   0x1bc, 0x1b9,  0x3,    0x2,    0x2,    0x2,    0x1bd,  0x13,   0x3,   0x2,   0x2,
        0x2,   0x1be, 0x1bf,  0x7,    0x165,  0x2,    0x2,    0x1bf,  0x1c2,  0x7,   0x168, 0x2,
        0x2,   0x1c0, 0x1c2,  0x7,    0x168,  0x2,    0x2,    0x1c1,  0x1be,  0x3,   0x2,   0x2,
        0x2,   0x1c1, 0x1c0,  0x3,    0x2,    0x2,    0x2,    0x1c1,  0x1c2,  0x3,   0x2,   0x2,
        0x2,   0x1c2, 0x1c5,  0x3,    0x2,    0x2,    0x2,    0x1c3,  0x1c4,  0x7,   0x74,  0x2,
        0x2,   0x1c4, 0x1c6,  0x5,    0x9e,   0x50,   0x2,    0x1c5,  0x1c3,  0x3,   0x2,   0x2,
        0x2,   0x1c5, 0x1c6,  0x3,    0x2,    0x2,    0x2,    0x1c6,  0x1c8,  0x3,   0x2,   0x2,
        0x2,   0x1c7, 0x1c9,  0x7,    0x18,   0x2,    0x2,    0x1c8,  0x1c7,  0x3,   0x2,   0x2,
        0x2,   0x1c8, 0x1c9,  0x3,    0x2,    0x2,    0x2,    0x1c9,  0x1d2,  0x3,   0x2,   0x2,
        0x2,   0x1ca, 0x1cc,  0x7,    0x247,  0x2,    0x2,    0x1cb,  0x1cd,  0x7,   0xff,  0x2,
        0x2,   0x1cc, 0x1cb,  0x3,    0x2,    0x2,    0x2,    0x1cc,  0x1cd,  0x3,   0x2,   0x2,
        0x2,   0x1cd, 0x1d3,  0x3,    0x2,    0x2,    0x2,    0x1ce,  0x1d0,  0x7,   0x192, 0x2,
        0x2,   0x1cf, 0x1ce,  0x3,    0x2,    0x2,    0x2,    0x1cf,  0x1d0,  0x3,   0x2,   0x2,
        0x2,   0x1d0, 0x1d1,  0x3,    0x2,    0x2,    0x2,    0x1d1,  0x1d3,  0x7,   0xff,  0x2,
        0x2,   0x1d2, 0x1ca,  0x3,    0x2,    0x2,    0x2,    0x1d2,  0x1cf,  0x3,   0x2,   0x2,
        0x2,   0x1d2, 0x1d3,  0x3,    0x2,    0x2,    0x2,    0x1d3,  0x1d6,  0x3,   0x2,   0x2,
        0x2,   0x1d4, 0x1d5,  0x7,    0x46,   0x2,    0x2,    0x1d5,  0x1d7,  0x5,   0xa0,  0x51,
        0x2,   0x1d6, 0x1d4,  0x3,    0x2,    0x2,    0x2,    0x1d6,  0x1d7,  0x3,   0x2,   0x2,
        0x2,   0x1d7, 0x1da,  0x3,    0x2,    0x2,    0x2,    0x1d8,  0x1d9,  0x7,   0x44,  0x2,
        0x2,   0x1d9, 0x1db,  0x5,    0x86,   0x44,   0x2,    0x1da,  0x1d8,  0x3,   0x2,   0x2,
        0x2,   0x1da, 0x1db,  0x3,    0x2,    0x2,    0x2,    0x1db,  0x1de,  0x3,   0x2,   0x2,
        0x2,   0x1dc, 0x1dd,  0x7,    0x218,  0x2,    0x2,    0x1dd,  0x1df,  0x5,   0x88,  0x45,
        0x2,   0x1de, 0x1dc,  0x3,    0x2,    0x2,    0x2,    0x1de,  0x1df,  0x3,   0x2,   0x2,
        0x2,   0x1df, 0x1e3,  0x3,    0x2,    0x2,    0x2,    0x1e0,  0x1e1,  0x7,   0x16e, 0x2,
        0x2,   0x1e1, 0x1e2,  0x7,    0x24c,  0x2,    0x2,    0x1e2,  0x1e4,  0x5,   0x9c,  0x4f,
        0x2,   0x1e3, 0x1e0,  0x3,    0x2,    0x2,    0x2,    0x1e3,  0x1e4,  0x3,   0x2,   0x2,
        0x2,   0x1e4, 0x15,   0x3,    0x2,    0x2,    0x2,    0x1e5,  0x1e6,  0x7,   0xc3,  0x2,
        0x2,   0x1e6, 0x1e8,  0x7,    0xd,    0x2,    0x2,    0x1e7,  0x1e5,  0x3,   0x2,   0x2,
        0x2,   0x1e7, 0x1e8,  0x3,    0x2,    0x2,    0x2,    0x1e8,  0x1e9,  0x3,   0x2,   0x2,
        0x2,   0x1e9, 0x1ea,  0x7,    0x12,   0x2,    0x2,    0x1ea,  0x1ec,  0x5,   0xaa,  0x56,
        0x2,   0x1eb, 0x1ed,  0x9,    0x6,    0x2,    0x2,    0x1ec,  0x1eb,  0x3,   0x2,   0x2,
        0x2,   0x1ec, 0x1ed,  0x3,    0x2,    0x2,    0x2,    0x1ed,  0x1f2,  0x3,   0x2,   0x2,
        0x2,   0x1ee, 0x1f0,  0x7,    0x247,  0x2,    0x2,    0x1ef,  0x1f1,  0x7,   0xff,  0x2,
        0x2,   0x1f0, 0x1ef,  0x3,    0x2,    0x2,    0x2,    0x1f0,  0x1f1,  0x3,   0x2,   0x2,
        0x2,   0x1f1, 0x1f3,  0x3,    0x2,    0x2,    0x2,    0x1f2,  0x1ee,  0x3,   0x2,   0x2,
        0x2,   0x1f2, 0x1f3,  0x3,    0x2,    0x2,    0x2,    0x1f3,  0x1f6,  0x3,   0x2,   0x2,
        0x2,   0x1f4, 0x1f5,  0x7,    0x46,   0x2,    0x2,    0x1f5,  0x1f7,  0x5,   0xa0,  0x51,
        0x2,   0x1f6, 0x1f4,  0x3,    0x2,    0x2,    0x2,    0x1f6,  0x1f7,  0x3,   0x2,   0x2,
        0x2,   0x1f7, 0x1fb,  0x3,    0x2,    0x2,    0x2,    0x1f8,  0x1f9,  0x7,   0x165, 0x2,
        0x2,   0x1f9, 0x1fc,  0x7,    0x168,  0x2,    0x2,    0x1fa,  0x1fc,  0x7,   0x168, 0x2,
        0x2,   0x1fb, 0x1f8,  0x3,    0x2,    0x2,    0x2,    0x1fb,  0x1fa,  0x3,   0x2,   0x2,
        0x2,   0x1fb, 0x1fc,  0x3,    0x2,    0x2,    0x2,    0x1fc,  0x201,  0x3,   0x2,   0x2,
        0x2,   0x1fd, 0x1ff,  0x7,    0x192,  0x2,    0x2,    0x1fe,  0x1fd,  0x3,   0x2,   0x2,
        0x2,   0x1fe, 0x1ff,  0x3,    0x2,    0x2,    0x2,    0x1ff,  0x200,  0x3,   0x2,   0x2,
        0x2,   0x200, 0x202,  0x7,    0xff,   0x2,    0x2,    0x201,  0x1fe,  0x3,   0x2,   0x2,
        0x2,   0x201, 0x202,  0x3,    0x2,    0x2,    0x2,    0x202,  0x17,   0x3,   0x2,   0x2,
        0x2,   0x203, 0x208,  0x5,    0x8a,   0x46,   0x2,    0x204,  0x205,  0x7,   0x27f, 0x2,
        0x2,   0x205, 0x206,  0x5,    0x58,   0x2d,   0x2,    0x206,  0x207,  0x7,   0x280, 0x2,
        0x2,   0x207, 0x209,  0x3,    0x2,    0x2,    0x2,    0x208,  0x204,  0x3,   0x2,   0x2,
        0x2,   0x208, 0x209,  0x3,    0x2,    0x2,    0x2,    0x209,  0x20b,  0x3,   0x2,   0x2,
        0x2,   0x20a, 0x20c,  0x7,    0x24a,  0x2,    0x2,    0x20b,  0x20a,  0x3,   0x2,   0x2,
        0x2,   0x20b, 0x20c,  0x3,    0x2,    0x2,    0x2,    0x20c,  0x20e,  0x3,   0x2,   0x2,
        0x2,   0x20d, 0x20f,  0x7,    0x274,  0x2,    0x2,    0x20e,  0x20d,  0x3,   0x2,   0x2,
        0x2,   0x20e, 0x20f,  0x3,    0x2,    0x2,    0x2,    0x20f,  0x25b,  0x3,   0x2,   0x2,
        0x2,   0x210, 0x219,  0x5,    0x8c,   0x47,   0x2,    0x211,  0x212,  0x7,   0x27f, 0x2,
        0x2,   0x212, 0x215,  0x5,    0x58,   0x2d,   0x2,    0x213,  0x214,  0x7,   0x282, 0x2,
        0x2,   0x214, 0x216,  0x5,    0x5a,   0x2e,   0x2,    0x215,  0x213,  0x3,   0x2,   0x2,
        0x2,   0x215, 0x216,  0x3,    0x2,    0x2,    0x2,    0x216,  0x217,  0x3,   0x2,   0x2,
        0x2,   0x217, 0x218,  0x7,    0x280,  0x2,    0x2,    0x218,  0x21a,  0x3,   0x2,   0x2,
        0x2,   0x219, 0x211,  0x3,    0x2,    0x2,    0x2,    0x219,  0x21a,  0x3,   0x2,   0x2,
        0x2,   0x21a, 0x21c,  0x3,    0x2,    0x2,    0x2,    0x21b,  0x21d,  0x7,   0x24a, 0x2,
        0x2,   0x21c, 0x21b,  0x3,    0x2,    0x2,    0x2,    0x21c,  0x21d,  0x3,   0x2,   0x2,
        0x2,   0x21d, 0x21f,  0x3,    0x2,    0x2,    0x2,    0x21e,  0x220,  0x7,   0x274, 0x2,
        0x2,   0x21f, 0x21e,  0x3,    0x2,    0x2,    0x2,    0x21f,  0x220,  0x3,   0x2,   0x2,
        0x2,   0x220, 0x25b,  0x3,    0x2,    0x2,    0x2,    0x221,  0x226,  0x5,   0x9a,  0x4e,
        0x2,   0x222, 0x223,  0x7,    0x27f,  0x2,    0x2,    0x223,  0x224,  0x5,   0x56,  0x2c,
        0x2,   0x224, 0x225,  0x7,    0x280,  0x2,    0x2,    0x225,  0x227,  0x3,   0x2,   0x2,
        0x2,   0x226, 0x222,  0x3,    0x2,    0x2,    0x2,    0x226,  0x227,  0x3,   0x2,   0x2,
        0x2,   0x227, 0x25b,  0x3,    0x2,    0x2,    0x2,    0x228,  0x22d,  0x5,   0x98,  0x4d,
        0x2,   0x229, 0x22a,  0x7,    0x27f,  0x2,    0x2,    0x22a,  0x22b,  0x5,   0x58,  0x2d,
        0x2,   0x22b, 0x22c,  0x7,    0x280,  0x2,    0x2,    0x22c,  0x22e,  0x3,   0x2,   0x2,
        0x2,   0x22d, 0x229,  0x3,    0x2,    0x2,    0x2,    0x22d,  0x22e,  0x3,   0x2,   0x2,
        0x2,   0x22e, 0x230,  0x3,    0x2,    0x2,    0x2,    0x22f,  0x231,  0x7,   0x20,  0x2,
        0x2,   0x230, 0x22f,  0x3,    0x2,    0x2,    0x2,    0x230,  0x231,  0x3,   0x2,   0x2,
        0x2,   0x231, 0x233,  0x3,    0x2,    0x2,    0x2,    0x232,  0x234,  0x5,   0x4c,  0x27,
        0x2,   0x233, 0x232,  0x3,    0x2,    0x2,    0x2,    0x233,  0x234,  0x3,   0x2,   0x2,
        0x2,   0x234, 0x236,  0x3,    0x2,    0x2,    0x2,    0x235,  0x237,  0x5,   0x4e,  0x28,
        0x2,   0x236, 0x235,  0x3,    0x2,    0x2,    0x2,    0x236,  0x237,  0x3,   0x2,   0x2,
        0x2,   0x237, 0x25b,  0x3,    0x2,    0x2,    0x2,    0x238,  0x23d,  0x5,   0x96,  0x4c,
        0x2,   0x239, 0x23a,  0x7,    0x27f,  0x2,    0x2,    0x23a,  0x23b,  0x5,   0x58,  0x2d,
        0x2,   0x23b, 0x23c,  0x7,    0x280,  0x2,    0x2,    0x23c,  0x23e,  0x3,   0x2,   0x2,
        0x2,   0x23d, 0x239,  0x3,    0x2,    0x2,    0x2,    0x23d,  0x23e,  0x3,   0x2,   0x2,
        0x2,   0x23e, 0x25b,  0x3,    0x2,    0x2,    0x2,    0x23f,  0x25b,  0x5,   0x90,  0x49,
        0x2,   0x240, 0x245,  0x5,    0x8e,   0x48,   0x2,    0x241,  0x242,  0x7,   0x27f, 0x2,
        0x2,   0x242, 0x243,  0x5,    0x58,   0x2d,   0x2,    0x243,  0x244,  0x7,   0x280, 0x2,
        0x2,   0x244, 0x246,  0x3,    0x2,    0x2,    0x2,    0x245,  0x241,  0x3,   0x2,   0x2,
        0x2,   0x245, 0x246,  0x3,    0x2,    0x2,    0x2,    0x246,  0x248,  0x3,   0x2,   0x2,
        0x2,   0x247, 0x249,  0x7,    0x20,   0x2,    0x2,    0x248,  0x247,  0x3,   0x2,   0x2,
        0x2,   0x248, 0x249,  0x3,    0x2,    0x2,    0x2,    0x249,  0x24b,  0x3,   0x2,   0x2,
        0x2,   0x24a, 0x24c,  0x5,    0x4c,   0x27,   0x2,    0x24b,  0x24a,  0x3,   0x2,   0x2,
        0x2,   0x24b, 0x24c,  0x3,    0x2,    0x2,    0x2,    0x24c,  0x24e,  0x3,   0x2,   0x2,
        0x2,   0x24d, 0x24f,  0x5,    0x4e,   0x28,   0x2,    0x24e,  0x24d,  0x3,   0x2,   0x2,
        0x2,   0x24e, 0x24f,  0x3,    0x2,    0x2,    0x2,    0x24f,  0x25b,  0x3,   0x2,   0x2,
        0x2,   0x250, 0x251,  0x5,    0x94,   0x4b,   0x2,    0x251,  0x253,  0x5,   0x40,  0x21,
        0x2,   0x252, 0x254,  0x5,    0x4c,   0x27,   0x2,    0x253,  0x252,  0x3,   0x2,   0x2,
        0x2,   0x253, 0x254,  0x3,    0x2,    0x2,    0x2,    0x254,  0x256,  0x3,   0x2,   0x2,
        0x2,   0x255, 0x257,  0x5,    0x4e,   0x28,   0x2,    0x256,  0x255,  0x3,   0x2,   0x2,
        0x2,   0x256, 0x257,  0x3,    0x2,    0x2,    0x2,    0x257,  0x25b,  0x3,   0x2,   0x2,
        0x2,   0x258, 0x25b,  0x5,    0x92,   0x4a,   0x2,    0x259,  0x25b,  0x7,   0xfe,  0x2,
        0x2,   0x25a, 0x203,  0x3,    0x2,    0x2,    0x2,    0x25a,  0x210,  0x3,   0x2,   0x2,
        0x2,   0x25a, 0x221,  0x3,    0x2,    0x2,    0x2,    0x25a,  0x228,  0x3,   0x2,   0x2,
        0x2,   0x25a, 0x238,  0x3,    0x2,    0x2,    0x2,    0x25a,  0x23f,  0x3,   0x2,   0x2,
        0x2,   0x25a, 0x240,  0x3,    0x2,    0x2,    0x2,    0x25a,  0x250,  0x3,   0x2,   0x2,
        0x2,   0x25a, 0x258,  0x3,    0x2,    0x2,    0x2,    0x25a,  0x259,  0x3,   0x2,   0x2,
        0x2,   0x25b, 0x19,   0x3,    0x2,    0x2,    0x2,    0x25c,  0x25e,  0x7,   0x95,  0x2,
        0x2,   0x25d, 0x25f,  0x7,    0x285,  0x2,    0x2,    0x25e,  0x25d,  0x3,   0x2,   0x2,
        0x2,   0x25e, 0x25f,  0x3,    0x2,    0x2,    0x2,    0x25f,  0x260,  0x3,   0x2,   0x2,
        0x2,   0x260, 0x2d7,  0x5,    0xbc,   0x5f,   0x2,    0x261,  0x263,  0x7,   0x18,  0x2,
        0x2,   0x262, 0x264,  0x7,    0x285,  0x2,    0x2,    0x263,  0x262,  0x3,   0x2,   0x2,
        0x2,   0x263, 0x264,  0x3,    0x2,    0x2,    0x2,    0x264,  0x265,  0x3,   0x2,   0x2,
        0x2,   0x265, 0x2d7,  0x5,    0x60,   0x31,   0x2,    0x266,  0x268,  0x7,   0x1a,  0x2,
        0x2,   0x267, 0x269,  0x7,    0x285,  0x2,    0x2,    0x268,  0x267,  0x3,   0x2,   0x2,
        0x2,   0x268, 0x269,  0x3,    0x2,    0x2,    0x2,    0x269,  0x26a,  0x3,   0x2,   0x2,
        0x2,   0x26a, 0x2d7,  0x5,    0x62,   0x32,   0x2,    0x26b,  0x26d,  0x7,   0x74,  0x2,
        0x2,   0x26c, 0x26b,  0x3,    0x2,    0x2,    0x2,    0x26c,  0x26d,  0x3,   0x2,   0x2,
        0x2,   0x26d, 0x26e,  0x3,    0x2,    0x2,    0x2,    0x26e,  0x2d7,  0x5,   0x4c,  0x27,
        0x2,   0x26f, 0x271,  0x7,    0x39,   0x2,    0x2,    0x270,  0x272,  0x7,   0x285, 0x2,
        0x2,   0x271, 0x270,  0x3,    0x2,    0x2,    0x2,    0x271,  0x272,  0x3,   0x2,   0x2,
        0x2,   0x272, 0x273,  0x3,    0x2,    0x2,    0x2,    0x273,  0x2d7,  0x5,   0x6c,  0x37,
        0x2,   0x274, 0x276,  0x7,    0x74,   0x2,    0x2,    0x275,  0x274,  0x3,   0x2,   0x2,
        0x2,   0x275, 0x276,  0x3,    0x2,    0x2,    0x2,    0x276,  0x277,  0x3,   0x2,   0x2,
        0x2,   0x277, 0x2d7,  0x5,    0x4e,   0x28,   0x2,    0x278,  0x27a,  0x7,   0x46,  0x2,
        0x2,   0x279, 0x27b,  0x7,    0x285,  0x2,    0x2,    0x27a,  0x279,  0x3,   0x2,   0x2,
        0x2,   0x27a, 0x27b,  0x3,    0x2,    0x2,    0x2,    0x27b,  0x27c,  0x3,   0x2,   0x2,
        0x2,   0x27c, 0x2d7,  0x5,    0xa0,   0x51,   0x2,    0x27d,  0x27f,  0x7,   0x4c,  0x2,
        0x2,   0x27e, 0x280,  0x7,    0x285,  0x2,    0x2,    0x27f,  0x27e,  0x3,   0x2,   0x2,
        0x2,   0x27f, 0x280,  0x3,    0x2,    0x2,    0x2,    0x280,  0x281,  0x3,   0x2,   0x2,
        0x2,   0x281, 0x2d7,  0x5,    0x6e,   0x38,   0x2,    0x282,  0x284,  0x7,   0x4f,  0x2,
        0x2,   0x283, 0x285,  0x7,    0x285,  0x2,    0x2,    0x284,  0x283,  0x3,   0x2,   0x2,
        0x2,   0x284, 0x285,  0x3,    0x2,    0x2,    0x2,    0x285,  0x286,  0x3,   0x2,   0x2,
        0x2,   0x286, 0x2d7,  0x5,    0xa2,   0x52,   0x2,    0x287,  0x288,  0x7,   0x65,  0x2,
        0x2,   0x288, 0x28a,  0x7,    0x7f,   0x2,    0x2,    0x289,  0x28b,  0x7,   0x285, 0x2,
        0x2,   0x28a, 0x289,  0x3,    0x2,    0x2,    0x2,    0x28a,  0x28b,  0x3,   0x2,   0x2,
        0x2,   0x28b, 0x28c,  0x3,    0x2,    0x2,    0x2,    0x28c,  0x2d7,  0x5,   0xa6,  0x54,
        0x2,   0x28d, 0x28f,  0x7,    0x78,   0x2,    0x2,    0x28e,  0x290,  0x7,   0x285, 0x2,
        0x2,   0x28f, 0x28e,  0x3,    0x2,    0x2,    0x2,    0x28f,  0x290,  0x3,   0x2,   0x2,
        0x2,   0x290, 0x291,  0x3,    0x2,    0x2,    0x2,    0x291,  0x2d7,  0x5,   0x70,  0x39,
        0x2,   0x292, 0x294,  0x7,    0x92,   0x2,    0x2,    0x293,  0x295,  0x7,   0x285, 0x2,
        0x2,   0x294, 0x293,  0x3,    0x2,    0x2,    0x2,    0x294,  0x295,  0x3,   0x2,   0x2,
        0x2,   0x295, 0x296,  0x3,    0x2,    0x2,    0x2,    0x296,  0x2d7,  0x5,   0x72,  0x3a,
        0x2,   0x297, 0x298,  0x7,    0xde,   0x2,    0x2,    0x298,  0x29a,  0x7,   0x7f,  0x2,
        0x2,   0x299, 0x29b,  0x7,    0x285,  0x2,    0x2,    0x29a,  0x299,  0x3,   0x2,   0x2,
        0x2,   0x29a, 0x29b,  0x3,    0x2,    0x2,    0x2,    0x29b,  0x29c,  0x3,   0x2,   0x2,
        0x2,   0x29c, 0x2d7,  0x5,    0xa8,   0x55,   0x2,    0x29d,  0x29f,  0x7,   0xe7,  0x2,
        0x2,   0x29e, 0x2a0,  0x7,    0x285,  0x2,    0x2,    0x29f,  0x29e,  0x3,   0x2,   0x2,
        0x2,   0x29f, 0x2a0,  0x3,    0x2,    0x2,    0x2,    0x2a0,  0x2a1,  0x3,   0x2,   0x2,
        0x2,   0x2a1, 0x2d7,  0x5,    0x74,   0x3b,   0x2,    0x2a2,  0x2a4,  0x7,   0x101, 0x2,
        0x2,   0x2a3, 0x2a5,  0x7,    0x285,  0x2,    0x2,    0x2a4,  0x2a3,  0x3,   0x2,   0x2,
        0x2,   0x2a4, 0x2a5,  0x3,    0x2,    0x2,    0x2,    0x2a5,  0x2a6,  0x3,   0x2,   0x2,
        0x2,   0x2a6, 0x2d7,  0x5,    0x64,   0x33,   0x2,    0x2a7,  0x2a9,  0x7,   0x13a, 0x2,
        0x2,   0x2a8, 0x2aa,  0x7,    0x285,  0x2,    0x2,    0x2a9,  0x2a8,  0x3,   0x2,   0x2,
        0x2,   0x2a9, 0x2aa,  0x3,    0x2,    0x2,    0x2,    0x2aa,  0x2ab,  0x3,   0x2,   0x2,
        0x2,   0x2ab, 0x2d7,  0x5,    0x66,   0x34,   0x2,    0x2ac,  0x2ae,  0x7,   0x14c, 0x2,
        0x2,   0x2ad, 0x2af,  0x7,    0x285,  0x2,    0x2,    0x2ae,  0x2ad,  0x3,   0x2,   0x2,
        0x2,   0x2ae, 0x2af,  0x3,    0x2,    0x2,    0x2,    0x2af,  0x2b0,  0x3,   0x2,   0x2,
        0x2,   0x2b0, 0x2d7,  0x5,    0x68,   0x35,   0x2,    0x2b1,  0x2b3,  0x7,   0x17d, 0x2,
        0x2,   0x2b2, 0x2b4,  0x7,    0x285,  0x2,    0x2,    0x2b3,  0x2b2,  0x3,   0x2,   0x2,
        0x2,   0x2b3, 0x2b4,  0x3,    0x2,    0x2,    0x2,    0x2b4,  0x2b5,  0x3,   0x2,   0x2,
        0x2,   0x2b5, 0x2d7,  0x5,    0x76,   0x3c,   0x2,    0x2b6,  0x2b8,  0x7,   0x185, 0x2,
        0x2,   0x2b7, 0x2b9,  0x7,    0x285,  0x2,    0x2,    0x2b8,  0x2b7,  0x3,   0x2,   0x2,
        0x2,   0x2b8, 0x2b9,  0x3,    0x2,    0x2,    0x2,    0x2b9,  0x2ba,  0x3,   0x2,   0x2,
        0x2,   0x2ba, 0x2d7,  0x5,    0xa4,   0x53,   0x2,    0x2bb,  0x2bd,  0x7,   0x1d4, 0x2,
        0x2,   0x2bc, 0x2be,  0x7,    0x285,  0x2,    0x2,    0x2bd,  0x2bc,  0x3,   0x2,   0x2,
        0x2,   0x2bd, 0x2be,  0x3,    0x2,    0x2,    0x2,    0x2be,  0x2bf,  0x3,   0x2,   0x2,
        0x2,   0x2bf, 0x2d7,  0x5,    0x78,   0x3d,   0x2,    0x2c0,  0x2c2,  0x7,   0x213, 0x2,
        0x2,   0x2c1, 0x2c3,  0x7,    0x285,  0x2,    0x2,    0x2c2,  0x2c1,  0x3,   0x2,   0x2,
        0x2,   0x2c2, 0x2c3,  0x3,    0x2,    0x2,    0x2,    0x2c3,  0x2c4,  0x3,   0x2,   0x2,
        0x2,   0x2c4, 0x2d7,  0x5,    0x7a,   0x3e,   0x2,    0x2c5,  0x2c7,  0x7,   0x214, 0x2,
        0x2,   0x2c6, 0x2c8,  0x7,    0x285,  0x2,    0x2,    0x2c7,  0x2c6,  0x3,   0x2,   0x2,
        0x2,   0x2c7, 0x2c8,  0x3,    0x2,    0x2,    0x2,    0x2c8,  0x2c9,  0x3,   0x2,   0x2,
        0x2,   0x2c9, 0x2d7,  0x5,    0x7c,   0x3f,   0x2,    0x2ca,  0x2cc,  0x7,   0x215, 0x2,
        0x2,   0x2cb, 0x2cd,  0x7,    0x285,  0x2,    0x2,    0x2cc,  0x2cb,  0x3,   0x2,   0x2,
        0x2,   0x2cc, 0x2cd,  0x3,    0x2,    0x2,    0x2,    0x2cd,  0x2ce,  0x3,   0x2,   0x2,
        0x2,   0x2ce, 0x2d7,  0x5,    0x6a,   0x36,   0x2,    0x2cf,  0x2d0,  0x7,   0x226, 0x2,
        0x2,   0x2d0, 0x2d7,  0x5,    0xc4,   0x63,   0x2,    0x2d1,  0x2d3,  0x7,   0x246, 0x2,
        0x2,   0x2d2, 0x2d4,  0x7,    0x285,  0x2,    0x2,    0x2d3,  0x2d2,  0x3,   0x2,   0x2,
        0x2,   0x2d3, 0x2d4,  0x3,    0x2,    0x2,    0x2,    0x2d4,  0x2d5,  0x3,   0x2,   0x2,
        0x2,   0x2d5, 0x2d7,  0x5,    0x48,   0x25,   0x2,    0x2d6,  0x25c,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x261,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x266,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x26c,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x26f,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x275,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x278,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x27d,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x282,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x287,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x28d,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x292,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x297,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x29d,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x2a2,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x2a7,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x2ac,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x2b1,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x2b6,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x2bb,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x2c0,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x2c5,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x2ca,  0x3,   0x2,   0x2,
        0x2,   0x2d6, 0x2cf,  0x3,    0x2,    0x2,    0x2,    0x2d6,  0x2d1,  0x3,   0x2,   0x2,
        0x2,   0x2d7, 0x1b,   0x3,    0x2,    0x2,    0x2,    0x2d8,  0x2d9,  0x7,   0x182, 0x2,
        0x2,   0x2d9, 0x2da,  0x7,    0x29,   0x2,    0x2,    0x2da,  0x2dd,  0x5,   0x20,  0x11,
        0x2,   0x2db, 0x2dc,  0x7,    0x184,  0x2,    0x2,    0x2dc,  0x2de,  0x5,   0x5c,  0x2f,
        0x2,   0x2dd, 0x2db,  0x3,    0x2,    0x2,    0x2,    0x2dd,  0x2de,  0x3,   0x2,   0x2,
        0x2,   0x2de, 0x2e6,  0x3,    0x2,    0x2,    0x2,    0x2df,  0x2e0,  0x7,   0x21e, 0x2,
        0x2,   0x2e0, 0x2e1,  0x7,    0x29,   0x2,    0x2,    0x2e1,  0x2e4,  0x5,   0x22,  0x12,
        0x2,   0x2e2, 0x2e3,  0x7,    0x21f,  0x2,    0x2,    0x2e3,  0x2e5,  0x5,   0x5e,  0x30,
        0x2,   0x2e4, 0x2e2,  0x3,    0x2,    0x2,    0x2,    0x2e4,  0x2e5,  0x3,   0x2,   0x2,
        0x2,   0x2e5, 0x2e7,  0x3,    0x2,    0x2,    0x2,    0x2e6,  0x2df,  0x3,   0x2,   0x2,
        0x2,   0x2e6, 0x2e7,  0x3,    0x2,    0x2,    0x2,    0x2e7,  0x2e9,  0x3,   0x2,   0x2,
        0x2,   0x2e8, 0x2ea,  0x5,    0x1e,   0x10,   0x2,    0x2e9,  0x2e8,  0x3,   0x2,   0x2,
        0x2,   0x2e9, 0x2ea,  0x3,    0x2,    0x2,    0x2,    0x2ea,  0x1d,   0x3,   0x2,   0x2,
        0x2,   0x2eb, 0x2ec,  0x7,    0x27f,  0x2,    0x2,    0x2ec,  0x2f1,  0x5,   0x24,  0x13,
        0x2,   0x2ed, 0x2ee,  0x7,    0x282,  0x2,    0x2,    0x2ee,  0x2f0,  0x5,   0x24,  0x13,
        0x2,   0x2ef, 0x2ed,  0x3,    0x2,    0x2,    0x2,    0x2f0,  0x2f3,  0x3,   0x2,   0x2,
        0x2,   0x2f1, 0x2ef,  0x3,    0x2,    0x2,    0x2,    0x2f1,  0x2f2,  0x3,   0x2,   0x2,
        0x2,   0x2f2, 0x2f4,  0x3,    0x2,    0x2,    0x2,    0x2f3,  0x2f1,  0x3,   0x2,   0x2,
        0x2,   0x2f4, 0x2f5,  0x7,    0x280,  0x2,    0x2,    0x2f5,  0x1f,   0x3,   0x2,   0x2,
        0x2,   0x2f6, 0x2f8,  0x7,    0x10d,  0x2,    0x2,    0x2f7,  0x2f6,  0x3,   0x2,   0x2,
        0x2,   0x2f7, 0x2f8,  0x3,    0x2,    0x2,    0x2,    0x2f8,  0x2f9,  0x3,   0x2,   0x2,
        0x2,   0x2f9, 0x2fa,  0x7,    0xce,   0x2,    0x2,    0x2fa,  0x312,  0x5,   0xb0,  0x59,
        0x2,   0x2fb, 0x2fd,  0x7,    0x10d,  0x2,    0x2,    0x2fc,  0x2fb,  0x3,   0x2,   0x2,
        0x2,   0x2fc, 0x2fd,  0x3,    0x2,    0x2,    0x2,    0x2fd,  0x2fe,  0x3,   0x2,   0x2,
        0x2,   0x2fe, 0x302,  0x7,    0xff,   0x2,    0x2,    0x2ff,  0x300,  0x7,   0xa,   0x2,
        0x2,   0x300, 0x301,  0x7,    0x285,  0x2,    0x2,    0x301,  0x303,  0x5,   0x7e,  0x40,
        0x2,   0x302, 0x2ff,  0x3,    0x2,    0x2,    0x2,    0x302,  0x303,  0x3,   0x2,   0x2,
        0x2,   0x303, 0x304,  0x3,    0x2,    0x2,    0x2,    0x304,  0x312,  0x5,   0x42,  0x22,
        0x2,   0x305, 0x309,  0x7,    0x19d,  0x2,    0x2,    0x306,  0x30a,  0x5,   0xb2,  0x5a,
        0x2,   0x307, 0x308,  0x7,    0x43,   0x2,    0x2,    0x308,  0x30a,  0x5,   0x44,  0x23,
        0x2,   0x309, 0x306,  0x3,    0x2,    0x2,    0x2,    0x309,  0x307,  0x3,   0x2,   0x2,
        0x2,   0x30a, 0x312,  0x3,    0x2,    0x2,    0x2,    0x30b,  0x30f,  0x7,   0x110, 0x2,
        0x2,   0x30c, 0x310,  0x5,    0xb4,   0x5b,   0x2,    0x30d,  0x30e,  0x7,   0x43,  0x2,
        0x2,   0x30e, 0x310,  0x5,    0x46,   0x24,   0x2,    0x30f,  0x30c,  0x3,   0x2,   0x2,
        0x2,   0x30f, 0x30d,  0x3,    0x2,    0x2,    0x2,    0x310,  0x312,  0x3,   0x2,   0x2,
        0x2,   0x311, 0x2f7,  0x3,    0x2,    0x2,    0x2,    0x311,  0x2fc,  0x3,   0x2,   0x2,
        0x2,   0x311, 0x305,  0x3,    0x2,    0x2,    0x2,    0x311,  0x30b,  0x3,   0x2,   0x2,
        0x2,   0x312, 0x21,   0x3,    0x2,    0x2,    0x2,    0x313,  0x315,  0x7,   0x10d, 0x2,
        0x2,   0x314, 0x313,  0x3,    0x2,    0x2,    0x2,    0x314,  0x315,  0x3,   0x2,   0x2,
        0x2,   0x315, 0x316,  0x3,    0x2,    0x2,    0x2,    0x316,  0x317,  0x7,   0xce,  0x2,
        0x2,   0x317, 0x323,  0x5,    0xb0,   0x59,   0x2,    0x318,  0x31a,  0x7,   0x10d, 0x2,
        0x2,   0x319, 0x318,  0x3,    0x2,    0x2,    0x2,    0x319,  0x31a,  0x3,   0x2,   0x2,
        0x2,   0x31a, 0x31b,  0x3,    0x2,    0x2,    0x2,    0x31b,  0x31f,  0x7,   0xff,  0x2,
        0x2,   0x31c, 0x31d,  0x7,    0xa,    0x2,    0x2,    0x31d,  0x31e,  0x7,   0x285, 0x2,
        0x2,   0x31e, 0x320,  0x5,    0x7e,   0x40,   0x2,    0x31f,  0x31c,  0x3,   0x2,   0x2,
        0x2,   0x31f, 0x320,  0x3,    0x2,    0x2,    0x2,    0x320,  0x321,  0x3,   0x2,   0x2,
        0x2,   0x321, 0x323,  0x5,    0x42,   0x22,   0x2,    0x322,  0x314,  0x3,   0x2,   0x2,
        0x2,   0x322, 0x319,  0x3,    0x2,    0x2,    0x2,    0x323,  0x23,   0x3,   0x2,   0x2,
        0x2,   0x324, 0x325,  0x7,    0x182,  0x2,    0x2,    0x325,  0x327,  0x5,   0xd0,  0x69,
        0x2,   0x326, 0x328,  0x5,    0x28,   0x15,   0x2,    0x327,  0x326,  0x3,   0x2,   0x2,
        0x2,   0x327, 0x328,  0x3,    0x2,    0x2,    0x2,    0x328,  0x329,  0x3,   0x2,   0x2,
        0x2,   0x329, 0x32b,  0x5,    0x2c,   0x17,   0x2,    0x32a,  0x32c,  0x5,   0x26,  0x14,
        0x2,   0x32b, 0x32a,  0x3,    0x2,    0x2,    0x2,    0x32b,  0x32c,  0x3,   0x2,   0x2,
        0x2,   0x32c, 0x25,   0x3,    0x2,    0x2,    0x2,    0x32d,  0x32e,  0x7,   0x27f, 0x2,
        0x2,   0x32e, 0x333,  0x5,    0x2a,   0x16,   0x2,    0x32f,  0x330,  0x7,   0x282, 0x2,
        0x2,   0x330, 0x332,  0x5,    0x2a,   0x16,   0x2,    0x331,  0x32f,  0x3,   0x2,   0x2,
        0x2,   0x332, 0x335,  0x3,    0x2,    0x2,    0x2,    0x333,  0x331,  0x3,   0x2,   0x2,
        0x2,   0x333, 0x334,  0x3,    0x2,    0x2,    0x2,    0x334,  0x336,  0x3,   0x2,   0x2,
        0x2,   0x335, 0x333,  0x3,    0x2,    0x2,    0x2,    0x336,  0x337,  0x7,   0x280, 0x2,
        0x2,   0x337, 0x27,   0x3,    0x2,    0x2,    0x2,    0x338,  0x342,  0x7,   0x259, 0x2,
        0x2,   0x339, 0x33a,  0x7,    0x109,  0x2,    0x2,    0x33a,  0x33e,  0x7,   0x22d, 0x2,
        0x2,   0x33b, 0x33f,  0x5,    0xb6,   0x5c,   0x2,    0x33c,  0x33f,  0x5,   0x3c,  0x1f,
        0x2,   0x33d, 0x33f,  0x7,    0x137,  0x2,    0x2,    0x33e,  0x33b,  0x3,   0x2,   0x2,
        0x2,   0x33e, 0x33c,  0x3,    0x2,    0x2,    0x2,    0x33e,  0x33d,  0x3,   0x2,   0x2,
        0x2,   0x33f, 0x343,  0x3,    0x2,    0x2,    0x2,    0x340,  0x341,  0x7,   0xdd,  0x2,
        0x2,   0x341, 0x343,  0x5,    0x3e,   0x20,   0x2,    0x342,  0x339,  0x3,   0x2,   0x2,
        0x2,   0x342, 0x340,  0x3,    0x2,    0x2,    0x2,    0x343,  0x29,   0x3,   0x2,   0x2,
        0x2,   0x344, 0x345,  0x7,    0x21e,  0x2,    0x2,    0x345,  0x346,  0x5,   0xd2,  0x6a,
        0x2,   0x346, 0x347,  0x5,    0x2c,   0x17,   0x2,    0x347,  0x2b,   0x3,   0x2,   0x2,
        0x2,   0x348, 0x34a,  0x7,    0x218,  0x2,    0x2,    0x349,  0x348,  0x3,   0x2,   0x2,
        0x2,   0x349, 0x34a,  0x3,    0x2,    0x2,    0x2,    0x34a,  0x34b,  0x3,   0x2,   0x2,
        0x2,   0x34b, 0x34d,  0x7,    0x95,   0x2,    0x2,    0x34c,  0x34e,  0x7,   0x285, 0x2,
        0x2,   0x34d, 0x34c,  0x3,    0x2,    0x2,    0x2,    0x34d,  0x34e,  0x3,   0x2,   0x2,
        0x2,   0x34e, 0x34f,  0x3,    0x2,    0x2,    0x2,    0x34f,  0x351,  0x5,   0xbc,  0x5f,
        0x2,   0x350, 0x349,  0x3,    0x2,    0x2,    0x2,    0x350,  0x351,  0x3,   0x2,   0x2,
        0x2,   0x351, 0x357,  0x3,    0x2,    0x2,    0x2,    0x352,  0x354,  0x7,   0x46,  0x2,
        0x2,   0x353, 0x355,  0x7,    0x285,  0x2,    0x2,    0x354,  0x353,  0x3,   0x2,   0x2,
        0x2,   0x354, 0x355,  0x3,    0x2,    0x2,    0x2,    0x355,  0x356,  0x3,   0x2,   0x2,
        0x2,   0x356, 0x358,  0x5,    0xa0,   0x51,   0x2,    0x357,  0x352,  0x3,   0x2,   0x2,
        0x2,   0x357, 0x358,  0x3,    0x2,    0x2,    0x2,    0x358,  0x35f,  0x3,   0x2,   0x2,
        0x2,   0x359, 0x35a,  0x7,    0x65,   0x2,    0x2,    0x35a,  0x35c,  0x7,   0x7f,  0x2,
        0x2,   0x35b, 0x35d,  0x7,    0x285,  0x2,    0x2,    0x35c,  0x35b,  0x3,   0x2,   0x2,
        0x2,   0x35c, 0x35d,  0x3,    0x2,    0x2,    0x2,    0x35d,  0x35e,  0x3,   0x2,   0x2,
        0x2,   0x35e, 0x360,  0x5,    0xa6,   0x54,   0x2,    0x35f,  0x359,  0x3,   0x2,   0x2,
        0x2,   0x35f, 0x360,  0x3,    0x2,    0x2,    0x2,    0x360,  0x367,  0x3,   0x2,   0x2,
        0x2,   0x361, 0x362,  0x7,    0xde,   0x2,    0x2,    0x362,  0x364,  0x7,   0x7f,  0x2,
        0x2,   0x363, 0x365,  0x7,    0x285,  0x2,    0x2,    0x364,  0x363,  0x3,   0x2,   0x2,
        0x2,   0x364, 0x365,  0x3,    0x2,    0x2,    0x2,    0x365,  0x366,  0x3,   0x2,   0x2,
        0x2,   0x366, 0x368,  0x5,    0xa8,   0x55,   0x2,    0x367,  0x361,  0x3,   0x2,   0x2,
        0x2,   0x367, 0x368,  0x3,    0x2,    0x2,    0x2,    0x368,  0x36e,  0x3,   0x2,   0x2,
        0x2,   0x369, 0x36b,  0x7,    0x13a,  0x2,    0x2,    0x36a,  0x36c,  0x7,   0x285, 0x2,
        0x2,   0x36b, 0x36a,  0x3,    0x2,    0x2,    0x2,    0x36b,  0x36c,  0x3,   0x2,   0x2,
        0x2,   0x36c, 0x36d,  0x3,    0x2,    0x2,    0x2,    0x36d,  0x36f,  0x5,   0x66,  0x34,
        0x2,   0x36e, 0x369,  0x3,    0x2,    0x2,    0x2,    0x36e,  0x36f,  0x3,   0x2,   0x2,
        0x2,   0x36f, 0x375,  0x3,    0x2,    0x2,    0x2,    0x370,  0x372,  0x7,   0x14c, 0x2,
        0x2,   0x371, 0x373,  0x7,    0x285,  0x2,    0x2,    0x372,  0x371,  0x3,   0x2,   0x2,
        0x2,   0x372, 0x373,  0x3,    0x2,    0x2,    0x2,    0x373,  0x374,  0x3,   0x2,   0x2,
        0x2,   0x374, 0x376,  0x5,    0x68,   0x35,   0x2,    0x375,  0x370,  0x3,   0x2,   0x2,
        0x2,   0x375, 0x376,  0x3,    0x2,    0x2,    0x2,    0x376,  0x37c,  0x3,   0x2,   0x2,
        0x2,   0x377, 0x379,  0x7,    0x226,  0x2,    0x2,    0x378,  0x37a,  0x7,   0x285, 0x2,
        0x2,   0x379, 0x378,  0x3,    0x2,    0x2,    0x2,    0x379,  0x37a,  0x3,   0x2,   0x2,
        0x2,   0x37a, 0x37b,  0x3,    0x2,    0x2,    0x2,    0x37b,  0x37d,  0x5,   0xc4,  0x63,
        0x2,   0x37c, 0x377,  0x3,    0x2,    0x2,    0x2,    0x37c,  0x37d,  0x3,   0x2,   0x2,
        0x2,   0x37d, 0x2d,   0x3,    0x2,    0x2,    0x2,    0x37e,  0x380,  0x7,   0x101, 0x2,
        0x2,   0x37f, 0x381,  0x7,    0x285,  0x2,    0x2,    0x380,  0x37f,  0x3,   0x2,   0x2,
        0x2,   0x380, 0x381,  0x3,    0x2,    0x2,    0x2,    0x381,  0x382,  0x3,   0x2,   0x2,
        0x2,   0x382, 0x38b,  0x5,    0x64,   0x33,   0x2,    0x383,  0x384,  0x7,   0x253, 0x2,
        0x2,   0x384, 0x38b,  0x5,    0x50,   0x29,   0x2,    0x385,  0x386,  0x7,   0x268, 0x2,
        0x2,   0x386, 0x387,  0x7,    0x17f,  0x2,    0x2,    0x387,  0x38b,  0x5,   0xca,  0x66,
        0x2,   0x388, 0x389,  0x7,    0x46,   0x2,    0x2,    0x389,  0x38b,  0x5,   0xa0,  0x51,
        0x2,   0x38a, 0x37e,  0x3,    0x2,    0x2,    0x2,    0x38a,  0x383,  0x3,   0x2,   0x2,
        0x2,   0x38a, 0x385,  0x3,    0x2,    0x2,    0x2,    0x38a,  0x388,  0x3,   0x2,   0x2,
        0x2,   0x38b, 0x2f,   0x3,    0x2,    0x2,    0x2,    0x38c,  0x38d,  0x7,   0x1a8, 0x2,
        0x2,   0x38d, 0x38f,  0x5,    0xc6,   0x64,   0x2,    0x38e,  0x390,  0x5,   0x3a,  0x1e,
        0x2,   0x38f, 0x38e,  0x3,    0x2,    0x2,    0x2,    0x38f,  0x390,  0x3,   0x2,   0x2,
        0x2,   0x390, 0x393,  0x3,    0x2,    0x2,    0x2,    0x391,  0x392,  0x7,   0x136, 0x2,
        0x2,   0x392, 0x394,  0x5,    0x80,   0x41,   0x2,    0x393,  0x391,  0x3,   0x2,   0x2,
        0x2,   0x393, 0x394,  0x3,    0x2,    0x2,    0x2,    0x394,  0x398,  0x3,   0x2,   0x2,
        0x2,   0x395, 0x396,  0x7,    0x16e,  0x2,    0x2,    0x396,  0x397,  0x7,   0x79,  0x2,
        0x2,   0x397, 0x399,  0x5,    0x82,   0x42,   0x2,    0x398,  0x395,  0x3,   0x2,   0x2,
        0x2,   0x398, 0x399,  0x3,    0x2,    0x2,    0x2,    0x399,  0x39d,  0x3,   0x2,   0x2,
        0x2,   0x39a, 0x39b,  0x7,    0x16e,  0x2,    0x2,    0x39b,  0x39c,  0x7,   0x24c, 0x2,
        0x2,   0x39c, 0x39e,  0x5,    0x84,   0x43,   0x2,    0x39d,  0x39a,  0x3,   0x2,   0x2,
        0x2,   0x39d, 0x39e,  0x3,    0x2,    0x2,    0x2,    0x39e,  0x31,   0x3,   0x2,   0x2,
        0x2,   0x39f, 0x3a0,  0x7,    0x27f,  0x2,    0x2,    0x3a0,  0x3a5,  0x5,   0xe,   0x8,
        0x2,   0x3a1, 0x3a2,  0x7,    0x282,  0x2,    0x2,    0x3a2,  0x3a4,  0x5,   0xe,   0x8,
        0x2,   0x3a3, 0x3a1,  0x3,    0x2,    0x2,    0x2,    0x3a4,  0x3a7,  0x3,   0x2,   0x2,
        0x2,   0x3a5, 0x3a3,  0x3,    0x2,    0x2,    0x2,    0x3a5,  0x3a6,  0x3,   0x2,   0x2,
        0x2,   0x3a6, 0x3a8,  0x3,    0x2,    0x2,    0x2,    0x3a7,  0x3a5,  0x3,   0x2,   0x2,
        0x2,   0x3a8, 0x3a9,  0x7,    0x280,  0x2,    0x2,    0x3a9,  0x33,   0x3,   0x2,   0x2,
        0x2,   0x3aa, 0x3b1,  0x5,    0x1a,   0xe,    0x2,    0x3ab,  0x3ad,  0x7,   0x282, 0x2,
        0x2,   0x3ac, 0x3ab,  0x3,    0x2,    0x2,    0x2,    0x3ac,  0x3ad,  0x3,   0x2,   0x2,
        0x2,   0x3ad, 0x3ae,  0x3,    0x2,    0x2,    0x2,    0x3ae,  0x3b0,  0x5,   0x1a,  0xe,
        0x2,   0x3af, 0x3ac,  0x3,    0x2,    0x2,    0x2,    0x3b0,  0x3b3,  0x3,   0x2,   0x2,
        0x2,   0x3b1, 0x3af,  0x3,    0x2,    0x2,    0x2,    0x3b1,  0x3b2,  0x3,   0x2,   0x2,
        0x2,   0x3b2, 0x35,   0x3,    0x2,    0x2,    0x2,    0x3b3,  0x3b1,  0x3,   0x2,   0x2,
        0x2,   0x3b4, 0x3b6,  0x5,    0x2e,   0x18,   0x2,    0x3b5,  0x3b4,  0x3,   0x2,   0x2,
        0x2,   0x3b6, 0x3b9,  0x3,    0x2,    0x2,    0x2,    0x3b7,  0x3b5,  0x3,   0x2,   0x2,
        0x2,   0x3b7, 0x3b8,  0x3,    0x2,    0x2,    0x2,    0x3b8,  0x37,   0x3,   0x2,   0x2,
        0x2,   0x3b9, 0x3b7,  0x3,    0x2,    0x2,    0x2,    0x3ba,  0x3bb,  0x7,   0x27f, 0x2,
        0x2,   0x3bb, 0x3c0,  0x5,    0x52,   0x2a,   0x2,    0x3bc,  0x3bd,  0x7,   0x282, 0x2,
        0x2,   0x3bd, 0x3bf,  0x5,    0x52,   0x2a,   0x2,    0x3be,  0x3bc,  0x3,   0x2,   0x2,
        0x2,   0x3bf, 0x3c2,  0x3,    0x2,    0x2,    0x2,    0x3c0,  0x3be,  0x3,   0x2,   0x2,
        0x2,   0x3c0, 0x3c1,  0x3,    0x2,    0x2,    0x2,    0x3c1,  0x3c3,  0x3,   0x2,   0x2,
        0x2,   0x3c2, 0x3c0,  0x3,    0x2,    0x2,    0x2,    0x3c3,  0x3c4,  0x7,   0x280, 0x2,
        0x2,   0x3c4, 0x39,   0x3,    0x2,    0x2,    0x2,    0x3c5,  0x3c6,  0x7,   0x27f, 0x2,
        0x2,   0x3c6, 0x3cb,  0x5,    0x54,   0x2b,   0x2,    0x3c7,  0x3c8,  0x7,   0x282, 0x2,
        0x2,   0x3c8, 0x3ca,  0x5,    0x54,   0x2b,   0x2,    0x3c9,  0x3c7,  0x3,   0x2,   0x2,
        0x2,   0x3ca, 0x3cd,  0x3,    0x2,    0x2,    0x2,    0x3cb,  0x3c9,  0x3,   0x2,   0x2,
        0x2,   0x3cb, 0x3cc,  0x3,    0x2,    0x2,    0x2,    0x3cc,  0x3ce,  0x3,   0x2,   0x2,
        0x2,   0x3cd, 0x3cb,  0x3,    0x2,    0x2,    0x2,    0x3ce,  0x3cf,  0x7,   0x280, 0x2,
        0x2,   0x3cf, 0x3b,   0x3,    0x2,    0x2,    0x2,    0x3d0,  0x3d1,  0x7,   0x27f, 0x2,
        0x2,   0x3d1, 0x3d6,  0x5,    0xd4,   0x6b,   0x2,    0x3d2,  0x3d3,  0x7,   0x282, 0x2,
        0x2,   0x3d3, 0x3d5,  0x5,    0xd4,   0x6b,   0x2,    0x3d4,  0x3d2,  0x3,   0x2,   0x2,
        0x2,   0x3d5, 0x3d8,  0x3,    0x2,    0x2,    0x2,    0x3d6,  0x3d4,  0x3,   0x2,   0x2,
        0x2,   0x3d6, 0x3d7,  0x3,    0x2,    0x2,    0x2,    0x3d7,  0x3d9,  0x3,   0x2,   0x2,
        0x2,   0x3d8, 0x3d6,  0x3,    0x2,    0x2,    0x2,    0x3d9,  0x3da,  0x7,   0x280, 0x2,
        0x2,   0x3da, 0x3d,   0x3,    0x2,    0x2,    0x2,    0x3db,  0x3dc,  0x7,   0x27f, 0x2,
        0x2,   0x3dc, 0x3e1,  0x5,    0xd4,   0x6b,   0x2,    0x3dd,  0x3de,  0x7,   0x282, 0x2,
        0x2,   0x3de, 0x3e0,  0x5,    0xd4,   0x6b,   0x2,    0x3df,  0x3dd,  0x3,   0x2,   0x2,
        0x2,   0x3e0, 0x3e3,  0x3,    0x2,    0x2,    0x2,    0x3e1,  0x3df,  0x3,   0x2,   0x2,
        0x2,   0x3e1, 0x3e2,  0x3,    0x2,    0x2,    0x2,    0x3e2,  0x3e4,  0x3,   0x2,   0x2,
        0x2,   0x3e3, 0x3e1,  0x3,    0x2,    0x2,    0x2,    0x3e4,  0x3e5,  0x7,   0x280, 0x2,
        0x2,   0x3e5, 0x3f,   0x3,    0x2,    0x2,    0x2,    0x3e6,  0x3e7,  0x7,   0x27f, 0x2,
        0x2,   0x3e7, 0x3ec,  0x5,    0xd4,   0x6b,   0x2,    0x3e8,  0x3e9,  0x7,   0x282, 0x2,
        0x2,   0x3e9, 0x3eb,  0x5,    0xd4,   0x6b,   0x2,    0x3ea,  0x3e8,  0x3,   0x2,   0x2,
        0x2,   0x3eb, 0x3ee,  0x3,    0x2,    0x2,    0x2,    0x3ec,  0x3ea,  0x3,   0x2,   0x2,
        0x2,   0x3ec, 0x3ed,  0x3,    0x2,    0x2,    0x2,    0x3ed,  0x3ef,  0x3,   0x2,   0x2,
        0x2,   0x3ee, 0x3ec,  0x3,    0x2,    0x2,    0x2,    0x3ef,  0x3f0,  0x7,   0x280, 0x2,
        0x2,   0x3f0, 0x41,   0x3,    0x2,    0x2,    0x2,    0x3f1,  0x3f2,  0x7,   0x27f, 0x2,
        0x2,   0x3f2, 0x3f7,  0x5,    0xd6,   0x6c,   0x2,    0x3f3,  0x3f4,  0x7,   0x282, 0x2,
        0x2,   0x3f4, 0x3f6,  0x5,    0xd6,   0x6c,   0x2,    0x3f5,  0x3f3,  0x3,   0x2,   0x2,
        0x2,   0x3f6, 0x3f9,  0x3,    0x2,    0x2,    0x2,    0x3f7,  0x3f5,  0x3,   0x2,   0x2,
        0x2,   0x3f7, 0x3f8,  0x3,    0x2,    0x2,    0x2,    0x3f8,  0x3fa,  0x3,   0x2,   0x2,
        0x2,   0x3f9, 0x3f7,  0x3,    0x2,    0x2,    0x2,    0x3fa,  0x3fb,  0x7,   0x280, 0x2,
        0x2,   0x3fb, 0x43,   0x3,    0x2,    0x2,    0x2,    0x3fc,  0x3fd,  0x7,   0x27f, 0x2,
        0x2,   0x3fd, 0x402,  0x5,    0xd6,   0x6c,   0x2,    0x3fe,  0x3ff,  0x7,   0x282, 0x2,
        0x2,   0x3ff, 0x401,  0x5,    0xd6,   0x6c,   0x2,    0x400,  0x3fe,  0x3,   0x2,   0x2,
        0x2,   0x401, 0x404,  0x3,    0x2,    0x2,    0x2,    0x402,  0x400,  0x3,   0x2,   0x2,
        0x2,   0x402, 0x403,  0x3,    0x2,    0x2,    0x2,    0x403,  0x405,  0x3,   0x2,   0x2,
        0x2,   0x404, 0x402,  0x3,    0x2,    0x2,    0x2,    0x405,  0x406,  0x7,   0x280, 0x2,
        0x2,   0x406, 0x45,   0x3,    0x2,    0x2,    0x2,    0x407,  0x408,  0x7,   0x27f, 0x2,
        0x2,   0x408, 0x40d,  0x5,    0xd6,   0x6c,   0x2,    0x409,  0x40a,  0x7,   0x282, 0x2,
        0x2,   0x40a, 0x40c,  0x5,    0xd6,   0x6c,   0x2,    0x40b,  0x409,  0x3,   0x2,   0x2,
        0x2,   0x40c, 0x40f,  0x3,    0x2,    0x2,    0x2,    0x40d,  0x40b,  0x3,   0x2,   0x2,
        0x2,   0x40d, 0x40e,  0x3,    0x2,    0x2,    0x2,    0x40e,  0x410,  0x3,   0x2,   0x2,
        0x2,   0x40f, 0x40d,  0x3,    0x2,    0x2,    0x2,    0x410,  0x411,  0x7,   0x280, 0x2,
        0x2,   0x411, 0x47,   0x3,    0x2,    0x2,    0x2,    0x412,  0x413,  0x7,   0x27f, 0x2,
        0x2,   0x413, 0x418,  0x5,    0xc6,   0x64,   0x2,    0x414,  0x415,  0x7,   0x282, 0x2,
        0x2,   0x415, 0x417,  0x5,    0xc6,   0x64,   0x2,    0x416,  0x414,  0x3,   0x2,   0x2,
        0x2,   0x417, 0x41a,  0x3,    0x2,    0x2,    0x2,    0x418,  0x416,  0x3,   0x2,   0x2,
        0x2,   0x418, 0x419,  0x3,    0x2,    0x2,    0x2,    0x419,  0x41b,  0x3,   0x2,   0x2,
        0x2,   0x41a, 0x418,  0x3,    0x2,    0x2,    0x2,    0x41b,  0x41c,  0x7,   0x280, 0x2,
        0x2,   0x41c, 0x49,   0x3,    0x2,    0x2,    0x2,    0x41d,  0x41f,  0x7,   0x51,  0x2,
        0x2,   0x41e, 0x420,  0x5,    0xba,   0x5e,   0x2,    0x41f,  0x41e,  0x3,   0x2,   0x2,
        0x2,   0x41f, 0x420,  0x3,    0x2,    0x2,    0x2,    0x420,  0x4b,   0x3,   0x2,   0x2,
        0x2,   0x421, 0x422,  0x7,    0x36,   0x2,    0x2,    0x422,  0x425,  0x7,   0x1e5, 0x2,
        0x2,   0x423, 0x425,  0x7,    0x37,   0x2,    0x2,    0x424,  0x421,  0x3,   0x2,   0x2,
        0x2,   0x424, 0x423,  0x3,    0x2,    0x2,    0x2,    0x425,  0x427,  0x3,   0x2,   0x2,
        0x2,   0x426, 0x428,  0x7,    0x285,  0x2,    0x2,    0x427,  0x426,  0x3,   0x2,   0x2,
        0x2,   0x427, 0x428,  0x3,    0x2,    0x2,    0x2,    0x428,  0x429,  0x3,   0x2,   0x2,
        0x2,   0x429, 0x42a,  0x5,    0xcc,   0x67,   0x2,    0x42a,  0x4d,   0x3,   0x2,   0x2,
        0x2,   0x42b, 0x42d,  0x7,    0x40,   0x2,    0x2,    0x42c,  0x42e,  0x7,   0x285, 0x2,
        0x2,   0x42d, 0x42c,  0x3,    0x2,    0x2,    0x2,    0x42d,  0x42e,  0x3,   0x2,   0x2,
        0x2,   0x42e, 0x42f,  0x3,    0x2,    0x2,    0x2,    0x42f,  0x430,  0x5,   0xce,  0x68,
        0x2,   0x430, 0x4f,   0x3,    0x2,    0x2,    0x2,    0x431,  0x432,  0x9,   0x7,   0x2,
        0x2,   0x432, 0x51,   0x3,    0x2,    0x2,    0x2,    0x433,  0x438,  0x5,   0xc0,  0x61,
        0x2,   0x434, 0x435,  0x7,    0x27f,  0x2,    0x2,    0x435,  0x436,  0x5,   0x58,  0x2d,
        0x2,   0x436, 0x437,  0x7,    0x280,  0x2,    0x2,    0x437,  0x439,  0x3,   0x2,   0x2,
        0x2,   0x438, 0x434,  0x3,    0x2,    0x2,    0x2,    0x438,  0x439,  0x3,   0x2,   0x2,
        0x2,   0x439, 0x43b,  0x3,    0x2,    0x2,    0x2,    0x43a,  0x43c,  0x9,   0x8,   0x2,
        0x2,   0x43b, 0x43a,  0x3,    0x2,    0x2,    0x2,    0x43b,  0x43c,  0x3,   0x2,   0x2,
        0x2,   0x43c, 0x53,   0x3,    0x2,    0x2,    0x2,    0x43d,  0x442,  0x5,   0xc0,  0x61,
        0x2,   0x43e, 0x43f,  0x7,    0x27f,  0x2,    0x2,    0x43f,  0x440,  0x5,   0x58,  0x2d,
        0x2,   0x440, 0x441,  0x7,    0x280,  0x2,    0x2,    0x441,  0x443,  0x3,   0x2,   0x2,
        0x2,   0x442, 0x43e,  0x3,    0x2,    0x2,    0x2,    0x442,  0x443,  0x3,   0x2,   0x2,
        0x2,   0x443, 0x445,  0x3,    0x2,    0x2,    0x2,    0x444,  0x446,  0x9,   0x8,   0x2,
        0x2,   0x445, 0x444,  0x3,    0x2,    0x2,    0x2,    0x445,  0x446,  0x3,   0x2,   0x2,
        0x2,   0x446, 0x55,   0x3,    0x2,    0x2,    0x2,    0x447,  0x448,  0x5,   0xdc,  0x6f,
        0x2,   0x448, 0x57,   0x3,    0x2,    0x2,    0x2,    0x449,  0x44a,  0x5,   0xdc,  0x6f,
        0x2,   0x44a, 0x59,   0x3,    0x2,    0x2,    0x2,    0x44b,  0x44c,  0x5,   0xdc,  0x6f,
        0x2,   0x44c, 0x5b,   0x3,    0x2,    0x2,    0x2,    0x44d,  0x44e,  0x5,   0xdc,  0x6f,
        0x2,   0x44e, 0x5d,   0x3,    0x2,    0x2,    0x2,    0x44f,  0x450,  0x5,   0xdc,  0x6f,
        0x2,   0x450, 0x5f,   0x3,    0x2,    0x2,    0x2,    0x451,  0x452,  0x5,   0xdc,  0x6f,
        0x2,   0x452, 0x61,   0x3,    0x2,    0x2,    0x2,    0x453,  0x454,  0x5,   0xdc,  0x6f,
        0x2,   0x454, 0x63,   0x3,    0x2,    0x2,    0x2,    0x455,  0x456,  0x5,   0xdc,  0x6f,
        0x2,   0x456, 0x65,   0x3,    0x2,    0x2,    0x2,    0x457,  0x458,  0x5,   0xdc,  0x6f,
        0x2,   0x458, 0x67,   0x3,    0x2,    0x2,    0x2,    0x459,  0x45a,  0x5,   0xdc,  0x6f,
        0x2,   0x45a, 0x69,   0x3,    0x2,    0x2,    0x2,    0x45b,  0x45c,  0x5,   0xdc,  0x6f,
        0x2,   0x45c, 0x6b,   0x3,    0x2,    0x2,    0x2,    0x45d,  0x45e,  0x5,   0xdc,  0x6f,
        0x2,   0x45e, 0x6d,   0x3,    0x2,    0x2,    0x2,    0x45f,  0x460,  0x5,   0xde,  0x70,
        0x2,   0x460, 0x6f,   0x3,    0x2,    0x2,    0x2,    0x461,  0x462,  0x5,   0xdc,  0x6f,
        0x2,   0x462, 0x71,   0x3,    0x2,    0x2,    0x2,    0x463,  0x464,  0x5,   0xde,  0x70,
        0x2,   0x464, 0x73,   0x3,    0x2,    0x2,    0x2,    0x465,  0x466,  0x9,   0x9,   0x2,
        0x2,   0x466, 0x75,   0x3,    0x2,    0x2,    0x2,    0x467,  0x46a,  0x5,   0xdc,  0x6f,
        0x2,   0x468, 0x46a,  0x7,    0x74,   0x2,    0x2,    0x469,  0x467,  0x3,   0x2,   0x2,
        0x2,   0x469, 0x468,  0x3,    0x2,    0x2,    0x2,    0x46a,  0x77,   0x3,   0x2,   0x2,
        0x2,   0x46b, 0x46c,  0x9,    0xa,    0x2,    0x2,    0x46c,  0x79,   0x3,   0x2,   0x2,
        0x2,   0x46d, 0x470,  0x7,    0x74,   0x2,    0x2,    0x46e,  0x470,  0x5,   0xdc,  0x6f,
        0x2,   0x46f, 0x46d,  0x3,    0x2,    0x2,    0x2,    0x46f,  0x46e,  0x3,   0x2,   0x2,
        0x2,   0x470, 0x7b,   0x3,    0x2,    0x2,    0x2,    0x471,  0x474,  0x7,   0x74,  0x2,
        0x2,   0x472, 0x474,  0x5,    0xdc,   0x6f,   0x2,    0x473,  0x471,  0x3,   0x2,   0x2,
        0x2,   0x473, 0x472,  0x3,    0x2,    0x2,    0x2,    0x474,  0x7d,   0x3,   0x2,   0x2,
        0x2,   0x475, 0x476,  0x5,    0xdc,   0x6f,   0x2,    0x476,  0x7f,   0x3,   0x2,   0x2,
        0x2,   0x477, 0x478,  0x9,    0xb,    0x2,    0x2,    0x478,  0x81,   0x3,   0x2,   0x2,
        0x2,   0x479, 0x480,  0x7,    0x1c4,  0x2,    0x2,    0x47a,  0x480,  0x7,   0x2d,  0x2,
        0x2,   0x47b, 0x47c,  0x7,    0x1e5,  0x2,    0x2,    0x47c,  0x480,  0x7,   0x168, 0x2,
        0x2,   0x47d, 0x47e,  0x7,    0x161,  0x2,    0x2,    0x47e,  0x480,  0x7,   0x5,   0x2,
        0x2,   0x47f, 0x479,  0x3,    0x2,    0x2,    0x2,    0x47f,  0x47a,  0x3,   0x2,   0x2,
        0x2,   0x47f, 0x47b,  0x3,    0x2,    0x2,    0x2,    0x47f,  0x47d,  0x3,   0x2,   0x2,
        0x2,   0x480, 0x83,   0x3,    0x2,    0x2,    0x2,    0x481,  0x488,  0x7,   0x1c4, 0x2,
        0x2,   0x482, 0x488,  0x7,    0x2d,   0x2,    0x2,    0x483,  0x484,  0x7,   0x1e5, 0x2,
        0x2,   0x484, 0x488,  0x7,    0x168,  0x2,    0x2,    0x485,  0x486,  0x7,   0x161, 0x2,
        0x2,   0x486, 0x488,  0x7,    0x5,    0x2,    0x2,    0x487,  0x481,  0x3,   0x2,   0x2,
        0x2,   0x487, 0x482,  0x3,    0x2,    0x2,    0x2,    0x487,  0x483,  0x3,   0x2,   0x2,
        0x2,   0x487, 0x485,  0x3,    0x2,    0x2,    0x2,    0x488,  0x85,   0x3,   0x2,   0x2,
        0x2,   0x489, 0x48a,  0x9,    0xc,    0x2,    0x2,    0x48a,  0x87,   0x3,   0x2,   0x2,
        0x2,   0x48b, 0x48c,  0x9,    0xd,    0x2,    0x2,    0x48c,  0x89,   0x3,   0x2,   0x2,
        0x2,   0x48d, 0x48e,  0x9,    0xe,    0x2,    0x2,    0x48e,  0x8b,   0x3,   0x2,   0x2,
        0x2,   0x48f, 0x498,  0x7,    0x1a2,  0x2,    0x2,    0x490,  0x492,  0x7,   0x87,  0x2,
        0x2,   0x491, 0x493,  0x7,    0x18e,  0x2,    0x2,    0x492,  0x491,  0x3,   0x2,   0x2,
        0x2,   0x492, 0x493,  0x3,    0x2,    0x2,    0x2,    0x493,  0x498,  0x3,   0x2,   0x2,
        0x2,   0x494, 0x498,  0x7,    0xb4,   0x2,    0x2,    0x495,  0x498,  0x7,   0x72,  0x2,
        0x2,   0x496, 0x498,  0x7,    0x16a,  0x2,    0x2,    0x497,  0x48f,  0x3,   0x2,   0x2,
        0x2,   0x497, 0x490,  0x3,    0x2,    0x2,    0x2,    0x497,  0x494,  0x3,   0x2,   0x2,
        0x2,   0x497, 0x495,  0x3,    0x2,    0x2,    0x2,    0x497,  0x496,  0x3,   0x2,   0x2,
        0x2,   0x498, 0x8d,   0x3,    0x2,    0x2,    0x2,    0x499,  0x49a,  0x9,   0xf,   0x2,
        0x2,   0x49a, 0x8f,   0x3,    0x2,    0x2,    0x2,    0x49b,  0x49c,  0x9,   0x10,  0x2,
        0x2,   0x49c, 0x91,   0x3,    0x2,    0x2,    0x2,    0x49d,  0x49e,  0x9,   0x11,  0x2,
        0x2,   0x49e, 0x93,   0x3,    0x2,    0x2,    0x2,    0x49f,  0x4a0,  0x9,   0x12,  0x2,
        0x2,   0x4a0, 0x95,   0x3,    0x2,    0x2,    0x2,    0x4a1,  0x4a2,  0x9,   0x13,  0x2,
        0x2,   0x4a2, 0x97,   0x3,    0x2,    0x2,    0x2,    0x4a3,  0x4a4,  0x9,   0x14,  0x2,
        0x2,   0x4a4, 0x99,   0x3,    0x2,    0x2,    0x2,    0x4a5,  0x4a6,  0x9,   0x15,  0x2,
        0x2,   0x4a6, 0x9b,   0x3,    0x2,    0x2,    0x2,    0x4a7,  0x4a8,  0x5,   0xd4,  0x6b,
        0x2,   0x4a8, 0x9d,   0x3,    0x2,    0x2,    0x2,    0x4a9,  0x4aa,  0x5,   0xd4,  0x6b,
        0x2,   0x4aa, 0x9f,   0x3,    0x2,    0x2,    0x2,    0x4ab,  0x4ac,  0x5,   0xde,  0x70,
        0x2,   0x4ac, 0xa1,   0x3,    0x2,    0x2,    0x2,    0x4ad,  0x4ae,  0x5,   0xde,  0x70,
        0x2,   0x4ae, 0xa3,   0x3,    0x2,    0x2,    0x2,    0x4af,  0x4b0,  0x5,   0xde,  0x70,
        0x2,   0x4b0, 0xa5,   0x3,    0x2,    0x2,    0x2,    0x4b1,  0x4b2,  0x5,   0xde,  0x70,
        0x2,   0x4b2, 0xa7,   0x3,    0x2,    0x2,    0x2,    0x4b3,  0x4b4,  0x5,   0xde,  0x70,
        0x2,   0x4b4, 0xa9,   0x3,    0x2,    0x2,    0x2,    0x4b5,  0x4b6,  0x5,   0xb8,  0x5d,
        0x2,   0x4b6, 0xab,   0x3,    0x2,    0x2,    0x2,    0x4b7,  0x4b8,  0x5,   0xb8,  0x5d,
        0x2,   0x4b8, 0xad,   0x3,    0x2,    0x2,    0x2,    0x4b9,  0x4ba,  0x5,   0xb8,  0x5d,
        0x2,   0x4ba, 0xaf,   0x3,    0x2,    0x2,    0x2,    0x4bb,  0x4bc,  0x5,   0xb8,  0x5d,
        0x2,   0x4bc, 0xb1,   0x3,    0x2,    0x2,    0x2,    0x4bd,  0x4be,  0x5,   0xb8,  0x5d,
        0x2,   0x4be, 0xb3,   0x3,    0x2,    0x2,    0x2,    0x4bf,  0x4c0,  0x5,   0xb8,  0x5d,
        0x2,   0x4c0, 0xb5,   0x3,    0x2,    0x2,    0x2,    0x4c1,  0x4c2,  0x5,   0xb8,  0x5d,
        0x2,   0x4c2, 0xb7,   0x3,    0x2,    0x2,    0x2,    0x4c3,  0x4c4,  0x7,   0x27f, 0x2,
        0x2,   0x4c4, 0x4c5,  0x5,    0xd4,   0x6b,   0x2,    0x4c5,  0x4c6,  0x7,   0x280, 0x2,
        0x2,   0x4c6, 0xb9,   0x3,    0x2,    0x2,    0x2,    0x4c7,  0x4c8,  0x5,   0xd6,  0x6c,
        0x2,   0x4c8, 0xbb,   0x3,    0x2,    0x2,    0x2,    0x4c9,  0x4ca,  0x5,   0xd6,  0x6c,
        0x2,   0x4ca, 0xbd,   0x3,    0x2,    0x2,    0x2,    0x4cb,  0x4cc,  0x5,   0xc6,  0x64,
        0x2,   0x4cc, 0xbf,   0x3,    0x2,    0x2,    0x2,    0x4cd,  0x4ce,  0x5,   0xd6,  0x6c,
        0x2,   0x4ce, 0xc1,   0x3,    0x2,    0x2,    0x2,    0x4cf,  0x4d0,  0x5,   0xd6,  0x6c,
        0x2,   0x4d0, 0xc3,   0x3,    0x2,    0x2,    0x2,    0x4d1,  0x4d2,  0x5,   0xd6,  0x6c,
        0x2,   0x4d2, 0xc5,   0x3,    0x2,    0x2,    0x2,    0x4d3,  0x4d4,  0x5,   0xc8,  0x65,
        0x2,   0x4d4, 0x4d5,  0x7,    0x281,  0x2,    0x2,    0x4d5,  0x4d7,  0x3,   0x2,   0x2,
        0x2,   0x4d6, 0x4d3,  0x3,    0x2,    0x2,    0x2,    0x4d6,  0x4d7,  0x3,   0x2,   0x2,
        0x2,   0x4d7, 0x4d8,  0x3,    0x2,    0x2,    0x2,    0x4d8,  0x4d9,  0x5,   0xd6,  0x6c,
        0x2,   0x4d9, 0xc7,   0x3,    0x2,    0x2,    0x2,    0x4da,  0x4db,  0x5,   0xd6,  0x6c,
        0x2,   0x4db, 0xc9,   0x3,    0x2,    0x2,    0x2,    0x4dc,  0x4dd,  0x5,   0xd6,  0x6c,
        0x2,   0x4dd, 0xcb,   0x3,    0x2,    0x2,    0x2,    0x4de,  0x4df,  0x5,   0xd6,  0x6c,
        0x2,   0x4df, 0xcd,   0x3,    0x2,    0x2,    0x2,    0x4e0,  0x4e1,  0x5,   0xd6,  0x6c,
        0x2,   0x4e1, 0xcf,   0x3,    0x2,    0x2,    0x2,    0x4e2,  0x4e3,  0x5,   0xd6,  0x6c,
        0x2,   0x4e3, 0xd1,   0x3,    0x2,    0x2,    0x2,    0x4e4,  0x4e5,  0x5,   0xd6,  0x6c,
        0x2,   0x4e5, 0xd3,   0x3,    0x2,    0x2,    0x2,    0x4e6,  0x4ed,  0x7,   0x168, 0x2,
        0x2,   0x4e7, 0x4ed,  0x5,    0xd8,   0x6d,   0x2,    0x4e8,  0x4ed,  0x5,   0xda,  0x6e,
        0x2,   0x4e9, 0x4ed,  0x5,    0xdc,   0x6f,   0x2,    0x4ea,  0x4ed,  0x5,   0xde,  0x70,
        0x2,   0x4eb, 0x4ed,  0x5,    0xe0,   0x71,   0x2,    0x4ec,  0x4e6,  0x3,   0x2,   0x2,
        0x2,   0x4ec, 0x4e7,  0x3,    0x2,    0x2,    0x2,    0x4ec,  0x4e8,  0x3,   0x2,   0x2,
        0x2,   0x4ec, 0x4e9,  0x3,    0x2,    0x2,    0x2,    0x4ec,  0x4ea,  0x3,   0x2,   0x2,
        0x2,   0x4ec, 0x4eb,  0x3,    0x2,    0x2,    0x2,    0x4ed,  0xd5,   0x3,   0x2,   0x2,
        0x2,   0x4ee, 0x4ef,  0x9,    0x16,   0x2,    0x2,    0x4ef,  0xd7,   0x3,   0x2,   0x2,
        0x2,   0x4f0, 0x4f1,  0x9,    0x17,   0x2,    0x2,    0x4f1,  0xd9,   0x3,   0x2,   0x2,
        0x2,   0x4f2, 0x4f3,  0x7,    0x276,  0x2,    0x2,    0x4f3,  0xdb,   0x3,   0x2,   0x2,
        0x2,   0x4f4, 0x4f5,  0x7,    0x277,  0x2,    0x2,    0x4f5,  0xdd,   0x3,   0x2,   0x2,
        0x2,   0x4f6, 0x4f7,  0x9,    0x18,   0x2,    0x2,    0x4f7,  0xdf,   0x3,   0x2,   0x2,
        0x2,   0x4f8, 0x4f9,  0x9,    0x19,   0x2,    0x2,    0x4f9,  0xe1,   0x3,   0x2,   0x2,
        0x2,   0x4fa, 0x4fc,  0x7,    0xc,    0x2,    0x2,    0x4fb,  0x4fd,  0x7,   0xda,  0x2,
        0x2,   0x4fc, 0x4fb,  0x3,    0x2,    0x2,    0x2,    0x4fc,  0x4fd,  0x3,   0x2,   0x2,
        0x2,   0x4fd, 0x4fe,  0x3,    0x2,    0x2,    0x2,    0x4fe,  0x4ff,  0x7,   0x224, 0x2,
        0x2,   0x4ff, 0x501,  0x5,    0xc6,   0x64,   0x2,    0x500,  0x502,  0x5,   0xe6,  0x74,
        0x2,   0x501, 0x500,  0x3,    0x2,    0x2,    0x2,    0x501,  0x502,  0x3,   0x2,   0x2,
        0x2,   0x502, 0x504,  0x3,    0x2,    0x2,    0x2,    0x503,  0x505,  0x5,   0x1c,  0xf,
        0x2,   0x504, 0x503,  0x3,    0x2,    0x2,    0x2,    0x504,  0x505,  0x3,   0x2,   0x2,
        0x2,   0x505, 0xe3,   0x3,    0x2,    0x2,    0x2,    0x506,  0x5c8,  0x5,   0x34,  0x1b,
        0x2,   0x507, 0x509,  0x7,    0x6,    0x2,    0x2,    0x508,  0x50a,  0x7,   0x42,  0x2,
        0x2,   0x509, 0x508,  0x3,    0x2,    0x2,    0x2,    0x509,  0x50a,  0x3,   0x2,   0x2,
        0x2,   0x50a, 0x50b,  0x3,    0x2,    0x2,    0x2,    0x50b,  0x50c,  0x5,   0xc0,  0x61,
        0x2,   0x50c, 0x50e,  0x5,    0x12,   0xa,    0x2,    0x50d,  0x50f,  0x5,   0xf2,  0x7a,
        0x2,   0x50e, 0x50d,  0x3,    0x2,    0x2,    0x2,    0x50e,  0x50f,  0x3,   0x2,   0x2,
        0x2,   0x50f, 0x5c8,  0x3,    0x2,    0x2,    0x2,    0x510,  0x512,  0x7,   0x6,   0x2,
        0x2,   0x511, 0x513,  0x7,    0x42,   0x2,    0x2,    0x512,  0x511,  0x3,   0x2,   0x2,
        0x2,   0x512, 0x513,  0x3,    0x2,    0x2,    0x2,    0x513,  0x514,  0x3,   0x2,   0x2,
        0x2,   0x514, 0x5c8,  0x5,    0xec,   0x77,   0x2,    0x515,  0x516,  0x7,   0x6,   0x2,
        0x2,   0x516, 0x5c8,  0x5,    0x10,   0x9,    0x2,    0x517,  0x519,  0x7,   0xa,   0x2,
        0x2,   0x518, 0x51a,  0x7,    0x285,  0x2,    0x2,    0x519,  0x518,  0x3,   0x2,   0x2,
        0x2,   0x519, 0x51a,  0x3,    0x2,    0x2,    0x2,    0x51a,  0x51b,  0x3,   0x2,   0x2,
        0x2,   0x51b, 0x5c8,  0x5,    0xee,   0x78,   0x2,    0x51c,  0x51e,  0x7,   0xc,   0x2,
        0x2,   0x51d, 0x51f,  0x7,    0x42,   0x2,    0x2,    0x51e,  0x51d,  0x3,   0x2,   0x2,
        0x2,   0x51e, 0x51f,  0x3,    0x2,    0x2,    0x2,    0x51f,  0x520,  0x3,   0x2,   0x2,
        0x2,   0x520, 0x526,  0x5,    0xc0,   0x61,   0x2,    0x521,  0x522,  0x7,   0x1e5, 0x2,
        0x2,   0x522, 0x523,  0x7,    0x74,   0x2,    0x2,    0x523,  0x527,  0x5,   0x9e,  0x50,
        0x2,   0x524, 0x525,  0x7,    0x88,   0x2,    0x2,    0x525,  0x527,  0x7,   0x74,  0x2,
        0x2,   0x526, 0x521,  0x3,    0x2,    0x2,    0x2,    0x526,  0x524,  0x3,   0x2,   0x2,
        0x2,   0x527, 0x5c8,  0x3,    0x2,    0x2,    0x2,    0x528,  0x52a,  0x7,   0x32,  0x2,
        0x2,   0x529, 0x52b,  0x7,    0x42,   0x2,    0x2,    0x52a,  0x529,  0x3,   0x2,   0x2,
        0x2,   0x52a, 0x52b,  0x3,    0x2,    0x2,    0x2,    0x52b,  0x52c,  0x3,   0x2,   0x2,
        0x2,   0x52c, 0x52d,  0x5,    0xf8,   0x7d,   0x2,    0x52d,  0x52e,  0x5,   0xfa,  0x7e,
        0x2,   0x52e, 0x530,  0x5,    0x12,   0xa,    0x2,    0x52f,  0x531,  0x5,   0xf2,  0x7a,
        0x2,   0x530, 0x52f,  0x3,    0x2,    0x2,    0x2,    0x530,  0x531,  0x3,   0x2,   0x2,
        0x2,   0x531, 0x5c8,  0x3,    0x2,    0x2,    0x2,    0x532,  0x534,  0x7,   0x115, 0x2,
        0x2,   0x533, 0x535,  0x7,    0x285,  0x2,    0x2,    0x534,  0x533,  0x3,   0x2,   0x2,
        0x2,   0x534, 0x535,  0x3,    0x2,    0x2,    0x2,    0x535,  0x536,  0x3,   0x2,   0x2,
        0x2,   0x536, 0x5c8,  0x5,    0xf0,   0x79,   0x2,    0x537,  0x539,  0x7,   0x150, 0x2,
        0x2,   0x538, 0x53a,  0x7,    0x42,   0x2,    0x2,    0x539,  0x538,  0x3,   0x2,   0x2,
        0x2,   0x539, 0x53a,  0x3,    0x2,    0x2,    0x2,    0x53a,  0x53b,  0x3,   0x2,   0x2,
        0x2,   0x53b, 0x53c,  0x5,    0xc0,   0x61,   0x2,    0x53c,  0x53e,  0x5,   0x12,  0xa,
        0x2,   0x53d, 0x53f,  0x5,    0xf2,   0x7a,   0x2,    0x53e,  0x53d,  0x3,   0x2,   0x2,
        0x2,   0x53e, 0x53f,  0x3,    0x2,    0x2,    0x2,    0x53f,  0x5c8,  0x3,   0x2,   0x2,
        0x2,   0x540, 0x542,  0x7,    0x88,   0x2,    0x2,    0x541,  0x543,  0x7,   0x42,  0x2,
        0x2,   0x542, 0x541,  0x3,    0x2,    0x2,    0x2,    0x542,  0x543,  0x3,   0x2,   0x2,
        0x2,   0x543, 0x544,  0x3,    0x2,    0x2,    0x2,    0x544,  0x5c8,  0x5,   0xc0,  0x61,
        0x2,   0x545, 0x546,  0x7,    0x88,   0x2,    0x2,    0x546,  0x547,  0x7,   0x192, 0x2,
        0x2,   0x547, 0x5c8,  0x7,    0xff,   0x2,    0x2,    0x548,  0x549,  0x7,   0x88,  0x2,
        0x2,   0x549, 0x54a,  0x9,    0x4,    0x2,    0x2,    0x54a,  0x5c8,  0x5,   0xc2,  0x62,
        0x2,   0x54b, 0x54c,  0x7,    0x88,   0x2,    0x2,    0x54c,  0x54d,  0x7,   0xbb,  0x2,
        0x2,   0x54d, 0x54e,  0x7,    0xff,   0x2,    0x2,    0x54e,  0x5c8,  0x5,   0xf4,  0x7b,
        0x2,   0x54f, 0x550,  0x7,    0x80,   0x2,    0x2,    0x550,  0x5c8,  0x7,   0x100, 0x2,
        0x2,   0x551, 0x552,  0x7,    0x90,   0x2,    0x2,    0x552,  0x5c8,  0x7,   0x100, 0x2,
        0x2,   0x553, 0x555,  0x7,    0x1b2,  0x2,    0x2,    0x554,  0x556,  0x9,   0x1a,  0x2,
        0x2,   0x555, 0x554,  0x3,    0x2,    0x2,    0x2,    0x555,  0x556,  0x3,   0x2,   0x2,
        0x2,   0x556, 0x557,  0x3,    0x2,    0x2,    0x2,    0x557,  0x5c8,  0x5,   0xf6,  0x7c,
        0x2,   0x558, 0x559,  0x7,    0x1b2,  0x2,    0x2,    0x559,  0x55a,  0x9,   0x4,   0x2,
        0x2,   0x55a, 0x55b,  0x5,    0xfc,   0x7f,   0x2,    0x55b,  0x55c,  0x7,   0x236, 0x2,
        0x2,   0x55c, 0x55d,  0x5,    0xfe,   0x80,   0x2,    0x55d,  0x5c8,  0x3,   0x2,   0x2,
        0x2,   0x55e, 0x55f,  0x7,    0x178,  0x2,    0x2,    0x55f,  0x560,  0x7,   0x29,  0x2,
        0x2,   0x560, 0x5c8,  0x5,    0xe8,   0x75,   0x2,    0x561,  0x562,  0x7,   0x58,  0x2,
        0x2,   0x562, 0x563,  0x7,    0x236,  0x2,    0x2,    0x563,  0x565,  0x5,   0x4c,  0x27,
        0x2,   0x564, 0x566,  0x5,    0x4e,   0x28,   0x2,    0x565,  0x564,  0x3,   0x2,   0x2,
        0x2,   0x565, 0x566,  0x3,    0x2,    0x2,    0x2,    0x566,  0x5c8,  0x3,   0x2,   0x2,
        0x2,   0x567, 0x569,  0x7,    0x74,   0x2,    0x2,    0x568,  0x567,  0x3,   0x2,   0x2,
        0x2,   0x568, 0x569,  0x3,    0x2,    0x2,    0x2,    0x569,  0x56a,  0x3,   0x2,   0x2,
        0x2,   0x56a, 0x56c,  0x5,    0x4c,   0x27,   0x2,    0x56b,  0x56d,  0x5,   0x4e,  0x28,
        0x2,   0x56c, 0x56b,  0x3,    0x2,    0x2,    0x2,    0x56c,  0x56d,  0x3,   0x2,   0x2,
        0x2,   0x56d, 0x5c8,  0x3,    0x2,    0x2,    0x2,    0x56e,  0x56f,  0x7,   0x81,  0x2,
        0x2,   0x56f, 0x5c8,  0x7,    0x226,  0x2,    0x2,    0x570,  0x571,  0x7,   0xdc,  0x2,
        0x2,   0x571, 0x5c8,  0x7,    0x226,  0x2,    0x2,    0x572,  0x5c8,  0x7,   0xba,  0x2,
        0x2,   0x573, 0x574,  0x9,    0x1b,   0x2,    0x2,    0x574,  0x5c8,  0x7,   0x257, 0x2,
        0x2,   0x575, 0x576,  0x7,    0x6,    0x2,    0x2,    0x576,  0x577,  0x7,   0x182, 0x2,
        0x2,   0x577, 0x578,  0x7,    0x27f,  0x2,    0x2,    0x578,  0x579,  0x5,   0x24,  0x13,
        0x2,   0x579, 0x57a,  0x7,    0x280,  0x2,    0x2,    0x57a,  0x5c8,  0x3,   0x2,   0x2,
        0x2,   0x57b, 0x57c,  0x7,    0x88,   0x2,    0x2,    0x57c,  0x57d,  0x7,   0x182, 0x2,
        0x2,   0x57d, 0x5c8,  0x5,    0xea,   0x76,   0x2,    0x57e,  0x57f,  0x7,   0x81,  0x2,
        0x2,   0x57f, 0x582,  0x7,    0x182,  0x2,    0x2,    0x580,  0x583,  0x5,   0xea,  0x76,
        0x2,   0x581, 0x583,  0x7,    0xb,    0x2,    0x2,    0x582,  0x580,  0x3,   0x2,   0x2,
        0x2,   0x582, 0x581,  0x3,    0x2,    0x2,    0x2,    0x583,  0x584,  0x3,   0x2,   0x2,
        0x2,   0x584, 0x5c8,  0x7,    0x226,  0x2,    0x2,    0x585,  0x586,  0x7,   0xdc,  0x2,
        0x2,   0x586, 0x589,  0x7,    0x182,  0x2,    0x2,    0x587,  0x58a,  0x5,   0xea,  0x76,
        0x2,   0x588, 0x58a,  0x7,    0xb,    0x2,    0x2,    0x589,  0x587,  0x3,   0x2,   0x2,
        0x2,   0x589, 0x588,  0x3,    0x2,    0x2,    0x2,    0x58a,  0x58b,  0x3,   0x2,   0x2,
        0x2,   0x58b, 0x5c8,  0x7,    0x226,  0x2,    0x2,    0x58c,  0x58d,  0x7,   0x23c, 0x2,
        0x2,   0x58d, 0x590,  0x7,    0x182,  0x2,    0x2,    0x58e,  0x591,  0x5,   0xea,  0x76,
        0x2,   0x58f, 0x591,  0x7,    0xb,    0x2,    0x2,    0x590,  0x58e,  0x3,   0x2,   0x2,
        0x2,   0x590, 0x58f,  0x3,    0x2,    0x2,    0x2,    0x591,  0x5c8,  0x3,   0x2,   0x2,
        0x2,   0x592, 0x593,  0x7,    0x3e,   0x2,    0x2,    0x593,  0x594,  0x7,   0x182, 0x2,
        0x2,   0x594, 0x5c8,  0x5,    0x100,  0x81,   0x2,    0x595,  0x596,  0x7,   0x1b3, 0x2,
        0x2,   0x596, 0x597,  0x7,    0x182,  0x2,    0x2,    0x597,  0x598,  0x5,   0xea,  0x76,
        0x2,   0x598, 0x599,  0x7,    0xf2,   0x2,    0x2,    0x599,  0x59a,  0x5,   0x1e,  0x10,
        0x2,   0x59a, 0x5c8,  0x3,    0x2,    0x2,    0x2,    0x59b,  0x59c,  0x7,   0x9f,  0x2,
        0x2,   0x59c, 0x59d,  0x7,    0x182,  0x2,    0x2,    0x59d,  0x59e,  0x5,   0xd0,  0x69,
        0x2,   0x59e, 0x59f,  0x7,    0x268,  0x2,    0x2,    0x59f,  0x5a0,  0x7,   0x224, 0x2,
        0x2,   0x5a0, 0x5a3,  0x5,    0xc6,   0x64,   0x2,    0x5a1,  0x5a2,  0x9,   0x1b,  0x2,
        0x2,   0x5a2, 0x5a4,  0x7,    0x257,  0x2,    0x2,    0x5a3,  0x5a1,  0x3,   0x2,   0x2,
        0x2,   0x5a3, 0x5a4,  0x3,    0x2,    0x2,    0x2,    0x5a4,  0x5c8,  0x3,   0x2,   0x2,
        0x2,   0x5a5, 0x5a6,  0x7,    0xf,    0x2,    0x2,    0x5a6,  0x5a9,  0x7,   0x182, 0x2,
        0x2,   0x5a7, 0x5aa,  0x5,    0xea,   0x76,   0x2,    0x5a8,  0x5aa,  0x7,   0xb,   0x2,
        0x2,   0x5a9, 0x5a7,  0x3,    0x2,    0x2,    0x2,    0x5a9,  0x5a8,  0x3,   0x2,   0x2,
        0x2,   0x5aa, 0x5c8,  0x3,    0x2,    0x2,    0x2,    0x5ab,  0x5ac,  0x7,   0x38,  0x2,
        0x2,   0x5ac, 0x5af,  0x7,    0x182,  0x2,    0x2,    0x5ad,  0x5b0,  0x5,   0xea,  0x76,
        0x2,   0x5ae, 0x5b0,  0x7,    0xb,    0x2,    0x2,    0x5af,  0x5ad,  0x3,   0x2,   0x2,
        0x2,   0x5af, 0x5ae,  0x3,    0x2,    0x2,    0x2,    0x5b0,  0x5c8,  0x3,   0x2,   0x2,
        0x2,   0x5b1, 0x5b2,  0x7,    0x172,  0x2,    0x2,    0x5b2,  0x5b5,  0x7,   0x182, 0x2,
        0x2,   0x5b3, 0x5b6,  0x5,    0xea,   0x76,   0x2,    0x5b4,  0x5b6,  0x7,   0xb,   0x2,
        0x2,   0x5b5, 0x5b3,  0x3,    0x2,    0x2,    0x2,    0x5b5,  0x5b4,  0x3,   0x2,   0x2,
        0x2,   0x5b6, 0x5c8,  0x3,    0x2,    0x2,    0x2,    0x5b7,  0x5b8,  0x7,   0x1a3, 0x2,
        0x2,   0x5b8, 0x5bb,  0x7,    0x182,  0x2,    0x2,    0x5b9,  0x5bc,  0x5,   0xea,  0x76,
        0x2,   0x5ba, 0x5bc,  0x7,    0xb,    0x2,    0x2,    0x5bb,  0x5b9,  0x3,   0x2,   0x2,
        0x2,   0x5bb, 0x5ba,  0x3,    0x2,    0x2,    0x2,    0x5bc,  0x5c8,  0x3,   0x2,   0x2,
        0x2,   0x5bd, 0x5be,  0x7,    0x1b4,  0x2,    0x2,    0x5be,  0x5c1,  0x7,   0x182, 0x2,
        0x2,   0x5bf, 0x5c2,  0x5,    0xea,   0x76,   0x2,    0x5c0,  0x5c2,  0x7,   0xb,   0x2,
        0x2,   0x5c1, 0x5bf,  0x3,    0x2,    0x2,    0x2,    0x5c1,  0x5c0,  0x3,   0x2,   0x2,
        0x2,   0x5c2, 0x5c8,  0x3,    0x2,    0x2,    0x2,    0x5c3,  0x5c4,  0x7,   0x1b1, 0x2,
        0x2,   0x5c4, 0x5c8,  0x7,    0x183,  0x2,    0x2,    0x5c5,  0x5c6,  0x7,   0x24d, 0x2,
        0x2,   0x5c6, 0x5c8,  0x7,    0x183,  0x2,    0x2,    0x5c7,  0x506,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x507,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x510,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x515,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x517,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x51c,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x528,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x532,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x537,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x540,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x545,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x548,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x54b,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x54f,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x551,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x553,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x558,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x55e,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x561,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x568,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x56e,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x570,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x572,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x573,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x575,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x57b,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x57e,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x585,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x58c,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x592,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x595,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x59b,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x5a5,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x5ab,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x5b1,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x5b7,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x5bd,  0x3,   0x2,   0x2,
        0x2,   0x5c7, 0x5c3,  0x3,    0x2,    0x2,    0x2,    0x5c7,  0x5c5,  0x3,   0x2,   0x2,
        0x2,   0x5c8, 0xe5,   0x3,    0x2,    0x2,    0x2,    0x5c9,  0x5ce,  0x5,   0xe4,  0x73,
        0x2,   0x5ca, 0x5cb,  0x7,    0x282,  0x2,    0x2,    0x5cb,  0x5cd,  0x5,   0xe4,  0x73,
        0x2,   0x5cc, 0x5ca,  0x3,    0x2,    0x2,    0x2,    0x5cd,  0x5d0,  0x3,   0x2,   0x2,
        0x2,   0x5ce, 0x5cc,  0x3,    0x2,    0x2,    0x2,    0x5ce,  0x5cf,  0x3,   0x2,   0x2,
        0x2,   0x5cf, 0xe7,   0x3,    0x2,    0x2,    0x2,    0x5d0,  0x5ce,  0x3,   0x2,   0x2,
        0x2,   0x5d1, 0x5d6,  0x5,    0xc0,   0x61,   0x2,    0x5d2,  0x5d3,  0x7,   0x282, 0x2,
        0x2,   0x5d3, 0x5d5,  0x5,    0xc0,   0x61,   0x2,    0x5d4,  0x5d2,  0x3,   0x2,   0x2,
        0x2,   0x5d5, 0x5d8,  0x3,    0x2,    0x2,    0x2,    0x5d6,  0x5d4,  0x3,   0x2,   0x2,
        0x2,   0x5d6, 0x5d7,  0x3,    0x2,    0x2,    0x2,    0x5d7,  0xe9,   0x3,   0x2,   0x2,
        0x2,   0x5d8, 0x5d6,  0x3,    0x2,    0x2,    0x2,    0x5d9,  0x5de,  0x5,   0xd0,  0x69,
        0x2,   0x5da, 0x5db,  0x7,    0x282,  0x2,    0x2,    0x5db,  0x5dd,  0x5,   0xd0,  0x69,
        0x2,   0x5dc, 0x5da,  0x3,    0x2,    0x2,    0x2,    0x5dd,  0x5e0,  0x3,   0x2,   0x2,
        0x2,   0x5de, 0x5dc,  0x3,    0x2,    0x2,    0x2,    0x5de,  0x5df,  0x3,   0x2,   0x2,
        0x2,   0x5df, 0xeb,   0x3,    0x2,    0x2,    0x2,    0x5e0,  0x5de,  0x3,   0x2,   0x2,
        0x2,   0x5e1, 0x5e2,  0x7,    0x27f,  0x2,    0x2,    0x5e2,  0x5e3,  0x5,   0xc0,  0x61,
        0x2,   0x5e3, 0x5ea,  0x5,    0x12,   0xa,    0x2,    0x5e4,  0x5e5,  0x7,   0x282, 0x2,
        0x2,   0x5e5, 0x5e6,  0x5,    0xc0,   0x61,   0x2,    0x5e6,  0x5e7,  0x5,   0x12,  0xa,
        0x2,   0x5e7, 0x5e9,  0x3,    0x2,    0x2,    0x2,    0x5e8,  0x5e4,  0x3,   0x2,   0x2,
        0x2,   0x5e9, 0x5ec,  0x3,    0x2,    0x2,    0x2,    0x5ea,  0x5e8,  0x3,   0x2,   0x2,
        0x2,   0x5ea, 0x5eb,  0x3,    0x2,    0x2,    0x2,    0x5eb,  0x5ed,  0x3,   0x2,   0x2,
        0x2,   0x5ec, 0x5ea,  0x3,    0x2,    0x2,    0x2,    0x5ed,  0x5ee,  0x7,   0x280, 0x2,
        0x2,   0x5ee, 0xed,   0x3,    0x2,    0x2,    0x2,    0x5ef,  0x5f0,  0x9,   0x1c,  0x2,
        0x2,   0x5f0, 0xef,   0x3,    0x2,    0x2,    0x2,    0x5f1,  0x5f2,  0x9,   0x1d,  0x2,
        0x2,   0x5f2, 0xf1,   0x3,    0x2,    0x2,    0x2,    0x5f3,  0x5f7,  0x7,   0xb2,  0x2,
        0x2,   0x5f4, 0x5f5,  0x7,    0x7,    0x2,    0x2,    0x5f5,  0x5f7,  0x5,   0xc0,  0x61,
        0x2,   0x5f6, 0x5f3,  0x3,    0x2,    0x2,    0x2,    0x5f6,  0x5f4,  0x3,   0x2,   0x2,
        0x2,   0x5f7, 0xf3,   0x3,    0x2,    0x2,    0x2,    0x5f8,  0x5f9,  0x5,   0xba,  0x5e,
        0x2,   0x5f9, 0xf5,   0x3,    0x2,    0x2,    0x2,    0x5fa,  0x5fb,  0x5,   0xc6,  0x64,
        0x2,   0x5fb, 0xf7,   0x3,    0x2,    0x2,    0x2,    0x5fc,  0x5fd,  0x5,   0xc0,  0x61,
        0x2,   0x5fd, 0xf9,   0x3,    0x2,    0x2,    0x2,    0x5fe,  0x5ff,  0x5,   0xc0,  0x61,
        0x2,   0x5ff, 0xfb,   0x3,    0x2,    0x2,    0x2,    0x600,  0x601,  0x5,   0xc2,  0x62,
        0x2,   0x601, 0xfd,   0x3,    0x2,    0x2,    0x2,    0x602,  0x603,  0x5,   0xc2,  0x62,
        0x2,   0x603, 0xff,   0x3,    0x2,    0x2,    0x2,    0x604,  0x605,  0x5,   0xdc,  0x6f,
        0x2,   0x605, 0x101,  0x3,    0x2,    0x2,    0x2,    0xcf,   0x107,  0x110, 0x119, 0x11e,
        0x122, 0x129, 0x12e,  0x134,  0x139,  0x13c,  0x140,  0x146,  0x150,  0x154, 0x15a, 0x15e,
        0x161, 0x164, 0x167,  0x16a,  0x16e,  0x176,  0x179,  0x17e,  0x185,  0x188, 0x18e, 0x192,
        0x195, 0x198, 0x19f,  0x1a2,  0x1a8,  0x1ad,  0x1b2,  0x1b7,  0x1bc,  0x1c1, 0x1c5, 0x1c8,
        0x1cc, 0x1cf, 0x1d2,  0x1d6,  0x1da,  0x1de,  0x1e3,  0x1e7,  0x1ec,  0x1f0, 0x1f2, 0x1f6,
        0x1fb, 0x1fe, 0x201,  0x208,  0x20b,  0x20e,  0x215,  0x219,  0x21c,  0x21f, 0x226, 0x22d,
        0x230, 0x233, 0x236,  0x23d,  0x245,  0x248,  0x24b,  0x24e,  0x253,  0x256, 0x25a, 0x25e,
        0x263, 0x268, 0x26c,  0x271,  0x275,  0x27a,  0x27f,  0x284,  0x28a,  0x28f, 0x294, 0x29a,
        0x29f, 0x2a4, 0x2a9,  0x2ae,  0x2b3,  0x2b8,  0x2bd,  0x2c2,  0x2c7,  0x2cc, 0x2d3, 0x2d6,
        0x2dd, 0x2e4, 0x2e6,  0x2e9,  0x2f1,  0x2f7,  0x2fc,  0x302,  0x309,  0x30f, 0x311, 0x314,
        0x319, 0x31f, 0x322,  0x327,  0x32b,  0x333,  0x33e,  0x342,  0x349,  0x34d, 0x350, 0x354,
        0x357, 0x35c, 0x35f,  0x364,  0x367,  0x36b,  0x36e,  0x372,  0x375,  0x379, 0x37c, 0x380,
        0x38a, 0x38f, 0x393,  0x398,  0x39d,  0x3a5,  0x3ac,  0x3b1,  0x3b7,  0x3c0, 0x3cb, 0x3d6,
        0x3e1, 0x3ec, 0x3f7,  0x402,  0x40d,  0x418,  0x41f,  0x424,  0x427,  0x42d, 0x438, 0x43b,
        0x442, 0x445, 0x469,  0x46f,  0x473,  0x47f,  0x487,  0x492,  0x497,  0x4d6, 0x4ec, 0x4fc,
        0x501, 0x504, 0x509,  0x50e,  0x512,  0x519,  0x51e,  0x526,  0x52a,  0x530, 0x534, 0x539,
        0x53e, 0x542, 0x555,  0x565,  0x568,  0x56c,  0x582,  0x589,  0x590,  0x5a3, 0x5a9, 0x5af,
        0x5b5, 0x5bb, 0x5c1,  0x5c7,  0x5ce,  0x5d6,  0x5de,  0x5ea,  0x5f6,
    };

    atn::ATNDeserializer deserializer;
    _atn = deserializer.deserialize(_serializedATN);

    size_t count = _atn.getNumberOfDecisions();
    _decisionToDFA.reserve(count);
    for (size_t i = 0; i < count; i++)
    {
        _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
    }
}

mysqlParser::Initializer mysqlParser::_init;
