#pragma once
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_statement.hpp>
#include <boost/spirit/include/phoenix_container.hpp>
#include <iostream>
#include <string>

using namespace boost::spirit;
using namespace boost::spirit::ascii;
enum tokenids 
{
    IDANY = lex::min_token_id + 10
};
template <typename Lexer>
struct word_count_tokens : lex::lexer<Lexer>
{
    word_count_tokens()
    {
        // define patterns (lexer macros) to be used during token definition 
        // below
        this->self.add_pattern
            ("class_def", "class")
            ("WORD", "[^ \t\n]+")

        ;

        // define tokens and associate them with the lexer
        word = "{WORD}";    // reference the pattern 'WORD' as defined above
        class_def = "{class_def}";    // reference the pattern 'WORD' as defined above

        // this lexer will recognize 3 token types: words, newlines, and 
        // everything else
        this->self.add
            (class_def)
            (word)          // no token id is needed here
            ('\n')          // characters are usable as tokens as well
            (".", IDANY)    // string literals will not be esacped by the library
        ;
    }

    // the token 'word' exposes the matched string as its parser attribute
    lex::token_def<std::string> word;
    lex::token_def<std::string> class_def;
};

template <typename Iterator>
struct word_count_grammar : qi::grammar<Iterator>
{
    template <typename TokenDef>
    word_count_grammar(TokenDef const& tok)
      : word_count_grammar::base_type(start)
      , c(0), w(0), l(0)
    {
        using boost::phoenix::ref;
        using boost::phoenix::size;

        start =  *(   tok.word          [++ref(w), ref(c) += size(_1)]
                  |   lit('\n')         [++ref(c), ++ref(l)]
                  |   qi::token(IDANY)  [++ref(c)]
                  )
              ;
    }

    std::size_t c, w, l;
    qi::rule<Iterator> start;
};

class Parser
{
public:
	Parser(void);
	~Parser(void);
};

