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
  

#line 54 "parser.tab.cc"


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
#line 126 "parser.tab.cc"


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
      case 45: // goal
      case 46: // mainclass
      case 47: // extends
      case 48: // classList
      case 49: // classDec
      case 50: // varList
      case 51: // varDec
      case 52: // methodList
      case 53: // methodDec
      case 54: // identifierList
      case 55: // type
      case 56: // stateList
      case 57: // statement
      case 58: // identifier
      case 59: // expList
      case 60: // expression
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // RSQUAREP
      case 10: // LSQUAREP
      case 11: // LBRACKET
      case 12: // RBRACKET
      case 13: // COMMA
      case 14: // SEMICOLON
      case 15: // EQUALS
      case 16: // DIVISIONOP
      case 17: // AND
      case 18: // OR
      case 19: // LESSER
      case 20: // GREATER
      case 21: // ASSIGNOP
      case 22: // CLASS
      case 23: // PUBLIC
      case 24: // STATIC
      case 25: // VOID
      case 26: // MAIN
      case 27: // STRING
      case 28: // EXTENDS
      case 29: // RETURN
      case 30: // INTEGER
      case 31: // BOOLEAN
      case 32: // IF
      case 33: // ELSE
      case 34: // WHILE
      case 35: // PRINT
      case 36: // PERIOD
      case 37: // LENGTH
      case 38: // TRUE
      case 39: // FALSE
      case 40: // NEW
      case 41: // NOT
      case 42: // THIS
      case 43: // IDENTIFIER
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
      case 45: // goal
      case 46: // mainclass
      case 47: // extends
      case 48: // classList
      case 49: // classDec
      case 50: // varList
      case 51: // varDec
      case 52: // methodList
      case 53: // methodDec
      case 54: // identifierList
      case 55: // type
      case 56: // stateList
      case 57: // statement
      case 58: // identifier
      case 59: // expList
      case 60: // expression
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // RSQUAREP
      case 10: // LSQUAREP
      case 11: // LBRACKET
      case 12: // RBRACKET
      case 13: // COMMA
      case 14: // SEMICOLON
      case 15: // EQUALS
      case 16: // DIVISIONOP
      case 17: // AND
      case 18: // OR
      case 19: // LESSER
      case 20: // GREATER
      case 21: // ASSIGNOP
      case 22: // CLASS
      case 23: // PUBLIC
      case 24: // STATIC
      case 25: // VOID
      case 26: // MAIN
      case 27: // STRING
      case 28: // EXTENDS
      case 29: // RETURN
      case 30: // INTEGER
      case 31: // BOOLEAN
      case 32: // IF
      case 33: // ELSE
      case 34: // WHILE
      case 35: // PRINT
      case 36: // PERIOD
      case 37: // LENGTH
      case 38: // TRUE
      case 39: // FALSE
      case 40: // NEW
      case 41: // NOT
      case 42: // THIS
      case 43: // IDENTIFIER
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
      case 45: // goal
      case 46: // mainclass
      case 47: // extends
      case 48: // classList
      case 49: // classDec
      case 50: // varList
      case 51: // varDec
      case 52: // methodList
      case 53: // methodDec
      case 54: // identifierList
      case 55: // type
      case 56: // stateList
      case 57: // statement
      case 58: // identifier
      case 59: // expList
      case 60: // expression
        value.copy< Node * > (that.value);
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // RSQUAREP
      case 10: // LSQUAREP
      case 11: // LBRACKET
      case 12: // RBRACKET
      case 13: // COMMA
      case 14: // SEMICOLON
      case 15: // EQUALS
      case 16: // DIVISIONOP
      case 17: // AND
      case 18: // OR
      case 19: // LESSER
      case 20: // GREATER
      case 21: // ASSIGNOP
      case 22: // CLASS
      case 23: // PUBLIC
      case 24: // STATIC
      case 25: // VOID
      case 26: // MAIN
      case 27: // STRING
      case 28: // EXTENDS
      case 29: // RETURN
      case 30: // INTEGER
      case 31: // BOOLEAN
      case 32: // IF
      case 33: // ELSE
      case 34: // WHILE
      case 35: // PRINT
      case 36: // PERIOD
      case 37: // LENGTH
      case 38: // TRUE
      case 39: // FALSE
      case 40: // NEW
      case 41: // NOT
      case 42: // THIS
      case 43: // IDENTIFIER
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
      case 45: // goal
      case 46: // mainclass
      case 47: // extends
      case 48: // classList
      case 49: // classDec
      case 50: // varList
      case 51: // varDec
      case 52: // methodList
      case 53: // methodDec
      case 54: // identifierList
      case 55: // type
      case 56: // stateList
      case 57: // statement
      case 58: // identifier
      case 59: // expList
      case 60: // expression
        value.move< Node * > (that.value);
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // RSQUAREP
      case 10: // LSQUAREP
      case 11: // LBRACKET
      case 12: // RBRACKET
      case 13: // COMMA
      case 14: // SEMICOLON
      case 15: // EQUALS
      case 16: // DIVISIONOP
      case 17: // AND
      case 18: // OR
      case 19: // LESSER
      case 20: // GREATER
      case 21: // ASSIGNOP
      case 22: // CLASS
      case 23: // PUBLIC
      case 24: // STATIC
      case 25: // VOID
      case 26: // MAIN
      case 27: // STRING
      case 28: // EXTENDS
      case 29: // RETURN
      case 30: // INTEGER
      case 31: // BOOLEAN
      case 32: // IF
      case 33: // ELSE
      case 34: // WHILE
      case 35: // PRINT
      case 36: // PERIOD
      case 37: // LENGTH
      case 38: // TRUE
      case 39: // FALSE
      case 40: // NEW
      case 41: // NOT
      case 42: // THIS
      case 43: // IDENTIFIER
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
      case 45: // goal
      case 46: // mainclass
      case 47: // extends
      case 48: // classList
      case 49: // classDec
      case 50: // varList
      case 51: // varDec
      case 52: // methodList
      case 53: // methodDec
      case 54: // identifierList
      case 55: // type
      case 56: // stateList
      case 57: // statement
      case 58: // identifier
      case 59: // expList
      case 60: // expression
        yylhs.value.emplace< Node * > ();
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // RSQUAREP
      case 10: // LSQUAREP
      case 11: // LBRACKET
      case 12: // RBRACKET
      case 13: // COMMA
      case 14: // SEMICOLON
      case 15: // EQUALS
      case 16: // DIVISIONOP
      case 17: // AND
      case 18: // OR
      case 19: // LESSER
      case 20: // GREATER
      case 21: // ASSIGNOP
      case 22: // CLASS
      case 23: // PUBLIC
      case 24: // STATIC
      case 25: // VOID
      case 26: // MAIN
      case 27: // STRING
      case 28: // EXTENDS
      case 29: // RETURN
      case 30: // INTEGER
      case 31: // BOOLEAN
      case 32: // IF
      case 33: // ELSE
      case 34: // WHILE
      case 35: // PRINT
      case 36: // PERIOD
      case 37: // LENGTH
      case 38: // TRUE
      case 39: // FALSE
      case 40: // NEW
      case 41: // NOT
      case 42: // THIS
      case 43: // IDENTIFIER
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
#line 29 "parser.yy"
               { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R1 ");}
#line 855 "parser.tab.cc"
    break;

  case 3:
#line 30 "parser.yy"
                          {
        printf("R2 \n");
        yylhs.value.as < Node * > () = new Node("GOAL","");
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        root = yylhs.value.as < Node * > ();
      }
#line 867 "parser.tab.cc"
    break;

  case 4:
#line 37 "parser.yy"
                                                                                                                                          {
          printf("R3 ");
          yylhs.value.as < Node * > () = new Node ("Main Class","");
          yylhs.value.as < Node * > ()->children.push_back(new Node("","CLASS"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("",yystack_[13].value.as < std::string > ()));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","STATIC"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","VOID"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","MAIN"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","STRING"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","["));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","]"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));
}
#line 893 "parser.tab.cc"
    break;

  case 5:
#line 58 "parser.yy"
         {}
#line 899 "parser.tab.cc"
    break;

  case 6:
#line 59 "parser.yy"
                    {
            printf("R4 ");
            yylhs.value.as < Node * > () = new Node("EXTENDS", "");
            yylhs.value.as < Node * > ()->children.push_back(new Node("",""));
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

}
#line 911 "parser.tab.cc"
    break;

  case 7:
#line 66 "parser.yy"
                   {
            yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            printf("R5 ");
            }
#line 920 "parser.tab.cc"
    break;

  case 8:
#line 71 "parser.yy"
                             {
             printf("R6 "); 
             yylhs.value.as < Node * > () = new Node("List of Class/es","");
             yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
             yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 931 "parser.tab.cc"
    break;

  case 9:
#line 77 "parser.yy"
                                                                      {
            printf("R7 ");
            yylhs.value.as < Node * > () = new Node("Class Declaration","");
            yylhs.value.as < Node * > ()->children.push_back(new Node("","CLASS"));
            yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
            if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
            if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); 
            yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));
  }
