// MetaHub.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "MetaHub.h"
#include "Parser.h"

namespace MetaHub {

	METAHUB_API int parse(std::string str)
	{
		typedef lex::lexertl::token<
			char const*, boost::mpl::vector<std::string>
		> token_type;

		typedef lex::lexertl::lexer<token_type> lexer_type;

		typedef word_count_tokens<lexer_type>::iterator_type iterator_type;

		// now we use the types defined above to create the lexer and grammar
		// object instances needed to invoke the parsing process
		word_count_tokens<lexer_type> word_count;          // Our lexer
		word_count_grammar<iterator_type> g (word_count);  // Our parser 

		// read in the file int memory
		char const* first = str.c_str();
		char const* last = &first[str.size()];

		bool r = lex::tokenize_and_parse(first, last, word_count, g);

		if (r) {
			std::cout << "lines: " << g.l << ", words: " << g.w
				<< ", characters: " << g.c << "\n";
		}
		else {
			std::string rest(first, last);
			std::cerr << "Parsing failed\n" << "stopped at: \""
				<< rest << "\"\n";
		}
		return 42;
	}
}