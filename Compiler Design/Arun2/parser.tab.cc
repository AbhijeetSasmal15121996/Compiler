// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 11 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  
  extern int node_id;
  

#line 56 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 128 "parser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 42: // program
      case 43: // mainClass
      case 44: // extends
      case 45: // classDeclarationList
      case 46: // classDeclaration
      case 47: // varDeclarationList
      case 48: // varDeclaration
      case 49: // methodDeclarationList
      case 50: // methodDeclaration
      case 51: // parameterList
      case 52: // type
      case 53: // statementList
      case 54: // statement
      case 55: // expressionList
      case 56: // expression
      case 57: // identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case 3: // IDENTIFIER
      case 4: // LBRACKET
      case 5: // AND
      case 6: // RBRACKET
      case 7: // LSS
      case 8: // TIMES
      case 9: // INTEGER_LITERAL
      case 10: // PLUS
      case 11: // MINUS
      case 12: // PERIOD
      case 13: // LENGTH
      case 14: // TRUE
      case 15: // FALSE
      case 16: // THIS
      case 17: // NEW
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // LPAREN
      case 21: // RPAREN
      case 22: // EXCLAMATION
      case 23: // COMMA
      case 24: // LBRACE
      case 25: // RBRACE
      case 26: // IF
      case 27: // ELSE
      case 28: // WHILE
      case 29: // PRINTLN
      case 30: // SEMICOLON
      case 31: // EQUAL
      case 32: // RETURN
      case 33: // PUBLIC
      case 34: // CLASS
      case 35: // EXTENDS
      case 36: // STATIC
      case 37: // VOID
      case 38: // MAIN
      case 39: // STRING
      case 40: // WORDSTRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 42: // program
      case 43: // mainClass
      case 44: // extends
      case 45: // classDeclarationList
      case 46: // classDeclaration
      case 47: // varDeclarationList
      case 48: // varDeclaration
      case 49: // methodDeclarationList
      case 50: // methodDeclaration
      case 51: // parameterList
      case 52: // type
      case 53: // statementList
      case 54: // statement
      case 55: // expressionList
      case 56: // expression
      case 57: // identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case 3: // IDENTIFIER
      case 4: // LBRACKET
      case 5: // AND
      case 6: // RBRACKET
      case 7: // LSS
      case 8: // TIMES
      case 9: // INTEGER_LITERAL
      case 10: // PLUS
      case 11: // MINUS
      case 12: // PERIOD
      case 13: // LENGTH
      case 14: // TRUE
      case 15: // FALSE
      case 16: // THIS
      case 17: // NEW
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // LPAREN
      case 21: // RPAREN
      case 22: // EXCLAMATION
      case 23: // COMMA
      case 24: // LBRACE
      case 25: // RBRACE
      case 26: // IF
      case 27: // ELSE
      case 28: // WHILE
      case 29: // PRINTLN
      case 30: // SEMICOLON
      case 31: // EQUAL
      case 32: // RETURN
      case 33: // PUBLIC
      case 34: // CLASS
      case 35: // EXTENDS
      case 36: // STATIC
      case 37: // VOID
      case 38: // MAIN
      case 39: // STRING
      case 40: // WORDSTRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 42: // program
      case 43: // mainClass
      case 44: // extends
      case 45: // classDeclarationList
      case 46: // classDeclaration
      case 47: // varDeclarationList
      case 48: // varDeclaration
      case 49: // methodDeclarationList
      case 50: // methodDeclaration
      case 51: // parameterList
      case 52: // type
      case 53: // statementList
      case 54: // statement
      case 55: // expressionList
      case 56: // expression
      case 57: // identifier
        value.copy< Node * > (that.value);
        break;

      case 3: // IDENTIFIER
      case 4: // LBRACKET
      case 5: // AND
      case 6: // RBRACKET
      case 7: // LSS
      case 8: // TIMES
      case 9: // INTEGER_LITERAL
      case 10: // PLUS
      case 11: // MINUS
      case 12: // PERIOD
      case 13: // LENGTH
      case 14: // TRUE
      case 15: // FALSE
      case 16: // THIS
      case 17: // NEW
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // LPAREN
      case 21: // RPAREN
      case 22: // EXCLAMATION
      case 23: // COMMA
      case 24: // LBRACE
      case 25: // RBRACE
      case 26: // IF
      case 27: // ELSE
      case 28: // WHILE
      case 29: // PRINTLN
      case 30: // SEMICOLON
      case 31: // EQUAL
      case 32: // RETURN
      case 33: // PUBLIC
      case 34: // CLASS
      case 35: // EXTENDS
      case 36: // STATIC
      case 37: // VOID
      case 38: // MAIN
      case 39: // STRING
      case 40: // WORDSTRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 42: // program
      case 43: // mainClass
      case 44: // extends
      case 45: // classDeclarationList
      case 46: // classDeclaration
      case 47: // varDeclarationList
      case 48: // varDeclaration
      case 49: // methodDeclarationList
      case 50: // methodDeclaration
      case 51: // parameterList
      case 52: // type
      case 53: // statementList
      case 54: // statement
      case 55: // expressionList
      case 56: // expression
      case 57: // identifier
        value.move< Node * > (that.value);
        break;

      case 3: // IDENTIFIER
      case 4: // LBRACKET
      case 5: // AND
      case 6: // RBRACKET
      case 7: // LSS
      case 8: // TIMES
      case 9: // INTEGER_LITERAL
      case 10: // PLUS
      case 11: // MINUS
      case 12: // PERIOD
      case 13: // LENGTH
      case 14: // TRUE
      case 15: // FALSE
      case 16: // THIS
      case 17: // NEW
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // LPAREN
      case 21: // RPAREN
      case 22: // EXCLAMATION
      case 23: // COMMA
      case 24: // LBRACE
      case 25: // RBRACE
      case 26: // IF
      case 27: // ELSE
      case 28: // WHILE
      case 29: // PRINTLN
      case 30: // SEMICOLON
      case 31: // EQUAL
      case 32: // RETURN
      case 33: // PUBLIC
      case 34: // CLASS
      case 35: // EXTENDS
      case 36: // STATIC
      case 37: // VOID
      case 38: // MAIN
      case 39: // STRING
      case 40: // WORDSTRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 42: // program
      case 43: // mainClass
      case 44: // extends
      case 45: // classDeclarationList
      case 46: // classDeclaration
      case 47: // varDeclarationList
      case 48: // varDeclaration
      case 49: // methodDeclarationList
      case 50: // methodDeclaration
      case 51: // parameterList
      case 52: // type
      case 53: // statementList
      case 54: // statement
      case 55: // expressionList
      case 56: // expression
      case 57: // identifier
        yylhs.value.emplace< Node * > ();
        break;

      case 3: // IDENTIFIER
      case 4: // LBRACKET
      case 5: // AND
      case 6: // RBRACKET
      case 7: // LSS
      case 8: // TIMES
      case 9: // INTEGER_LITERAL
      case 10: // PLUS
      case 11: // MINUS
      case 12: // PERIOD
      case 13: // LENGTH
      case 14: // TRUE
      case 15: // FALSE
      case 16: // THIS
      case 17: // NEW
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // LPAREN
      case 21: // RPAREN
      case 22: // EXCLAMATION
      case 23: // COMMA
      case 24: // LBRACE
      case 25: // RBRACE
      case 26: // IF
      case 27: // ELSE
      case 28: // WHILE
      case 29: // PRINTLN
      case 30: // SEMICOLON
      case 31: // EQUAL
      case 32: // RETURN
      case 33: // PUBLIC
      case 34: // CLASS
      case 35: // EXTENDS
      case 36: // STATIC
      case 37: // VOID
      case 38: // MAIN
      case 39: // STRING
      case 40: // WORDSTRING
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 37 "parser.yy"
                   { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R1 ");}
#line 842 "parser.tab.cc"
    break;

  case 3:
#line 38 "parser.yy"
                                        {
                        printf("R2 Rules \n");
                        yylhs.value.as < Node * > () = new Node("Program", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        root = yylhs.value.as < Node * > ();
                      }
#line 854 "parser.tab.cc"
    break;

  case 4:
#line 47 "parser.yy"
                                                                                                                                               {
                        printf("R3 ");
                        yylhs.value.as < Node * > () = new Node("MainClass", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "PUBLIC"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "STATIC"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "VOID"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "MAIN"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "(")); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "String"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "["));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "]"));       
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));  
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}")); 
                      }