#line 947 "parser.tab.cc"
    break;

  case 10:
#line 89 "parser.yy"
                                                       {
            printf("R7.1 ");
            yylhs.value.as < Node * > () = new Node("Class Declaration","");
            yylhs.value.as < Node * > ()->children.push_back(new Node("","CLASS"));
            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
            if(yystack_[3].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
            if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            //if($6) $$->children.push_back($6); 
            yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));
  }
#line 963 "parser.tab.cc"
    break;

  case 11:
#line 102 "parser.yy"
                                                    {
            printf("R7.2 ");
            yylhs.value.as < Node * > () = new Node("Class Declaration","");
            yylhs.value.as < Node * > ()->children.push_back(new Node("","CLASS"));
            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
            if(yystack_[3].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
            if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            //if($6) $$->children.push_back($6); 
            yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));
  }
#line 979 "parser.tab.cc"
    break;

  case 12:
#line 115 "parser.yy"
                                            {
            printf("R7.3 ");
            yylhs.value.as < Node * > () = new Node("Class Declaration","");
            yylhs.value.as < Node * > ()->children.push_back(new Node("","CLASS"));
            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
            if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
            //if($5) $$->children.push_back($5);
            //if($6) $$->children.push_back($6); 
            yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));
  }
#line 995 "parser.tab.cc"
    break;

  case 13:
