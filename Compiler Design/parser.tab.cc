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
      case 46: // program
      case 47: // mainClass
      case 48: // extends
      case 49: // classDeclarationList
      case 50: // classDeclaration
      case 51: // varDeclarationList
      case 52: // varDeclaration
      case 53: // methodDeclarationList
      case 54: // methodDeclaration
      case 55: // parameterList
      case 56: // type
      case 57: // statementList
      case 58: // statement
      case 59: // expressionList
      case 60: // expression
      case 61: // identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case 3: // IDENTIFIER
      case 4: // LSQUAREP
      case 5: // AND
      case 6: // RSQUAREP
      case 7: // LESSER
      case 8: // GREATER
      case 9: // OR
      case 10: // ASSIGNOP
      case 11: // MULTOP
      case 12: // DIVISIONOP
      case 13: // INT
      case 14: // PLUSOP
      case 15: // MINUSOP
      case 16: // PERIOD
      case 17: // LENGTH
      case 18: // TRUE
      case 19: // FALSE
      case 20: // THIS
      case 21: // NEW
      case 22: // INTEGER
      case 23: // BOOLEAN
      case 24: // LP
      case 25: // RP
      case 26: // NOT
      case 27: // COMMA
      case 28: // LBRACKET
      case 29: // RBRACKET
      case 30: // IF
      case 31: // ELSE
      case 32: // WHILE
      case 33: // PRINT
      case 34: // SEMICOLON
      case 35: // EQUALS
      case 36: // RETURN
      case 37: // PUBLIC
      case 38: // CLASS
      case 39: // EXTENDS
      case 40: // STATIC
      case 41: // VOID
      case 42: // MAIN
      case 43: // STRINGS
      case 44: // STRING
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
      case 46: // program
      case 47: // mainClass
      case 48: // extends
      case 49: // classDeclarationList
      case 50: // classDeclaration
      case 51: // varDeclarationList
      case 52: // varDeclaration
      case 53: // methodDeclarationList
      case 54: // methodDeclaration
      case 55: // parameterList
      case 56: // type
      case 57: // statementList
      case 58: // statement
      case 59: // expressionList
      case 60: // expression
      case 61: // identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case 3: // IDENTIFIER
      case 4: // LSQUAREP
      case 5: // AND
      case 6: // RSQUAREP
      case 7: // LESSER
      case 8: // GREATER
      case 9: // OR
      case 10: // ASSIGNOP
      case 11: // MULTOP
      case 12: // DIVISIONOP
      case 13: // INT
      case 14: // PLUSOP
      case 15: // MINUSOP
      case 16: // PERIOD
      case 17: // LENGTH
      case 18: // TRUE
      case 19: // FALSE
      case 20: // THIS
      case 21: // NEW
      case 22: // INTEGER
      case 23: // BOOLEAN
      case 24: // LP
      case 25: // RP
      case 26: // NOT
      case 27: // COMMA
      case 28: // LBRACKET
      case 29: // RBRACKET
      case 30: // IF
      case 31: // ELSE
      case 32: // WHILE
      case 33: // PRINT
      case 34: // SEMICOLON
      case 35: // EQUALS
      case 36: // RETURN
      case 37: // PUBLIC
      case 38: // CLASS
      case 39: // EXTENDS
      case 40: // STATIC
      case 41: // VOID
      case 42: // MAIN
      case 43: // STRINGS
      case 44: // STRING
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
      case 46: // program
      case 47: // mainClass
      case 48: // extends
      case 49: // classDeclarationList
      case 50: // classDeclaration
      case 51: // varDeclarationList
      case 52: // varDeclaration
      case 53: // methodDeclarationList
      case 54: // methodDeclaration
      case 55: // parameterList
      case 56: // type
      case 57: // statementList
      case 58: // statement
      case 59: // expressionList
      case 60: // expression
      case 61: // identifier
        value.copy< Node * > (that.value);
        break;

      case 3: // IDENTIFIER
      case 4: // LSQUAREP
      case 5: // AND
      case 6: // RSQUAREP
      case 7: // LESSER
      case 8: // GREATER
      case 9: // OR
      case 10: // ASSIGNOP
      case 11: // MULTOP
      case 12: // DIVISIONOP
      case 13: // INT
      case 14: // PLUSOP
      case 15: // MINUSOP
      case 16: // PERIOD
      case 17: // LENGTH
      case 18: // TRUE
      case 19: // FALSE
      case 20: // THIS
      case 21: // NEW
      case 22: // INTEGER
      case 23: // BOOLEAN
      case 24: // LP
      case 25: // RP
      case 26: // NOT
      case 27: // COMMA
      case 28: // LBRACKET
      case 29: // RBRACKET
      case 30: // IF
      case 31: // ELSE
      case 32: // WHILE
      case 33: // PRINT
      case 34: // SEMICOLON
      case 35: // EQUALS
      case 36: // RETURN
      case 37: // PUBLIC
      case 38: // CLASS
      case 39: // EXTENDS
      case 40: // STATIC
      case 41: // VOID
      case 42: // MAIN
      case 43: // STRINGS
      case 44: // STRING
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
      case 46: // program
      case 47: // mainClass
      case 48: // extends
      case 49: // classDeclarationList
      case 50: // classDeclaration
      case 51: // varDeclarationList
      case 52: // varDeclaration
      case 53: // methodDeclarationList
      case 54: // methodDeclaration
      case 55: // parameterList
      case 56: // type
      case 57: // statementList
      case 58: // statement
      case 59: // expressionList
      case 60: // expression
      case 61: // identifier
        value.move< Node * > (that.value);
        break;

      case 3: // IDENTIFIER
      case 4: // LSQUAREP
      case 5: // AND
      case 6: // RSQUAREP
      case 7: // LESSER
      case 8: // GREATER
      case 9: // OR
      case 10: // ASSIGNOP
      case 11: // MULTOP
      case 12: // DIVISIONOP
      case 13: // INT
      case 14: // PLUSOP
      case 15: // MINUSOP
      case 16: // PERIOD
      case 17: // LENGTH
      case 18: // TRUE
      case 19: // FALSE
      case 20: // THIS
      case 21: // NEW
      case 22: // INTEGER
      case 23: // BOOLEAN
      case 24: // LP
      case 25: // RP
      case 26: // NOT
      case 27: // COMMA
      case 28: // LBRACKET
      case 29: // RBRACKET
      case 30: // IF
      case 31: // ELSE
      case 32: // WHILE
      case 33: // PRINT
      case 34: // SEMICOLON
      case 35: // EQUALS
      case 36: // RETURN
      case 37: // PUBLIC
      case 38: // CLASS
      case 39: // EXTENDS
      case 40: // STATIC
      case 41: // VOID
      case 42: // MAIN
      case 43: // STRINGS
      case 44: // STRING
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
      case 46: // program
      case 47: // mainClass
      case 48: // extends
      case 49: // classDeclarationList
      case 50: // classDeclaration
      case 51: // varDeclarationList
      case 52: // varDeclaration
      case 53: // methodDeclarationList
      case 54: // methodDeclaration
      case 55: // parameterList
      case 56: // type
      case 57: // statementList
      case 58: // statement
      case 59: // expressionList
      case 60: // expression
      case 61: // identifier
        yylhs.value.emplace< Node * > ();
        break;

      case 3: // IDENTIFIER
      case 4: // LSQUAREP
      case 5: // AND
      case 6: // RSQUAREP
      case 7: // LESSER
      case 8: // GREATER
      case 9: // OR
      case 10: // ASSIGNOP
      case 11: // MULTOP
      case 12: // DIVISIONOP
      case 13: // INT
      case 14: // PLUSOP
      case 15: // MINUSOP
      case 16: // PERIOD
      case 17: // LENGTH
      case 18: // TRUE
      case 19: // FALSE
      case 20: // THIS
      case 21: // NEW
      case 22: // INTEGER
      case 23: // BOOLEAN
      case 24: // LP
      case 25: // RP
      case 26: // NOT
      case 27: // COMMA
      case 28: // LBRACKET
      case 29: // RBRACKET
      case 30: // IF
      case 31: // ELSE
      case 32: // WHILE
      case 33: // PRINT
      case 34: // SEMICOLON
      case 35: // EQUALS
      case 36: // RETURN
      case 37: // PUBLIC
      case 38: // CLASS
      case 39: // EXTENDS
      case 40: // STATIC
      case 41: // VOID
      case 42: // MAIN
      case 43: // STRINGS
      case 44: // STRING
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
#line 38 "parser.yy"
                   { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R1 ");}
#line 862 "parser.tab.cc"
    break;

  case 3:
#line 39 "parser.yy"
                                        {
                        printf("R2 Rules \n");
                        yylhs.value.as < Node * > () = new Node("Program", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        root = yylhs.value.as < Node * > ();
                      }
#line 874 "parser.tab.cc"
    break;

  case 4:
#line 48 "parser.yy"
                                                                                                                                           {
                        printf("R3 ");
                        yylhs.value.as < Node * > () = new Node("MainClass", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "PUBLIC"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "STATIC"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "VOID"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "MAIN"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "(")); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "String"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LSQUAREP", "["));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RSQUAREP", "]"));       
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));  
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}")); 
                      }