#line 880 "parser.tab.cc"
    break;

  case 5:
#line 70 "parser.yy"
         {}
#line 886 "parser.tab.cc"
    break;

  case 6:
#line 71 "parser.yy"
                             { 
                        printf("R4 ");
                        yylhs.value.as < Node * > () = new Node("Extends", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "EXTENDS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 897 "parser.tab.cc"
    break;

  case 7:
#line 80 "parser.yy"
                                       { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R5 ");}
#line 903 "parser.tab.cc"
    break;

  case 8:
#line 81 "parser.yy"
                                                {
                        printf("R6 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclarationList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 914 "parser.tab.cc"
    break;

  case 9:
#line 89 "parser.yy"
                                                                                                 {
                        printf("R7 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 930 "parser.tab.cc"
    break;

  case 10:
#line 100 "parser.yy"
                                                                              {
                        printf("R8 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        if(yystack_[3].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 945 "parser.tab.cc"
    break;

  case 11:
#line 110 "parser.yy"
                                                                            {
                        printf("R9 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        if(yystack_[3].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 960 "parser.tab.cc"
    break;

  case 12:
#line 120 "parser.yy"
                                                        {
                        printf("R10 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 974 "parser.tab.cc"
    break;

  case 13:
#line 131 "parser.yy"
                                   { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R11 ");}
#line 980 "parser.tab.cc"
    break;

  case 14:
#line 132 "parser.yy"
                                            {
                        printf("R12 ");
                        yylhs.value.as < Node * > () = new Node("VarDeclarationList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 991 "parser.tab.cc"
    break;

  case 15:
#line 140 "parser.yy"
                                           {
                        printf("R13 ");
                        yylhs.value.as < Node * > () = new Node("VarDeclaration", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";")); 
                      }
#line 1003 "parser.tab.cc"
    break;

  case 16:
#line 149 "parser.yy"
                                         { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R14 ");}
#line 1009 "parser.tab.cc"
    break;

  case 17:
#line 150 "parser.yy"
                                                  { 
                        printf("R15 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclarationList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1020 "parser.tab.cc"
    break;

  case 18:
#line 159 "parser.yy"
                                                                                                                                                {
                        printf("R16 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "public")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[11].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        if(yystack_[8].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        if(yystack_[5].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "return"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 1042 "parser.tab.cc"
    break;

  case 19:
#line 176 "parser.yy"
                                                                                                                              {
                        printf("R17 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "public")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        if(yystack_[7].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "return"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 1063 "parser.tab.cc"
    break;

  case 20:
#line 192 "parser.yy"
                                                                                                                                    {
                        printf("R17 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "public")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        if(yystack_[7].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "return"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 1084 "parser.tab.cc"
    break;

  case 21:
#line 208 "parser.yy"
                                                                                                                {
                        printf("R18 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "public")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        if(yystack_[6].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "return"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 1104 "parser.tab.cc"
    break;

  case 22:
#line 225 "parser.yy"
               {}
#line 1110 "parser.tab.cc"
    break;

  case 23:
#line 226 "parser.yy"
                         {
                          printf("R19 ");
                          yylhs.value.as < Node * > () = new Node("ParameterList", ""); 
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1121 "parser.tab.cc"
    break;

  case 24:
#line 232 "parser.yy"
                                              {
                          printf("R20 ");
                          yylhs.value.as < Node * > () = new Node("ParameterList", ""); 
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(new Node("COMMA", ","));
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1134 "parser.tab.cc"
    break;

  case 25:
#line 242 "parser.yy"
                  { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R21 ");}
#line 1140 "parser.tab.cc"
    break;

  case 26:
#line 243 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("TYPE", yystack_[0].value.as < std::string > ()); printf("R22 ");}
#line 1146 "parser.tab.cc"
    break;

  case 27:
#line 244 "parser.yy"
                  { yylhs.value.as < Node * > () = new Node("TYPE", yystack_[0].value.as < std::string > ()); printf("R23 ");}
#line 1152 "parser.tab.cc"
    break;

  case 28:
#line 245 "parser.yy"
                                {
                        printf("R24 ");
                        yylhs.value.as < Node * > () = new Node("TypeVector", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("Type", "INT"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "["));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "]"));
                      }
#line 1164 "parser.tab.cc"
    break;

  case 29:
#line 253 "parser.yy"
                          { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R25 ");}
#line 1170 "parser.tab.cc"
    break;

  case 30:
#line 254 "parser.yy"
                                 {
                        printf("R26 ");
                        yylhs.value.as < Node * > () = new Node("StatementList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1181 "parser.tab.cc"
    break;

  case 31:
#line 262 "parser.yy"
                                       {
                        printf("R27 ");
                        yylhs.value.as < Node * > () = new Node("Statement", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACE", "{"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACE", "}"));
                      }
#line 1193 "parser.tab.cc"
    break;

  case 32:
#line 269 "parser.yy"
                                                              {
                        printf("R28 ");
                        yylhs.value.as < Node * > () = new Node("IFStatement", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("IF", "if"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("ELSE", "else"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1209 "parser.tab.cc"
    break;

  case 33:
#line 280 "parser.yy"
                                                  {
                        printf("R29 ");
                        yylhs.value.as < Node * > () = new Node("WHILEStatement", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("WHILE", "while"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1223 "parser.tab.cc"
    break;

  case 34:
#line 289 "parser.yy"
                                                     {
                        printf("R30 ");
                        yylhs.value.as < Node * > () = new Node("PrintStatement", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PRINT", "System.out.println"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                      }
#line 1237 "parser.tab.cc"
    break;

  case 35:
#line 298 "parser.yy"
                                               {
                        printf("R31 ");
                        yylhs.value.as < Node * > () = new Node("AssignmentStatement", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("EQUAL", "="));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                      }
#line 1250 "parser.tab.cc"
    break;

  case 36:
#line 306 "parser.yy"
                                                                             {
                        printf("R32 ");
                        yylhs.value.as < Node * > () = new Node("VectorAssignmentStatement", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ()); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "["));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "]"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("EQUAL", "="));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                      }
#line 1266 "parser.tab.cc"
    break;

  case 37:
#line 319 "parser.yy"
                           { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R33 ");}
#line 1272 "parser.tab.cc"
    break;

  case 38:
#line 320 "parser.yy"
                                                {
                        printf("R34 ");
                        yylhs.value.as < Node * > () = new Node("ExpressionList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("COMMA", ","));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1284 "parser.tab.cc"
    break;

  case 39:
#line 329 "parser.yy"
                       { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R35 ");}
#line 1290 "parser.tab.cc"
    break;

  case 40:
#line 330 "parser.yy"
                          { yylhs.value.as < Node * > () = new Node("INTEGER", yystack_[0].value.as < std::string > ()); printf("R36 ");}
#line 1296 "parser.tab.cc"
    break;

  case 41:
#line 331 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("LITERAL", yystack_[0].value.as < std::string > ()); printf("R37 ");}
#line 1302 "parser.tab.cc"
    break;

  case 42:
#line 332 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("LITERAL", yystack_[0].value.as < std::string > ()); printf("R38 ");}
#line 1308 "parser.tab.cc"
    break;

  case 43:
#line 333 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("", yystack_[0].value.as < std::string > ()); printf("R39 ");}
#line 1314 "parser.tab.cc"
    break;

  case 44:
#line 334 "parser.yy"
                                                {
                        printf("R40 ");
                        yylhs.value.as < Node * > () = new Node("lssExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LSS", "<"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      
                      }
#line 1327 "parser.tab.cc"
    break;

  case 45:
#line 342 "parser.yy"
                                                {
                        printf("R41 ");
                        yylhs.value.as < Node * > () = new Node("AndExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("AND", "&&"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                     
                      }
#line 1340 "parser.tab.cc"
    break;

  case 46:
#line 350 "parser.yy"
                                                  {
                        printf("R42 ");
                        yylhs.value.as < Node * > () = new Node("MultExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("TIMES", "*"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        
                      }
#line 1353 "parser.tab.cc"
    break;

  case 47:
#line 358 "parser.yy"
                                                 {
                        printf("R43 ");
                        yylhs.value.as < Node * > () = new Node("PlusExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PLUS", "+"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        
                      }
#line 1366 "parser.tab.cc"
    break;

  case 48:
#line 366 "parser.yy"
                                                  {
                        printf("R44 ");
                        yylhs.value.as < Node * > () = new Node("MinusExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("MINUS", "-"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        
                      }
#line 1379 "parser.tab.cc"
    break;

  case 49:
#line 374 "parser.yy"
                                                 {
                        printf("R45 ");
                        yylhs.value.as < Node * > () = new Node("VectorAccessExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "["));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "]"));
                      }
#line 1392 "parser.tab.cc"
    break;

  case 50:
#line 382 "parser.yy"
                                                  {
                        printf("R46 ");
                        yylhs.value.as < Node * > () = new Node("LengthExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PERIOD", "."));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LENGTH", "length"));
                      }
#line 1404 "parser.tab.cc"
    break;

  case 51:
#line 389 "parser.yy"
                                                                  {
                        printf("R47 ");
                        yylhs.value.as < Node * > () = new Node("NewVectorExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("NEW", "new"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("INT", "int")); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "["));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "]")); 
                      }
#line 1418 "parser.tab.cc"
    break;

  case 52:
#line 398 "parser.yy"
                                                 {
                        printf("R48 ");
                        yylhs.value.as < Node * > () = new Node("NewClassExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("NEW", "new"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "(")); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                      }
#line 1431 "parser.tab.cc"
    break;

  case 53:
#line 406 "parser.yy"
                                                 {
                        printf("R49 ");
                        yylhs.value.as < Node * > () = new Node("ExclamationExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("EXCLAMATION", "!"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1442 "parser.tab.cc"
    break;

  case 54:
#line 412 "parser.yy"
                                                  {
                        printf("R50 ");
                        yylhs.value.as < Node * > () = new Node("ParenExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                      }
#line 1454 "parser.tab.cc"
    break;

  case 55:
#line 419 "parser.yy"
                                                                   {
                        printf("R51 ");
                        yylhs.value.as < Node * > () = new Node("MethodCallExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PERIOD", "."));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                      }
#line 1469 "parser.tab.cc"
    break;

  case 56:
#line 429 "parser.yy"
                                                    {
                        printf("R52 ");
                        yylhs.value.as < Node * > () = new Node("MethodCallExpressionWithoutArgs", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PERIOD", "."));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LPAREN", "("));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RPAREN", ")"));
                      }
#line 1483 "parser.tab.cc"
    break;

  case 57:
#line 440 "parser.yy"
                       {  yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > ()); printf("R53 %s ",yystack_[0].value.as < std::string > ().c_str());}
#line 1489 "parser.tab.cc"
    break;


#line 1493 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -49;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -25,    37,     2,   -49,   -49,   -14,   -49,    37,     3,   -49,
      24,    16,   -49,   -49,    33,    37,    48,    43,   -49,     8,
      45,    77,   -49,   -49,    52,    40,   -49,   -20,   -49,    37,
     -49,    70,    97,    37,   -49,   -49,    27,   -49,   -49,    82,
      76,   -49,    99,   -49,   -49,   113,    52,   117,   105,    37,
      37,   106,   108,   111,    96,    52,   112,   190,   109,   118,
     120,   221,   115,    18,   -49,     0,   -49,   190,    72,     0,
     221,   221,   221,   -49,   -49,   -49,   -49,     4,   221,   221,
     150,   -49,   221,   124,   221,   -49,   221,   221,   110,   -49,
     249,   261,   273,   133,   125,   285,   139,   221,   221,   221,
     221,   221,   221,    71,   126,   159,   221,   171,   297,   180,
     134,   190,   190,   135,   221,   147,   -49,   306,   321,   165,
       5,    80,    80,   -49,   153,   -49,   149,   192,   152,   155,
     -49,   -49,   167,   -49,   -49,   315,   -49,   -49,   212,   -49,
     170,   -49,   221,   190,   -49,   -49,   177,   240,   -49,   201,
     -49,   -49,   221,   -49,   -49
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,    57,     0,     1,     0,     0,     7,
       0,     5,     3,     8,     0,     0,     0,     0,     6,     0,
       0,    26,    27,    12,     0,     0,    13,     0,    16,     0,
      25,     0,     0,     0,    11,    14,     0,    10,    17,     0,
       0,    28,     0,     9,    15,     0,    22,     0,     0,     0,
       0,     0,    23,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    25,    24,     0,     0,     0,
       0,     0,     0,    40,    41,    42,    43,     0,     0,     0,
       0,    39,     0,     0,     0,    30,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,    45,    44,
      46,    47,    48,    50,     0,    21,     0,     0,     0,     0,
      35,     4,     0,    33,    34,     0,    52,    49,     0,    20,
       0,    19,     0,     0,    51,    56,     0,    37,    18,     0,
      32,    55,     0,    36,    38
  };

  const short
  parser::yypgoto_[] =
  {
     -49,   -49,   -49,   -49,   -49,   199,   163,   -24,   195,   -11,
     168,   -16,   -28,   -48,    73,     7,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    16,     8,     9,    25,    26,    27,    28,
      48,    29,    63,    64,   146,   147,    81
  };

  const short
  parser::yytable_[] =
  {
       5,    35,     6,    12,    86,    37,    11,     4,    33,     1,
      10,     4,    99,    24,    18,    85,    38,   103,    30,    88,
      85,     4,    93,    30,    30,    38,    21,    22,    39,    68,
      49,    87,    42,    23,    83,    85,     7,     7,    35,    49,
       4,    24,    57,     4,    58,    30,    59,    60,    52,    53,
      84,    15,    43,    65,    30,     4,    69,    14,    21,    22,
      24,    65,    69,   132,   133,    34,    69,    69,    80,    17,
      21,    22,    19,    24,     4,     4,    94,    90,    91,    92,
      20,    32,    69,    31,   123,    95,    96,    99,   100,   105,
      40,   107,   103,   108,   109,   150,    57,    89,    58,     4,
      59,    60,   124,    41,   117,   118,   119,   120,   121,   122,
      69,    69,    44,   127,    21,    22,    45,    47,     4,    46,
      57,   135,    58,    50,    59,    60,    51,     4,    61,    70,
      54,    55,    56,    21,    22,   110,    67,   114,    71,    57,
      72,    58,    69,    59,    60,   115,    99,    82,    57,   149,
      58,   125,    59,    60,    97,    98,   106,    99,   100,   131,
     101,   102,   103,    97,    98,   134,    99,   100,   136,   101,
     102,   103,    -1,   138,   139,    97,    98,   141,    99,   100,
     104,   101,   102,   103,    97,    98,   142,    99,   100,   126,
     101,   102,   103,     4,   143,   148,    97,    98,   151,    99,
     100,   128,   101,   102,   103,    97,    98,    13,    99,   100,
     130,   101,   102,   103,    57,     4,    58,    62,    59,    60,
      36,    73,   140,    66,     4,   154,    74,    75,    76,    77,
      73,   153,    78,   145,    79,    74,    75,    76,    77,     0,
       0,    78,     0,    79,    97,    98,     0,    99,   100,     0,
     101,   102,   103,    97,    98,     0,    99,   100,     0,   101,
     102,   103,     0,   152,     0,    97,    98,     0,    99,   100,
     111,   101,   102,   103,     0,     0,     0,    97,    98,     0,
      99,   100,   112,   101,   102,   103,     0,     0,     0,    97,
      98,     0,    99,   100,   113,   101,   102,   103,     0,     0,
       0,    97,    98,   129,    99,   100,   116,   101,   102,   103,
      97,    98,   137,    99,   100,     0,   101,   102,   103,    97,
      98,   144,    99,   100,     0,   101,   102,   103,    99,   100,
       0,   101,   102,   103
  };

  const short
  parser::yycheck_[] =
  {
       1,    25,     0,     0,     4,    25,     7,     3,    24,    34,
      24,     3,     7,    33,    15,    63,    27,    12,    19,    67,
      68,     3,    18,    24,    25,    36,    18,    19,    29,    57,
      46,    31,    33,    25,    62,    83,    34,    34,    62,    55,
       3,    33,    24,     3,    26,    46,    28,    29,    49,    50,
      32,    35,    25,    54,    55,     3,    57,    33,    18,    19,
      33,    62,    63,   111,   112,    25,    67,    68,    61,    36,
      18,    19,    24,    33,     3,     3,    77,    70,    71,    72,
      37,     4,    83,    38,    13,    78,    79,     7,     8,    82,
      20,    84,    12,    86,    87,   143,    24,    25,    26,     3,
      28,    29,   103,     6,    97,    98,    99,   100,   101,   102,
     111,   112,    30,   106,    18,    19,    40,     4,     3,    20,
      24,   114,    26,     6,    28,    29,    21,     3,    32,    20,
      24,    23,    21,    18,    19,    25,    24,     4,    20,    24,
      20,    26,   143,    28,    29,    20,     7,    32,    24,   142,
      26,    25,    28,    29,     4,     5,    32,     7,     8,    25,
      10,    11,    12,     4,     5,    30,     7,     8,    21,    10,
      11,    12,     7,    20,    25,     4,     5,    25,     7,     8,
      30,    10,    11,    12,     4,     5,    31,     7,     8,    30,
      10,    11,    12,     3,    27,    25,     4,     5,    21,     7,
       8,    30,    10,    11,    12,     4,     5,     8,     7,     8,
      30,    10,    11,    12,    24,     3,    26,    54,    28,    29,
      25,     9,    30,    55,     3,   152,    14,    15,    16,    17,
       9,    30,    20,    21,    22,    14,    15,    16,    17,    -1,
      -1,    20,    -1,    22,     4,     5,    -1,     7,     8,    -1,
      10,    11,    12,     4,     5,    -1,     7,     8,    -1,    10,
      11,    12,    -1,    23,    -1,     4,     5,    -1,     7,     8,
      21,    10,    11,    12,    -1,    -1,    -1,     4,     5,    -1,
       7,     8,    21,    10,    11,    12,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,    21,    10,    11,    12,    -1,    -1,
      -1,     4,     5,     6,     7,     8,    21,    10,    11,    12,
       4,     5,     6,     7,     8,    -1,    10,    11,    12,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,     7,     8,
      -1,    10,    11,    12
  };

  const signed char
  parser::yystos_[] =
  {
       0,    34,    42,    43,     3,    57,     0,    34,    45,    46,
      24,    57,     0,    46,    33,    35,    44,    36,    57,    24,
      37,    18,    19,    25,    33,    47,    48,    49,    50,    52,
      57,    38,     4,    52,    25,    48,    49,    25,    50,    57,
      20,     6,    57,    25,    30,    40,    20,     4,    51,    52,
       6,    21,    57,    57,    24,    23,    21,    24,    26,    28,
      29,    32,    47,    53,    54,    57,    51,    24,    53,    57,
      20,    20,    20,     9,    14,    15,    16,    17,    20,    22,
      56,    57,    32,    53,    32,    54,     4,    31,    54,    25,
      56,    56,    56,    18,    57,    56,    56,     4,     5,     7,
       8,    10,    11,    12,    30,    56,    32,    56,    56,    56,
      25,    21,    21,    21,     4,    20,    21,    56,    56,    56,
      56,    56,    56,    13,    57,    25,    30,    56,    30,     6,
      30,    25,    54,    54,    30,    56,    21,     6,    20,    25,
      30,    25,    31,    27,     6,    21,    55,    56,    25,    56,
      54,    21,    23,    30,    55
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    42,    43,    44,    44,    45,    45,    46,
      46,    46,    46,    47,    47,    48,    49,    49,    50,    50,
      50,    50,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,    17,     0,     2,     1,     2,     7,
       6,     6,     5,     1,     2,     3,     1,     2,    13,    12,
      12,    11,     0,     2,     4,     1,     1,     1,     3,     1,
       2,     3,     7,     5,     5,     4,     7,     1,     3,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     4,
       3,     5,     4,     2,     3,     6,     5,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IDENTIFIER", "LBRACKET",
  "AND", "RBRACKET", "LSS", "TIMES", "INTEGER_LITERAL", "PLUS", "MINUS",
  "PERIOD", "LENGTH", "TRUE", "FALSE", "THIS", "NEW", "INT", "BOOLEAN",
  "LPAREN", "RPAREN", "EXCLAMATION", "COMMA", "LBRACE", "RBRACE", "IF",
  "ELSE", "WHILE", "PRINTLN", "SEMICOLON", "EQUAL", "RETURN", "PUBLIC",
  "CLASS", "EXTENDS", "STATIC", "VOID", "MAIN", "STRING", "WORDSTRING",
  "$accept", "program", "mainClass", "extends", "classDeclarationList",
  "classDeclaration", "varDeclarationList", "varDeclaration",
  "methodDeclarationList", "methodDeclaration", "parameterList", "type",
  "statementList", "statement", "expressionList", "expression",
  "identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    37,    37,    38,    47,    70,    71,    80,    81,    89,
     100,   110,   120,   131,   132,   140,   149,   150,   159,   176,
     192,   208,   225,   226,   232,   242,   243,   244,   245,   253,
     254,   262,   269,   280,   289,   298,   306,   319,   320,   329,
     330,   331,   332,   333,   334,   342,   350,   358,   366,   374,
     382,   389,   398,   406,   412,   419,   429,   440
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2004 "parser.tab.cc"