#line 127 "parser.yy"
               {
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              printf("R8 ");
}
#line 1004 "parser.tab.cc"
    break;

  case 14:
#line 132 "parser.yy"
                        {
             printf("R9 "); 
             yylhs.value.as < Node * > () = new Node("List of Variable/s","");
             yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
             yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
}
#line 1015 "parser.tab.cc"
    break;

  case 15:
#line 138 "parser.yy"
                                 {
        printf("R10 ");
        yylhs.value.as < Node * > () = new Node(" Variable Declaration", "");
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(new Node("",";"));
}
#line 1027 "parser.tab.cc"
    break;

  case 16:
#line 145 "parser.yy"
                     {
              yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
              printf("R11 ");
}
#line 1036 "parser.tab.cc"
    break;

  case 17:
#line 150 "parser.yy"
                                {
             printf("R12 "); 
             yylhs.value.as < Node * > () = new Node("List of Method/s","");
             yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
             yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
}
#line 1047 "parser.tab.cc"
    break;

  case 18:
#line 156 "parser.yy"
                                                                                                                {
          printf("R13 ");
          yylhs.value.as < Node * > () = new Node(" Method Declaration", "");
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Public"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
          if(yystack_[7].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
          if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Return"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",";"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));


}
#line 1070 "parser.tab.cc"
    break;

  case 19:
#line 174 "parser.yy"
                                                                                           {
          printf("R13.1 ");
          yylhs.value.as < Node * > () = new Node(" Method Declaration", "");
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Public"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
          if(yystack_[6].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
          //if($8) $$->children.push_back($8);
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Return"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",";"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));
}
#line 1091 "parser.tab.cc"
    break;

  case 20:
#line 191 "parser.yy"
                                                                                                                        {
          printf("R13.2 ");
          yylhs.value.as < Node * > () = new Node(" Method Declaration", "");
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Public"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[11].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
          if(yystack_[8].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
          if(yystack_[5].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
          if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Return"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",";"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));


}
#line 1115 "parser.tab.cc"
    break;

  case 21:
#line 211 "parser.yy"
                                                                                                      {
          printf("R13.3 ");
          yylhs.value.as < Node * > () = new Node(" Method Declaration", "");
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Public"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
          if(yystack_[6].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
          //if($8) $$->children.push_back($8);
          //if($9) $$->children.push_back($9);
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Return"));
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(new Node("",";"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));


}
#line 1139 "parser.tab.cc"
    break;

  case 22:
#line 231 "parser.yy"
                {}
#line 1145 "parser.tab.cc"
    break;

  case 23:
#line 232 "parser.yy"
                 {
                    printf("R14 ");
                    yylhs.value.as < Node * > () = new Node("List of Identifier/s","");
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
}
#line 1156 "parser.tab.cc"
    break;

  case 24:
#line 239 "parser.yy"
                                                   {
                    printf("R15 ");
                    yylhs.value.as < Node * > () = new Node("List of Identifier/s","");
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); 
                    yylhs.value.as < Node * > ()->children.push_back(new Node("","Comma"));
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 

}
#line 1170 "parser.tab.cc"
    break;

  case 25:
#line 248 "parser.yy"
                               {
          printf("R16 ");
          yylhs.value.as < Node * > () = new Node("Array","");
          yylhs.value.as < Node * > ()->children.push_back(new Node("","Integer"));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","["));
          yylhs.value.as < Node * > ()->children.push_back(new Node("","]"));
}
#line 1182 "parser.tab.cc"
    break;

  case 26:
#line 256 "parser.yy"
              {
          printf("R17 ");
          yylhs.value.as < Node * > () = new Node("Boolean","");          
}
#line 1191 "parser.tab.cc"
    break;

  case 27:
#line 261 "parser.yy"
              {
          printf("R18 ");
          yylhs.value.as < Node * > () = new Node("Integer","");
}
#line 1200 "parser.tab.cc"
    break;

  case 28:
#line 266 "parser.yy"
                {
            yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
            printf("R19 ");
}
#line 1209 "parser.tab.cc"
    break;

  case 29:
#line 270 "parser.yy"
                     {
                  yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                  printf("R20 "); 
}
#line 1218 "parser.tab.cc"
    break;

  case 30:
#line 275 "parser.yy"
                              {
                  printf("R21 ");
                  yylhs.value.as < Node * > () = new Node("List of statement/s","");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
}
#line 1229 "parser.tab.cc"
    break;

  case 31:
#line 281 "parser.yy"
                  {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); printf("R60");}
#line 1235 "parser.tab.cc"
    break;

  case 32:
#line 282 "parser.yy"
                             {
                  printf("R22 ");
                  yylhs.value.as < Node * > () = new Node("Statement", "");
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","{"));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","}"));

}
#line 1248 "parser.tab.cc"
    break;

  case 33:
#line 290 "parser.yy"
                                                        {
                  printf("R23 ");
                  yylhs.value.as < Node * > () = new Node("If Else", "");
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","If"));
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","Else"));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

}
#line 1265 "parser.tab.cc"
    break;

  case 34:
#line 302 "parser.yy"
                                            {
                  printf("R24 ");
                  yylhs.value.as < Node * > () = new Node("While", "");
                  yylhs.value.as < Node * > ()->children.push_back(new Node("",""));
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1279 "parser.tab.cc"
    break;

  case 35:
#line 311 "parser.yy"
                                             {
                  printf("R25 ");
                  yylhs.value.as < Node * > () = new Node("Print Statement", "");
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","Print"));
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
                  yylhs.value.as < Node * > ()->children.push_back(new Node("",";"));
}
#line 1293 "parser.tab.cc"
    break;

  case 36:
#line 321 "parser.yy"
                                                 {
                  printf("R26 ");
                  yylhs.value.as < Node * > () = new Node("Equation", "");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","Equals to"));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("",";"));
}
#line 1306 "parser.tab.cc"
    break;

  case 37:
#line 329 "parser.yy"
                                                                             {
                  printf("R27 ");
                  yylhs.value.as < Node * > () = new Node("Equating", "");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","["));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","]"));
                  yylhs.value.as < Node * > ()->children.push_back(new Node("","Equals to"));
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(new Node("",";"));

}
#line 1323 "parser.tab.cc"
    break;

  case 38:
#line 341 "parser.yy"
                      {
                printf("R52 %s ",yystack_[0].value.as < std::string > ().c_str());
                yylhs.value.as < Node * > () = new Node ("Identifier",yystack_[0].value.as < std::string > ());
                

}
#line 1334 "parser.tab.cc"
    break;

  case 39:
#line 347 "parser.yy"
                   {
                      yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                      printf("R28 ");
}
#line 1343 "parser.tab.cc"
    break;

  case 40:
#line 352 "parser.yy"
                                          {
                      printf("R29 ");
                      yylhs.value.as < Node * > () = new Node("List of Expression/s", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","Comma"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1355 "parser.tab.cc"
    break;

  case 41:
#line 359 "parser.yy"
                                    {
                printf("R30 ");
                yylhs.value.as < Node * > () = new Node("AND", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","and"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1367 "parser.tab.cc"
    break;

  case 42:
#line 367 "parser.yy"
                          {
                printf("R31 ");
                yylhs.value.as < Node * > () = new Node("OR", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","or"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1379 "parser.tab.cc"
    break;

  case 43:
#line 375 "parser.yy"
                              {
                printf("R32 ");
                yylhs.value.as < Node * > () = new Node("Less than", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","less than"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1391 "parser.tab.cc"
    break;

  case 44:
#line 383 "parser.yy"
                               {
                printf("R33 ");
                yylhs.value.as < Node * > () = new Node("Greater Than", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","greater than"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1403 "parser.tab.cc"
    break;

  case 45:
#line 391 "parser.yy"
                                {
                printf("R34 ");
                yylhs.value.as < Node * > () = new Node("Assignment", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","Assignment"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1415 "parser.tab.cc"
    break;

  case 46:
#line 399 "parser.yy"
                              {
                printf("R35 ");
                yylhs.value.as < Node * > () = new Node("Addition", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","Addition"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1427 "parser.tab.cc"
    break;

  case 47:
#line 407 "parser.yy"
                               {
                printf("R36 ");
                yylhs.value.as < Node * > () = new Node("Subtraction", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","Subtractiom"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1439 "parser.tab.cc"
    break;

  case 48:
#line 415 "parser.yy"
                              {
                printf("R37 ");
                yylhs.value.as < Node * > () = new Node("Multiplication", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","Multiplication"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1451 "parser.tab.cc"
    break;

  case 49:
#line 423 "parser.yy"
                                  {
                printf("R38 ");
                yylhs.value.as < Node * > () = new Node("Dividion", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(new Node("","Division"));
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1463 "parser.tab.cc"
    break;

  case 50:
#line 430 "parser.yy"
                                         {
                printf("R39 ");
                yylhs.value.as < Node * > () = new Node ("Vector","");
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("","["));
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("","]"));
}
#line 1476 "parser.tab.cc"
    break;

  case 51:
#line 438 "parser.yy"
                          {
                printf("R40 ");
                yylhs.value.as < Node * > () = new Node ("Length","");
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("","Period"));
                yylhs.value.as < Node * > ()->children.push_back(new Node("","length"));
}
#line 1488 "parser.tab.cc"
    break;

  case 52:
#line 445 "parser.yy"
                                             {
                printf("R41 ");
                yylhs.value.as < Node * > () = new Node("withArguementsExpMethodCall","");
                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("","period"));
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
}
#line 1503 "parser.tab.cc"
    break;

  case 53:
#line 456 "parser.yy"
     {
  printf("R42 ");
  yylhs.value.as < Node * > () = new Node("Integer",yystack_[0].value.as < std::string > ());
}
#line 1512 "parser.tab.cc"
    break;

  case 54:
#line 461 "parser.yy"
      {
  printf("R43 ");
  yylhs.value.as < Node * > () = new Node("True Statement","");
}
#line 1521 "parser.tab.cc"
    break;

  case 55:
#line 466 "parser.yy"
       {
  printf("R44 ");
  yylhs.value.as < Node * > () = new Node("False Statement","");
}
#line 1530 "parser.tab.cc"
    break;

  case 56:
#line 471 "parser.yy"
            {
  printf("R45 ");
  yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
}
#line 1539 "parser.tab.cc"
    break;

  case 57:
#line 476 "parser.yy"
      {
  printf("R46 ");
  yylhs.value.as < Node * > () = new Node("This","");
}
#line 1548 "parser.tab.cc"
    break;

  case 58:
#line 481 "parser.yy"
                                          {
  printf("R47 ");
  yylhs.value.as < Node * > () = new Node("Integer expression","");
  yylhs.value.as < Node * > ()->children.push_back(new Node("",""));
  yylhs.value.as < Node * > ()->children.push_back(new Node("","int"));
  yylhs.value.as < Node * > ()->children.push_back(new Node("","["));
  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(new Node("","]"));
}
#line 1562 "parser.tab.cc"
    break;

  case 59:
#line 491 "parser.yy"
                      {
  printf("R48 ");
  yylhs.value.as < Node * > () = new Node("New identifier","");
  yylhs.value.as < Node * > ()->children.push_back(new Node("","new"));
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
  yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
}
#line 1575 "parser.tab.cc"
    break;

  case 60:
#line 500 "parser.yy"
                                     {
  printf("R49 ");
  yylhs.value.as < Node * > () = new Node("WithOutArguements","");
  yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(new Node("","Period"));
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
  yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
}
#line 1589 "parser.tab.cc"
    break;

  case 61:
#line 510 "parser.yy"
                {
  printf("R50 ");
  yylhs.value.as < Node * > () = new Node("Not Exp","");
  yylhs.value.as < Node * > ()->children.push_back(new Node("","!"));
  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1600 "parser.tab.cc"
    break;

  case 62:
#line 517 "parser.yy"
                  {
  printf("R51 ");
  yylhs.value.as < Node * > () = new Node("EXPRESSION","");
  yylhs.value.as < Node * > ()->children.push_back(new Node("","("));
  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(new Node("",")"));
}
#line 1612 "parser.tab.cc"
    break;


#line 1616 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -62;

  const signed char parser::yytable_ninf_ = -32;

  const short
  parser::yypact_[] =
  {
     -11,   -24,     5,   -62,   -62,    33,   -62,   -24,    20,   -62,
      34,    30,   -62,   -62,    35,   -24,    49,    37,   -62,    54,
      39,   -62,   -18,    58,   -62,   457,   -62,     3,   -62,   -24,
     -62,    65,   -24,    64,   -62,   -62,    17,   -62,   -62,    61,
      52,    69,   -62,   -62,   -62,    70,   -18,    72,    81,   -24,
     -24,    79,    82,    88,   399,   -18,    87,   442,    -5,    92,
      93,   108,   442,    89,   415,   -62,    36,   -62,   442,   -62,
     425,   -62,    -5,   -62,   -62,   -13,    -5,   -62,   -62,   122,
      -5,    -5,    -5,    89,   432,    -5,   -62,    -5,    -5,   105,
     -62,   152,   109,   113,   404,    -5,    -5,    -5,    -5,   111,
      -5,    -5,    -5,    -5,    -5,    -5,   -21,   173,   194,   215,
      -5,   236,   257,   278,   112,   -62,    -5,   120,   404,   404,
     404,   299,   -62,   404,   404,   404,   404,   404,   404,   -62,
     114,   442,   442,   115,   320,   121,   119,   -62,   -62,   341,
     -62,   -62,   106,   102,   -62,   -62,   125,   -62,    -5,   -62,
     -62,   142,   362,   442,   -62,   383,   -62,    -5,   -62,   -62,
     -62
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,    38,     0,     1,     0,     0,     7,
       0,     5,     3,     8,     0,     0,     0,     0,     6,     0,
       0,    12,     0,    27,    26,     0,    13,     0,    16,     0,
      28,     0,     0,     0,    11,    14,     0,    10,    17,     0,
       0,     0,    25,     9,    15,     0,    22,     0,     0,     0,
       0,     0,    23,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,    13,     0,    29,    28,    24,     0,    31,
       0,    53,     0,    54,    55,     0,     0,    57,    56,     0,
       0,     0,     0,    14,     0,     0,    30,     0,     0,     0,
      32,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,     0,    46,    47,
      48,     0,    19,    49,    41,    42,    43,    44,    45,    51,
       0,     0,     0,     0,     0,     0,     0,    36,     4,     0,
      59,    50,     0,     0,    34,    35,     0,    18,     0,    58,
      60,     0,    39,     0,    20,     0,    52,     0,    33,    37,
      40
  };

  const short
  parser::yypgoto_[] =
  {
     -62,   -62,   -62,   -62,   -62,   143,    99,   -15,   134,    16,
     110,   -14,    -7,   -61,    -1,     4,     6
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    16,     8,     9,    25,    69,    27,    28,
      48,    29,    64,    65,    78,   151,   152
  };

  const short
  parser::yytable_[] =
  {
       5,    71,    72,    86,    26,     6,    11,    89,    32,    86,
      35,     1,    23,    24,    18,    37,   129,    92,    30,     4,
      12,    30,     4,    86,    30,     4,    22,     7,    39,    43,
       4,    41,    49,    73,    74,    75,    76,    77,     4,    63,
      22,    49,     7,    38,    10,    30,    87,    83,    52,    53,
      70,    88,    38,    66,    30,    84,    66,    14,    15,    17,
      19,    66,    20,    66,    79,    31,    21,    66,    33,    66,
     143,   144,    40,    42,    93,    44,    46,    22,    91,    45,
      47,    50,    94,    66,    23,    24,   107,   108,   109,    51,
      54,   111,   158,   112,   113,    55,    56,     4,    68,    80,
      81,   118,   119,   120,   121,   130,   123,   124,   125,   126,
     127,   128,    71,    72,   150,    82,   134,   114,   -31,   116,
     117,   142,   139,   122,   138,    95,    96,    97,   140,   145,
      66,    66,    98,   147,   148,   153,    99,   154,   100,   101,
     102,   103,   104,   105,    73,    74,    75,    76,    77,     4,
     156,    13,    66,    62,   155,    95,    96,    97,   106,    36,
     115,   160,    98,     0,     0,    67,     0,     0,   100,   101,
     102,   103,   104,   105,     0,     0,    95,    96,    97,     0,
       0,   131,     0,    98,     0,     0,     0,     0,   106,   100,
     101,   102,   103,   104,   105,     0,     0,    95,    96,    97,
       0,     0,   132,     0,    98,     0,     0,     0,     0,   106,
     100,   101,   102,   103,   104,   105,     0,     0,    95,    96,
      97,     0,     0,   133,     0,    98,     0,     0,     0,     0,
     106,   100,   101,   102,   103,   104,   105,     0,     0,    95,
      96,    97,     0,     0,     0,     0,    98,     0,     0,     0,
     135,   106,   100,   101,   102,   103,   104,   105,     0,     0,
      95,    96,    97,     0,     0,     0,   136,    98,     0,     0,
       0,     0,   106,   100,   101,   102,   103,   104,   105,     0,
       0,    95,    96,    97,     0,     0,     0,     0,    98,     0,
       0,     0,   137,   106,   100,   101,   102,   103,   104,   105,
       0,     0,    95,    96,    97,     0,     0,     0,   141,    98,
       0,     0,     0,     0,   106,   100,   101,   102,   103,   104,
     105,     0,     0,    95,    96,    97,     0,     0,     0,     0,
      98,     0,     0,     0,   146,   106,   100,   101,   102,   103,
     104,   105,     0,     0,    95,    96,    97,     0,     0,     0,
     149,    98,     0,     0,     0,     0,   106,   100,   101,   102,
     103,   104,   105,     0,     0,    95,    96,    97,     0,     0,
       0,     0,    98,     0,     0,   157,     0,   106,   100,   101,
     102,   103,   104,   105,     0,     0,    95,    96,    97,     0,
       0,     0,     0,    98,     0,     0,     0,   159,   106,   100,
     101,   102,   103,   104,   105,     0,     0,    95,    96,    97,
      57,     0,     0,     0,    98,     0,     0,     0,     0,   106,
     100,   101,   102,   103,   104,   105,    57,     0,    58,    23,
      24,    59,     0,    60,    61,     0,    57,    90,     0,     0,
     106,     0,     4,    57,    85,    23,    24,    59,     0,    60,
      61,     0,     0,    57,     0,    23,    24,    59,     4,    60,
      61,   110,    23,    24,    59,     0,    60,    61,     4,    34,
       0,     0,    23,    24,    59,     4,    60,    61,     0,     0,
      22,     0,     0,     0,     0,     4,     0,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4
  };

  const short
  parser::yycheck_[] =
  {
       1,     6,     7,    64,    19,     0,     7,    68,    22,    70,
      25,    22,    30,    31,    15,    12,    37,    30,    19,    43,
       0,    22,    43,    84,    25,    43,    23,    22,    29,    12,
      43,    32,    46,    38,    39,    40,    41,    42,    43,    54,
      23,    55,    22,    27,    11,    46,    10,    62,    49,    50,
      57,    15,    36,    54,    55,    62,    57,    23,    28,    24,
      11,    62,    25,    64,    58,    26,    12,    68,    10,    70,
     131,   132,     7,     9,    75,    14,     7,    23,    72,    27,
      10,     9,    76,    84,    30,    31,    80,    81,    82,     8,
      11,    85,   153,    87,    88,    13,     8,    43,    11,     7,
       7,    95,    96,    97,    98,   106,   100,   101,   102,   103,
     104,   105,     6,     7,     8,     7,   110,    12,    29,    10,
       7,     7,   116,    12,    12,     3,     4,     5,     8,    14,
     131,   132,    10,    12,    15,    33,    14,    12,    16,    17,
      18,    19,    20,    21,    38,    39,    40,    41,    42,    43,
       8,     8,   153,    54,   148,     3,     4,     5,    36,    25,
       8,   157,    10,    -1,    -1,    55,    -1,    -1,    16,    17,
      18,    19,    20,    21,    -1,    -1,     3,     4,     5,    -1,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    36,    16,
      17,    18,    19,    20,    21,    -1,    -1,     3,     4,     5,
      -1,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    36,
      16,    17,    18,    19,    20,    21,    -1,    -1,     3,     4,
       5,    -1,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,
      36,    16,    17,    18,    19,    20,    21,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      14,    36,    16,    17,    18,    19,    20,    21,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    -1,    -1,
      -1,    -1,    36,    16,    17,    18,    19,    20,    21,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    14,    36,    16,    17,    18,    19,    20,    21,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      -1,    -1,    -1,    -1,    36,    16,    17,    18,    19,    20,
      21,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    14,    36,    16,    17,    18,    19,
      20,    21,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    -1,    -1,    -1,    -1,    36,    16,    17,    18,
      19,    20,    21,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    13,    -1,    36,    16,    17,
      18,    19,    20,    21,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    14,    36,    16,
      17,    18,    19,    20,    21,    -1,    -1,     3,     4,     5,
      11,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    36,
      16,    17,    18,    19,    20,    21,    11,    -1,    29,    30,
      31,    32,    -1,    34,    35,    -1,    11,    12,    -1,    -1,
      36,    -1,    43,    11,    29,    30,    31,    32,    -1,    34,
      35,    -1,    -1,    11,    -1,    30,    31,    32,    43,    34,
      35,    29,    30,    31,    32,    -1,    34,    35,    43,    12,
      -1,    -1,    30,    31,    32,    43,    34,    35,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    43,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43
  };

  const signed char
  parser::yystos_[] =
  {
       0,    22,    45,    46,    43,    58,     0,    22,    48,    49,
      11,    58,     0,    49,    23,    28,    47,    24,    58,    11,
      25,    12,    23,    30,    31,    50,    51,    52,    53,    55,
      58,    26,    55,    10,    12,    51,    52,    12,    53,    58,
       7,    58,     9,    12,    14,    27,     7,    10,    54,    55,
       9,     8,    58,    58,    11,    13,     8,    11,    29,    32,
      34,    35,    50,    51,    56,    57,    58,    54,    11,    51,
      56,     6,     7,    38,    39,    40,    41,    42,    58,    60,
       7,     7,     7,    51,    56,    29,    57,    10,    15,    57,
      12,    60,    30,    58,    60,     3,     4,     5,    10,    14,
      16,    17,    18,    19,    20,    21,    36,    60,    60,    60,
      29,    60,    60,    60,    12,     8,    10,     7,    60,    60,
      60,    60,    12,    60,    60,    60,    60,    60,    60,    37,
      58,     8,     8,     8,    60,    14,     9,    14,    12,    60,
       8,     9,     7,    57,    57,    14,    14,    12,    15,     9,
       8,    59,    60,    33,    12,    60,     8,    13,    57,    14,
      59
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    45,    46,    47,    47,    48,    48,    49,
      49,    49,    49,    50,    50,    51,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,    17,     0,     2,     1,     2,     7,
       6,     6,     5,     1,     2,     3,     1,     2,    12,    11,
      13,    11,     0,     2,     4,     3,     1,     1,     1,     1,
       2,     1,     3,     7,     5,     5,     4,     7,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     6,     1,     1,     1,     1,     1,     5,     4,
       5,     2,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "PLUSOP", "MINUSOP", "MULTOP",
  "INT", "LP", "RP", "RSQUAREP", "LSQUAREP", "LBRACKET", "RBRACKET",
  "COMMA", "SEMICOLON", "EQUALS", "DIVISIONOP", "AND", "OR", "LESSER",
  "GREATER", "ASSIGNOP", "CLASS", "PUBLIC", "STATIC", "VOID", "MAIN",
  "STRING", "EXTENDS", "RETURN", "INTEGER", "BOOLEAN", "IF", "ELSE",
  "WHILE", "PRINT", "PERIOD", "LENGTH", "TRUE", "FALSE", "NEW", "NOT",
  "THIS", "IDENTIFIER", "$accept", "goal", "mainclass", "extends",
  "classList", "classDec", "varList", "varDec", "methodList", "methodDec",
  "identifierList", "type", "stateList", "statement", "identifier",
  "expList", "expression", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    29,    29,    30,    37,    58,    59,    66,    71,    77,
      89,   102,   115,   127,   132,   138,   145,   150,   156,   174,
     191,   211,   231,   232,   239,   248,   256,   261,   266,   270,
     275,   281,   282,   290,   302,   311,   321,   329,   341,   347,
     352,   359,   367,   375,   383,   391,   399,   407,   415,   423,
     430,   438,   445,   456,   461,   466,   471,   476,   481,   491,
     500,   510,   517
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
#line 2166 "parser.tab.cc"