#line 900 "parser.tab.cc"
    break;

  case 5:
#line 71 "parser.yy"
         {}
#line 906 "parser.tab.cc"
    break;

  case 6:
#line 72 "parser.yy"
                             { 
                        printf("R4 ");
                        yylhs.value.as < Node * > () = new Node("Extends", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "EXTENDS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 917 "parser.tab.cc"
    break;

  case 7:
#line 81 "parser.yy"
                                       { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R5 ");}
#line 923 "parser.tab.cc"
    break;

  case 8:
#line 82 "parser.yy"
                                                {
                        printf("R6 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclarationList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 934 "parser.tab.cc"
    break;

  case 9:
#line 90 "parser.yy"
                                                                                                     {
                        printf("R7 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 950 "parser.tab.cc"
    break;

  case 10:
#line 101 "parser.yy"
                                                                                  {
                        printf("R8 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        if(yystack_[3].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 965 "parser.tab.cc"
    break;

  case 11:
#line 111 "parser.yy"
                                                                                {
                        printf("R9 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        if(yystack_[3].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 980 "parser.tab.cc"
    break;

  case 12:
#line 121 "parser.yy"
                                                            {
                        printf("R10 ");
                        yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "CLASS")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 994 "parser.tab.cc"
    break;

  case 13:
#line 132 "parser.yy"
                                   { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R11 ");}
#line 1000 "parser.tab.cc"
    break;

  case 14:
#line 133 "parser.yy"
                                            {
                        printf("R12 ");
                        yylhs.value.as < Node * > () = new Node("VarDeclarationList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1011 "parser.tab.cc"
    break;

  case 15:
#line 141 "parser.yy"
                                           {
                        printf("R13 ");
                        yylhs.value.as < Node * > () = new Node("VarDeclaration", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";")); 
                      }
#line 1023 "parser.tab.cc"
    break;

  case 16:
#line 150 "parser.yy"
                                         { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R14 ");}
#line 1029 "parser.tab.cc"
    break;

  case 17:
#line 151 "parser.yy"
                                                  { 
                        printf("R15 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclarationList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1040 "parser.tab.cc"
    break;

  case 18:
#line 160 "parser.yy"
                                                                                                                                            {
                        printf("R16 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "public")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[11].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        if(yystack_[8].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        if(yystack_[5].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "return"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 1062 "parser.tab.cc"
    break;

  case 19:
#line 177 "parser.yy"
                                                                                                                          {
                        printf("R17 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "public")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        if(yystack_[7].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "return"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 1083 "parser.tab.cc"
    break;

  case 20:
#line 193 "parser.yy"
                                                                                                                                {
                        printf("R17 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "public")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        if(yystack_[7].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "return"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 1104 "parser.tab.cc"
    break;

  case 21:
#line 209 "parser.yy"
                                                                                                            {
                        printf("R18 ");
                        yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "public")); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        if(yystack_[6].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("", "return"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 1124 "parser.tab.cc"
    break;

  case 22:
#line 226 "parser.yy"
               {}
#line 1130 "parser.tab.cc"
    break;

  case 23:
#line 227 "parser.yy"
                         {
                          printf("R19 ");
                          yylhs.value.as < Node * > () = new Node("ParameterList", ""); 
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1141 "parser.tab.cc"
    break;

  case 24:
#line 233 "parser.yy"
                                              {
                          printf("R20 ");
                          yylhs.value.as < Node * > () = new Node("ParameterList", ""); 
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(new Node("COMMA", ","));
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1154 "parser.tab.cc"
    break;

  case 25:
#line 243 "parser.yy"
                  { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R21 ");}
#line 1160 "parser.tab.cc"
    break;

  case 26:
#line 244 "parser.yy"
                  { yylhs.value.as < Node * > () = new Node("TYPE", yystack_[0].value.as < std::string > ()); printf("R22 ");}
#line 1166 "parser.tab.cc"
    break;

  case 27:
#line 245 "parser.yy"
                  { yylhs.value.as < Node * > () = new Node("TYPE", yystack_[0].value.as < std::string > ()); printf("R23 ");}
#line 1172 "parser.tab.cc"
    break;

  case 28:
#line 246 "parser.yy"
                                    {
                        printf("R24 ");
                        yylhs.value.as < Node * > () = new Node("TypeVector", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("Type", "INT"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LSQUAREP", "["));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RSQUAREP", "]"));
                      }
#line 1184 "parser.tab.cc"
    break;

  case 29:
#line 254 "parser.yy"
                          { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R25 ");}
#line 1190 "parser.tab.cc"
    break;

  case 30:
#line 255 "parser.yy"
                                 {
                        printf("R26 ");
                        yylhs.value.as < Node * > () = new Node("StatementList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1201 "parser.tab.cc"
    break;

  case 31:
#line 263 "parser.yy"
                                           {
                        printf("R27 ");
                        yylhs.value.as < Node * > () = new Node("Statement", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LBRACKET", "{"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RBRACKET", "}"));
                      }
#line 1213 "parser.tab.cc"
    break;

  case 32:
#line 270 "parser.yy"
                                                      {
                        printf("R28 ");
                        yylhs.value.as < Node * > () = new Node("IFStatement", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("IF", "if"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("ELSE", "else"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1229 "parser.tab.cc"
    break;

  case 33:
#line 281 "parser.yy"
                                          {
                        printf("R29 ");
                        yylhs.value.as < Node * > () = new Node("WHILEStatement", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("WHILE", "while"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1243 "parser.tab.cc"
    break;

  case 34:
#line 290 "parser.yy"
                                           {
                        printf("R30 ");
                        yylhs.value.as < Node * > () = new Node("PrintStatement", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PRINT", "System.out.println"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                      }
#line 1257 "parser.tab.cc"
    break;

  case 35:
#line 299 "parser.yy"
                                                {
                        printf("R31 ");
                        yylhs.value.as < Node * > () = new Node("AssignmentStatement", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("EQUALS", "="));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                      }
#line 1270 "parser.tab.cc"
    break;

  case 36:
#line 307 "parser.yy"
                                                                              {
                        printf("R32 ");
                        yylhs.value.as < Node * > () = new Node("VectorAssignmentStatement", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ()); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LSQUAREP", "["));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RSQUAREP", "]"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("EQUALS", "="));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("SEMICOLON", ";"));
                      }
#line 1286 "parser.tab.cc"
    break;

  case 37:
#line 320 "parser.yy"
                           { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R33 ");}
#line 1292 "parser.tab.cc"
    break;

  case 38:
#line 321 "parser.yy"
                                                {
                        printf("R34 ");
                        yylhs.value.as < Node * > () = new Node("ExpressionList", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("COMMA", ","));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1304 "parser.tab.cc"
    break;

  case 39:
#line 330 "parser.yy"
                       { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R35 ");}
#line 1310 "parser.tab.cc"
    break;

  case 40:
#line 331 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("INTEGER", yystack_[0].value.as < std::string > ()); printf("R36 ");}
#line 1316 "parser.tab.cc"
    break;

  case 41:
#line 332 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("LITERAL", yystack_[0].value.as < std::string > ()); printf("R37 ");}
#line 1322 "parser.tab.cc"
    break;

  case 42:
#line 333 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("LITERAL", yystack_[0].value.as < std::string > ()); printf("R38 ");}
#line 1328 "parser.tab.cc"
    break;

  case 43:
#line 334 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("", yystack_[0].value.as < std::string > ()); printf("R39 ");}
#line 1334 "parser.tab.cc"
    break;

  case 44:
#line 335 "parser.yy"
                                                   {
                        printf("R40 ");
                        yylhs.value.as < Node * > () = new Node("LESSERExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LESSER", "<"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      
                      }
#line 1347 "parser.tab.cc"
    break;

  case 45:
#line 343 "parser.yy"
                                                     {
                        printf("R40 ");
                        yylhs.value.as < Node * > () = new Node("ASSIGNMENTExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("ASSIGNMENT", "=="));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      
                      }
#line 1360 "parser.tab.cc"
    break;

  case 46:
#line 351 "parser.yy"
                                                    {
                        printf("R40 ");
                        yylhs.value.as < Node * > () = new Node("GREATERExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("GREATER", ">"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      
                      }
#line 1373 "parser.tab.cc"
    break;

  case 47:
#line 359 "parser.yy"
                                               {
                        printf("R40 ");
                        yylhs.value.as < Node * > () = new Node("ORExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("OR", "||"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      
                      }
#line 1386 "parser.tab.cc"
    break;

  case 48:
#line 368 "parser.yy"
                                                {
                        printf("R41 ");
                        yylhs.value.as < Node * > () = new Node("AndExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("AND", "&&"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                     
                      }
#line 1399 "parser.tab.cc"
    break;

  case 49:
#line 376 "parser.yy"
                                                   {
                        printf("R42 ");
                        yylhs.value.as < Node * > () = new Node("MultExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("MULTOP", "*"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        
                      }
#line 1412 "parser.tab.cc"
    break;

  case 50:
#line 384 "parser.yy"
                                                       {
                        printf("R42 ");
                        yylhs.value.as < Node * > () = new Node("DIVISIONExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("DIVISION", "/"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        
                      }
#line 1425 "parser.tab.cc"
    break;

  case 51:
#line 392 "parser.yy"
                                                   {
                        printf("R43 ");
                        yylhs.value.as < Node * > () = new Node("PlusExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PLUS", "+"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        
                      }
#line 1438 "parser.tab.cc"
    break;

  case 52:
#line 400 "parser.yy"
                                                    {
                        printf("R44 ");
                        yylhs.value.as < Node * > () = new Node("MinusExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("MINUS", "-"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        
                      }
#line 1451 "parser.tab.cc"
    break;

  case 53:
#line 408 "parser.yy"
                                                 {
                        printf("R45 ");
                        yylhs.value.as < Node * > () = new Node("VectorAccessExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LSQUAREP", "["));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RSQUAREP", "]"));
                      }
#line 1464 "parser.tab.cc"
    break;

  case 54:
#line 416 "parser.yy"
                                                  {
                        printf("R46 ");
                        yylhs.value.as < Node * > () = new Node("LengthExpression", ""); 
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PERIOD", "."));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LENGTH", "length"));
                      }
#line 1476 "parser.tab.cc"
    break;

  case 55:
#line 423 "parser.yy"
                                                                      {
                        printf("R47 ");
                        yylhs.value.as < Node * > () = new Node("NewVectorExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("NEW", "new"));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("INT", "int")); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LSQUAREP", "["));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RSQUAREP", "]")); 
                      }
#line 1490 "parser.tab.cc"
    break;

  case 56:
#line 432 "parser.yy"
                                         {
                        printf("R48 ");
                        yylhs.value.as < Node * > () = new Node("NewClassExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("NEW", "new"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "(")); 
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                      }
#line 1503 "parser.tab.cc"
    break;

  case 57:
#line 440 "parser.yy"
                                         {
                        printf("R49 ");
                        yylhs.value.as < Node * > () = new Node("NOTExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("NOT", "!"));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1514 "parser.tab.cc"
    break;

  case 58:
#line 446 "parser.yy"
                                          {
                        printf("R50 ");
                        yylhs.value.as < Node * > () = new Node("ParenExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                      }
#line 1526 "parser.tab.cc"
    break;

  case 59:
#line 453 "parser.yy"
                                                           {
                        printf("R51 ");
                        yylhs.value.as < Node * > () = new Node("MethodCallExpression", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PERIOD", "."));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                      }
#line 1541 "parser.tab.cc"
    break;

  case 60:
#line 463 "parser.yy"
                                            {
                        printf("R52 ");
                        yylhs.value.as < Node * > () = new Node("MethodCallExpressionWithoutArgs", "");
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("PERIOD", "."));
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(new Node("LP", "("));
                        yylhs.value.as < Node * > ()->children.push_back(new Node("RP", ")"));
                      }
#line 1555 "parser.tab.cc"
    break;

  case 61:
#line 474 "parser.yy"
                       {  yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > ()); printf("R53 %s ",yystack_[0].value.as < std::string > ().c_str());}
#line 1561 "parser.tab.cc"
    break;


#line 1565 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -53;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -29,    18,     1,   -53,   -53,    -2,   -53,    18,     2,   -53,
      15,    -4,   -53,   -53,    -3,    18,    27,    28,   -53,     7,
      26,    61,   -53,   -53,    24,    48,   -53,   -24,   -53,    18,
     -53,    54,    73,    18,   -53,   -53,    13,   -53,   -53,    46,
      39,   -53,    62,   -53,   -53,    93,    24,    92,    75,    18,
      18,    76,    81,    78,   115,    24,    83,   262,    88,    89,
      95,   311,   131,   146,   -53,     3,   -53,   262,   249,     3,
     311,   311,   311,   -53,   -53,   -53,   -53,     0,   311,   311,
     183,   -53,   311,   153,   311,   -53,   311,   311,    87,   -53,
     334,   353,   372,   113,   106,   391,    50,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,    16,   102,   196,
     311,   211,   413,   224,   103,   262,   262,   101,   311,   111,
     -53,   426,   462,   161,   452,   452,   452,   472,    65,    80,
      80,   -53,   116,   -53,   110,   239,   117,   107,   -53,   -53,
     121,   -53,   -53,   439,   -53,   -53,   302,   -53,   126,   -53,
     311,   262,   -53,   -53,   119,   292,   -53,   252,   -53,   -53,
     311,   -53,   -53
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,    61,     0,     1,     0,     0,     7,
       0,     5,     3,     8,     0,     0,     0,     0,     6,     0,
       0,    26,    27,    12,     0,     0,    13,     0,    16,     0,
      25,     0,     0,     0,    11,    14,     0,    10,    17,     0,
       0,    28,     0,     9,    15,     0,    22,     0,     0,     0,
       0,     0,    23,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    25,    24,     0,     0,     0,
       0,     0,     0,    40,    41,    42,    43,     0,     0,     0,
       0,    39,     0,     0,     0,    30,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,    48,    44,    46,    47,    45,    49,    50,    51,
      52,    54,     0,    21,     0,     0,     0,     0,    35,     4,
       0,    33,    34,     0,    56,    53,     0,    20,     0,    19,
       0,     0,    55,    60,     0,    37,    18,     0,    32,    59,
       0,    36,    38
  };

  const short
  parser::yypgoto_[] =
  {
     -53,   -53,   -53,   -53,   -53,   149,   104,   -21,   135,   -19,
     120,   -12,   -37,   -52,     5,    23,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    16,     8,     9,    25,    26,    27,    28,
      48,    29,    63,    64,   154,   155,    81
  };

  const short
  parser::yytable_[] =
  {
       5,     6,    12,     4,    35,    37,    11,    86,    38,     1,
       4,    85,    33,    24,    18,    88,    85,    38,    30,     4,
      68,     4,    93,    30,    30,    83,    10,     4,    39,    21,
      22,    85,    42,   131,    49,    15,    23,    17,    87,     7,
       7,    35,    43,    49,    24,    30,    21,    22,    52,    53,
      24,     4,    14,    65,    30,    19,    69,    99,   100,   101,
     102,    65,    69,   140,   141,    32,    69,    69,    31,    20,
      21,    22,    99,   100,   101,   102,    94,    34,    40,    41,
      44,   107,    69,    45,    80,    24,    46,    99,   100,   101,
     102,   103,   104,    90,    91,    92,   107,    47,    50,   158,
      51,    95,    96,    56,    54,   109,   132,   111,    55,   112,
     113,    67,    70,    71,    69,    69,   114,   118,     4,    72,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     119,   133,   139,   135,     4,   142,   144,    21,    22,   147,
     146,   143,   150,    57,   159,    58,   149,    59,    60,     4,
      69,    61,   151,    21,    22,   156,     4,    13,    62,    57,
      36,    58,     0,    59,    60,   162,     0,    82,    -1,   100,
     101,   102,     0,   157,    57,    66,    58,     0,    59,    60,
       0,    57,    84,    58,     0,    59,    60,    97,    98,   110,
      99,   100,   101,   102,   103,   104,     0,   105,   106,   107,
      97,    98,     0,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,     0,     0,    97,    98,   108,    99,   100,
     101,   102,   103,   104,     0,   105,   106,   107,    97,    98,
     134,    99,   100,   101,   102,   103,   104,     0,   105,   106,
     107,     0,     0,    97,    98,   136,    99,   100,   101,   102,
     103,   104,     4,   105,   106,   107,    97,    98,   138,    99,
     100,   101,   102,   103,   104,     4,   105,   106,   107,     0,
       0,     0,     0,   148,     0,     0,     0,    57,    89,    58,
       0,    59,    60,     0,     0,     0,   161,     0,     0,     0,
      57,     0,    58,     0,    59,    60,    97,    98,     0,    99,
     100,   101,   102,   103,   104,     4,   105,   106,   107,     0,
       0,     0,     0,     0,     4,    73,     0,     0,     0,   160,
      74,    75,    76,    77,    73,     0,    78,   153,    79,    74,
      75,    76,    77,     0,     0,    78,     0,    79,    97,    98,
       0,    99,   100,   101,   102,   103,   104,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,    97,    98,   115,
      99,   100,   101,   102,   103,   104,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,    97,    98,   116,    99,
     100,   101,   102,   103,   104,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,    97,    98,   117,    99,   100,
     101,   102,   103,   104,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,   120,    97,    98,   137,
      99,   100,   101,   102,   103,   104,     0,   105,   106,   107,
      97,    98,   145,    99,   100,   101,   102,   103,   104,     0,
     105,   106,   107,    97,    98,   152,    99,   100,   101,   102,
     103,   104,     0,   105,   106,   107,    97,    98,     0,    99,
     100,   101,   102,   103,   104,     0,   105,   106,   107,    99,
     100,   101,   102,   103,   104,     0,   105,   106,   107,    99,
     100,   101,   102,     0,   104,     0,     0,     0,   107
  };

  const short
  parser::yycheck_[] =
  {
       1,     0,     0,     3,    25,    29,     7,     4,    27,    38,
       3,    63,    24,    37,    15,    67,    68,    36,    19,     3,
      57,     3,    22,    24,    25,    62,    28,     3,    29,    22,
      23,    83,    33,    17,    46,    39,    29,    40,    35,    38,
      38,    62,    29,    55,    37,    46,    22,    23,    49,    50,
      37,     3,    37,    54,    55,    28,    57,     7,     8,     9,
      10,    62,    63,   115,   116,     4,    67,    68,    42,    41,
      22,    23,     7,     8,     9,    10,    77,    29,    24,     6,
      34,    16,    83,    44,    61,    37,    24,     7,     8,     9,
      10,    11,    12,    70,    71,    72,    16,     4,     6,   151,
      25,    78,    79,    25,    28,    82,   107,    84,    27,    86,
      87,    28,    24,    24,   115,   116,    29,     4,     3,    24,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      24,    29,    29,   110,     3,    34,    25,    22,    23,    29,
      24,   118,    35,    28,    25,    30,    29,    32,    33,     3,
     151,    36,    31,    22,    23,    29,     3,     8,    54,    28,
      25,    30,    -1,    32,    33,   160,    -1,    36,     7,     8,
       9,    10,    -1,   150,    28,    55,    30,    -1,    32,    33,
      -1,    28,    36,    30,    -1,    32,    33,     4,     5,    36,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    -1,    -1,     4,     5,    34,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,     4,     5,
      34,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    -1,    -1,     4,     5,    34,     7,     8,     9,    10,
      11,    12,     3,    14,    15,    16,     4,     5,    34,     7,
       8,     9,    10,    11,    12,     3,    14,    15,    16,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    28,    29,    30,
      -1,    32,    33,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,     4,     5,    -1,     7,
       8,     9,    10,    11,    12,     3,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,     3,    13,    -1,    -1,    -1,    27,
      18,    19,    20,    21,    13,    -1,    24,    25,    26,    18,
      19,    20,    21,    -1,    -1,    24,    -1,    26,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    25,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    25,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    25,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,     4,     5,    -1,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,     7,
       8,     9,    10,    -1,    12,    -1,    -1,    -1,    16
  };

  const signed char
  parser::yystos_[] =
  {
       0,    38,    46,    47,     3,    61,     0,    38,    49,    50,
      28,    61,     0,    50,    37,    39,    48,    40,    61,    28,
      41,    22,    23,    29,    37,    51,    52,    53,    54,    56,
      61,    42,     4,    56,    29,    52,    53,    29,    54,    61,
      24,     6,    61,    29,    34,    44,    24,     4,    55,    56,
       6,    25,    61,    61,    28,    27,    25,    28,    30,    32,
      33,    36,    51,    57,    58,    61,    55,    28,    57,    61,
      24,    24,    24,    13,    18,    19,    20,    21,    24,    26,
      60,    61,    36,    57,    36,    58,     4,    35,    58,    29,
      60,    60,    60,    22,    61,    60,    60,     4,     5,     7,
       8,     9,    10,    11,    12,    14,    15,    16,    34,    60,
      36,    60,    60,    60,    29,    25,    25,    25,     4,    24,
      25,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    17,    61,    29,    34,    60,    34,     6,    34,    29,
      58,    58,    34,    60,    25,     6,    24,    29,    34,    29,
      35,    31,     6,    25,    59,    60,    29,    60,    58,    25,
      27,    34,    59
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    46,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    51,    51,    52,    53,    53,    54,    54,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,    17,     0,     2,     1,     2,     7,
       6,     6,     5,     1,     2,     3,     1,     2,    13,    12,
      12,    11,     0,     2,     4,     1,     1,     1,     3,     1,
       2,     3,     7,     5,     5,     4,     7,     1,     3,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     5,     4,     2,     3,     6,
       5,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IDENTIFIER", "LSQUAREP",
  "AND", "RSQUAREP", "LESSER", "GREATER", "OR", "ASSIGNOP", "MULTOP",
  "DIVISIONOP", "INT", "PLUSOP", "MINUSOP", "PERIOD", "LENGTH", "TRUE",
  "FALSE", "THIS", "NEW", "INTEGER", "BOOLEAN", "LP", "RP", "NOT", "COMMA",
  "LBRACKET", "RBRACKET", "IF", "ELSE", "WHILE", "PRINT", "SEMICOLON",
  "EQUALS", "RETURN", "PUBLIC", "CLASS", "EXTENDS", "STATIC", "VOID",
  "MAIN", "STRINGS", "STRING", "$accept", "program", "mainClass",
  "extends", "classDeclarationList", "classDeclaration",
  "varDeclarationList", "varDeclaration", "methodDeclarationList",
  "methodDeclaration", "parameterList", "type", "statementList",
  "statement", "expressionList", "expression", "identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    38,    38,    39,    48,    71,    72,    81,    82,    90,
     101,   111,   121,   132,   133,   141,   150,   151,   160,   177,
     193,   209,   226,   227,   233,   243,   244,   245,   246,   254,
     255,   263,   270,   281,   290,   299,   307,   320,   321,   330,
     331,   332,   333,   334,   335,   343,   351,   359,   368,   376,
     384,   392,   400,   408,   416,   423,   432,   440,   446,   453,
     463,   474
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
#line 2112 "parser.tab.cc"

