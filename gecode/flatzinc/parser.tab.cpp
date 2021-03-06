/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 41 "gecode/flatzinc/parser.yxx"

#define YYPARSE_PARAM parm
#define YYLEX_PARAM static_cast<ParserState*>(parm)->yyscanner
#include <gecode/flatzinc.hh>
#include <gecode/flatzinc/parser.hh>
#include <iostream>
#include <fstream>

#ifdef HAVE_MMAP
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#endif

using namespace std;

int yyparse(void*);
int yylex(YYSTYPE*, void* scanner);
int yylex_init (void** scanner);
int yylex_destroy (void* scanner);
int yyget_lineno (void* scanner);
void yyset_extra (void* user_defined ,void* yyscanner );

extern int yydebug;

using namespace Gecode;
using namespace Gecode::FlatZinc;

void yyerror(void* parm, const char *str) {
  ParserState* pp = static_cast<ParserState*>(parm);
  pp->err << "Error: " << str
          << " in line no. " << yyget_lineno(pp->yyscanner)
          << std::endl;
  pp->hadError = true;
}

void yyassert(ParserState* pp, bool cond, const char* str)
{
  if (!cond) {
    pp->err << "Error: " << str
            << " in line no. " << yyget_lineno(pp->yyscanner)
            << std::endl;
    pp->hadError = true;
  }
}

/*
 * The symbol tables
 *
 */

AST::Node* getArrayElement(ParserState* pp, string id, int offset,
                           bool annotation) {
  if (offset > 0) {
    SymbolEntry e;
    if (pp->symbols.get(id,e)) {
      switch (e.t) {
      case ST_INTVARARRAY:
        if (offset > pp->arrays[e.i])
          goto error;
        {
          std::string n;
          if (annotation) {
            std::ostringstream oss;
            oss << id << "[" << offset << "]";
            n = oss.str();
          }
          return new AST::IntVar(pp->arrays[e.i+offset],n);
        }
      case ST_BOOLVARARRAY:
        if (offset > pp->arrays[e.i])
          goto error;
        {
          std::string n;
          if (annotation) {
            std::ostringstream oss;
            oss << id << "[" << offset << "]";
            n = oss.str();
          }
          return new AST::BoolVar(pp->arrays[e.i+offset],n);
        }
      case ST_SETVARARRAY:
        if (offset > pp->arrays[e.i])
          goto error;
        {
          std::string n;
          if (annotation) {
            std::ostringstream oss;
            oss << id << "[" << offset << "]";
            n = oss.str();
          }
          return new AST::SetVar(pp->arrays[e.i+offset],n);
        }
      case ST_FLOATVARARRAY:
        if (offset > pp->arrays[e.i])
          goto error;
        {
          std::string n;
          if (annotation) {
            std::ostringstream oss;
            oss << id << "[" << offset << "]";
            n = oss.str();
          }          
          return new AST::FloatVar(pp->arrays[e.i+offset],n);
        }
      case ST_INTVALARRAY:
        if (offset > pp->arrays[e.i])
          goto error;
        return new AST::IntLit(pp->arrays[e.i+offset]);
      case ST_SETVALARRAY:
        if (offset > pp->arrays[e.i])
          goto error;
        return new AST::SetLit(pp->setvals[pp->arrays[e.i+1]+offset-1]);
      case ST_FLOATVALARRAY:
        if (offset > pp->arrays[e.i])
          goto error;
        return new AST::FloatLit(pp->floatvals[pp->arrays[e.i+1]+offset-1]);
      default:
        break;
      }
    }
  }
error:
  pp->err << "Error: array access to " << id << " invalid"
          << " in line no. "
          << yyget_lineno(pp->yyscanner) << std::endl;
  pp->hadError = true;
  return new AST::IntVar(0); // keep things consistent
}
AST::Node* getVarRefArg(ParserState* pp, string id, bool annotation = false) {
  SymbolEntry e;
  string n;
  if (annotation)
    n = id;
  if (pp->symbols.get(id, e)) {
    switch (e.t) {
    case ST_INTVAR: return new AST::IntVar(e.i,n);
    case ST_BOOLVAR: return new AST::BoolVar(e.i,n);
    case ST_SETVAR: return new AST::SetVar(e.i,n);
    case ST_FLOATVAR: return new AST::FloatVar(e.i,n);
    default: break;
    }
  }
  
  if (annotation)
    return new AST::Atom(id);
  pp->err << "Error: undefined variable " << id
          << " in line no. "
          << yyget_lineno(pp->yyscanner) << std::endl;
  pp->hadError = true;
  return new AST::IntVar(0); // keep things consistent
}

void addDomainConstraint(ParserState* pp, std::string id, AST::Node* var,
                         Option<AST::SetLit* >& dom) {
  if (!dom())
    return;
  AST::Array* args = new AST::Array(2);
  args->a[0] = var;
  args->a[1] = dom.some();
  pp->domainConstraints.push_back(new ConExpr(id, args, NULL));
}

void addDomainConstraint(ParserState* pp, AST::Node* var,
                         Option<std::pair<double,double>* > dom) {
  if (!dom())
    return;
  {
    AST::Array* args = new AST::Array(2);
    args->a[0] = new AST::FloatLit(dom.some()->first);
    args->a[1] = var;
    pp->domainConstraints.push_back(new ConExpr("float_le", args, NULL));
  }
  {
    AST::Array* args = new AST::Array(2);
    AST::FloatVar* fv = static_cast<AST::FloatVar*>(var);
    args->a[0] = new AST::FloatVar(fv->i,fv->n);
    args->a[1] = new AST::FloatLit(dom.some()->second);
    pp->domainConstraints.push_back(new ConExpr("float_le", args, NULL));
  }
  delete dom.some();
}

int getBaseIntVar(ParserState* pp, int i) {
  int base = i;
  IntVarSpec* ivs = static_cast<IntVarSpec*>(pp->intvars[base].second);
  while (ivs->alias) {
    base = ivs->i;
    ivs = static_cast<IntVarSpec*>(pp->intvars[base].second);
  }
  return base;
}
int getBaseBoolVar(ParserState* pp, int i) {
  int base = i;
  BoolVarSpec* ivs = static_cast<BoolVarSpec*>(pp->boolvars[base].second);
  while (ivs->alias) {
    base = ivs->i;
    ivs = static_cast<BoolVarSpec*>(pp->boolvars[base].second);
  }
  return base;
}
int getBaseFloatVar(ParserState* pp, int i) {
  int base = i;
  FloatVarSpec* ivs = static_cast<FloatVarSpec*>(pp->floatvars[base].second);
  while (ivs->alias) {
    base = ivs->i;
    ivs = static_cast<FloatVarSpec*>(pp->floatvars[base].second);
  }
  return base;
}
int getBaseSetVar(ParserState* pp, int i) {
  int base = i;
  SetVarSpec* ivs = static_cast<SetVarSpec*>(pp->setvars[base].second);
  while (ivs->alias) {
    base = ivs->i;
    ivs = static_cast<SetVarSpec*>(pp->setvars[base].second);
  }
  return base;
}

/*
 * Initialize the root gecode space
 *
 */

void initfg(ParserState* pp) {
  if (!pp->hadError)
    pp->fg->init(pp->intvars.size(),
                 pp->boolvars.size(),
                 pp->setvars.size(),
                 pp->floatvars.size());

  for (unsigned int i=0; i<pp->intvars.size(); i++) {
    if (!pp->hadError) {
      try {
        pp->fg->newIntVar(static_cast<IntVarSpec*>(pp->intvars[i].second));
      } catch (Gecode::FlatZinc::Error& e) {
        yyerror(pp, e.toString().c_str());
      }
    }
    delete pp->intvars[i].second;
    pp->intvars[i].second = NULL;
  }
  for (unsigned int i=0; i<pp->boolvars.size(); i++) {
    if (!pp->hadError) {
      try {
        pp->fg->newBoolVar(
          static_cast<BoolVarSpec*>(pp->boolvars[i].second));
      } catch (Gecode::FlatZinc::Error& e) {
        yyerror(pp, e.toString().c_str());
      }
    }
    delete pp->boolvars[i].second;
    pp->boolvars[i].second = NULL;
  }
  for (unsigned int i=0; i<pp->setvars.size(); i++) {
    if (!pp->hadError) {
      try {
        pp->fg->newSetVar(static_cast<SetVarSpec*>(pp->setvars[i].second));
      } catch (Gecode::FlatZinc::Error& e) {
        yyerror(pp, e.toString().c_str());
      }
    }      
    delete pp->setvars[i].second;
    pp->setvars[i].second = NULL;
  }
  for (unsigned int i=0; i<pp->floatvars.size(); i++) {
    if (!pp->hadError) {
      try {
        pp->fg->newFloatVar(
          static_cast<FloatVarSpec*>(pp->floatvars[i].second));
      } catch (Gecode::FlatZinc::Error& e) {
        yyerror(pp, e.toString().c_str());
      }
    }      
    delete pp->floatvars[i].second;
    pp->floatvars[i].second = NULL;
  }
  pp->fg->postConstraints(pp->domainConstraints);
  pp->fg->postConstraints(pp->constraints);
}

void fillPrinter(ParserState& pp, Gecode::FlatZinc::Printer& p) {
  p.init(pp.getOutput());
}

AST::Node* arrayOutput(AST::Call* ann) {
  AST::Array* a = NULL;
  
  if (ann->args->isArray()) {
    a = ann->args->getArray();
  } else {
    a = new AST::Array(ann->args);
  }
  
  std::ostringstream oss;
  
  oss << "array" << a->a.size() << "d(";
  for (unsigned int i=0; i<a->a.size(); i++) {
    AST::SetLit* s = a->a[i]->getSet();
    if (s->empty())
      oss << "{}, ";
    else if (s->interval)
      oss << s->min << ".." << s->max << ", ";
    else {
      oss << "{";
      for (unsigned int j=0; j<s->s.size(); j++) {
        oss << s->s[j];
        if (j<s->s.size()-1)
          oss << ",";
      }
      oss << "}, ";
    }
  }

  if (!ann->args->isArray()) {
    a->a[0] = NULL;
    delete a;
  }
  return new AST::String(oss.str());
}

/*
 * The main program
 *
 */

namespace Gecode { namespace FlatZinc {

  FlatZincSpace* parse(const std::string& filename, Printer& p, std::ostream& err,
                       FlatZincSpace* fzs, FznRnd* rnd) {
#ifdef HAVE_MMAP
    int fd;
    char* data;
    struct stat sbuf;
    fd = open(filename.c_str(), O_RDONLY);
    if (fd == -1) {
      err << "Cannot open file " << filename << endl;
      return NULL;
    }
    if (stat(filename.c_str(), &sbuf) == -1) {
      err << "Cannot stat file " << filename << endl;
      return NULL;      
    }
    data = (char*)mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd,0);
    if (data == (caddr_t)(-1)) {
      err << "Cannot mmap file " << filename << endl;
      return NULL;      
    }

    if (fzs == NULL) {
      fzs = new FlatZincSpace();
    }
    ParserState pp(data, sbuf.st_size, err, fzs);
#else
    std::ifstream file;
    file.open(filename.c_str());
    if (!file.is_open()) {
      err << "Cannot open file " << filename << endl;
      return NULL;
    }
    std::string s = string(istreambuf_iterator<char>(file),
                           istreambuf_iterator<char>());
    if (fzs == NULL) {
      fzs = new FlatZincSpace(rnd);
    }
    ParserState pp(s, err, fzs);
#endif
    yylex_init(&pp.yyscanner);
    yyset_extra(&pp, pp.yyscanner);
    // yydebug = 1;
    yyparse(&pp);
    fillPrinter(pp, p);
    
    if (pp.yyscanner)
      yylex_destroy(pp.yyscanner);
    return pp.hadError ? NULL : pp.fg;
  }

  FlatZincSpace* parse(std::istream& is, Printer& p, std::ostream& err,
                       FlatZincSpace* fzs, FznRnd* rnd) {
    std::string s = string(istreambuf_iterator<char>(is),
                           istreambuf_iterator<char>());

    if (fzs == NULL) {
      fzs = new FlatZincSpace(rnd);
    }
    ParserState pp(s, err, fzs);
    yylex_init(&pp.yyscanner);
    yyset_extra(&pp, pp.yyscanner);
    // yydebug = 1;
    yyparse(&pp);
    fillPrinter(pp, p);
    
    if (pp.yyscanner)
      yylex_destroy(pp.yyscanner);
    return pp.hadError ? NULL : pp.fg;
  }

  ParseResult parseWithSymbols(const std::string& filename, Printer& p, std::ostream& err,
                               FlatZincSpace* fzs) {
    ParseResult pr;
    pr.s = NULL;
#ifdef HAVE_MMAP
    int fd;
    char* data;
    struct stat sbuf;
    fd = open(filename.c_str(), O_RDONLY);
    if (fd == -1) {
      err << "Cannot open file " << filename << endl;
      return pr;
    }
    if (stat(filename.c_str(), &sbuf) == -1) {
      err << "Cannot stat file " << filename << endl;
      return pr;      
    }
    data = (char*)mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd,0);
    if (data == (caddr_t)(-1)) {
      err << "Cannot mmap file " << filename << endl;
      return pr;      
    }

    if (fzs == NULL) {
      fzs = new FlatZincSpace();
    }
    ParserState pp(data, sbuf.st_size, err, fzs);
#else
    std::ifstream file;
    file.open(filename.c_str());
    if (!file.is_open()) {
      err << "Cannot open file " << filename << endl;
      return pr;
    }
    std::string s = string(istreambuf_iterator<char>(file),
                           istreambuf_iterator<char>());
    if (fzs == NULL) {
      fzs = new FlatZincSpace();
    }
    ParserState pp(s, err, fzs);
#endif
    yylex_init(&pp.yyscanner);
    yyset_extra(&pp, pp.yyscanner);
    // yydebug = 1;
    yyparse(&pp);
    fillPrinter(pp, p);
    
    if (pp.yyscanner)
      yylex_destroy(pp.yyscanner);

    pr.s = pp.hadError ? NULL : pp.fg;
    pr.t = pp.symbols;
    pr.a = pp.arrays;
    return pr;
  }

  ParseResult parseWithSymbols(std::istream& is, Printer& p, std::ostream& err,
                               FlatZincSpace* fzs) {
    std::string s = string(istreambuf_iterator<char>(is),
                           istreambuf_iterator<char>());

    if (fzs == NULL) {
      fzs = new FlatZincSpace();
    }
    ParserState pp(s, err, fzs);
    yylex_init(&pp.yyscanner);
    yyset_extra(&pp, pp.yyscanner);
    // yydebug = 1;
    yyparse(&pp);
    fillPrinter(pp, p);
    
    if (pp.yyscanner)
      yylex_destroy(pp.yyscanner);
    ParseResult pr;
    pr.s = pp.hadError ? NULL : pp.fg;
    pr.t = pp.symbols;
    pr.a = pp.arrays;
    return pr;
  }

}}


/* Line 371 of yacc.c  */
#line 555 "gecode/flatzinc/parser.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_GECODE_FLATZINC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_GECODE_FLATZINC_PARSER_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FZ_INT_LIT = 258,
     FZ_BOOL_LIT = 259,
     FZ_FLOAT_LIT = 260,
     FZ_ID = 261,
     FZ_U_ID = 262,
     FZ_STRING_LIT = 263,
     FZ_VAR = 264,
     FZ_PAR = 265,
     FZ_ANNOTATION = 266,
     FZ_ANY = 267,
     FZ_ARRAY = 268,
     FZ_BOOL = 269,
     FZ_CASE = 270,
     FZ_COLONCOLON = 271,
     FZ_CONSTRAINT = 272,
     FZ_DEFAULT = 273,
     FZ_DOTDOT = 274,
     FZ_ELSE = 275,
     FZ_ELSEIF = 276,
     FZ_ENDIF = 277,
     FZ_ENUM = 278,
     FZ_FLOAT = 279,
     FZ_FUNCTION = 280,
     FZ_IF = 281,
     FZ_INCLUDE = 282,
     FZ_INT = 283,
     FZ_LET = 284,
     FZ_MAXIMIZE = 285,
     FZ_MINIMIZE = 286,
     FZ_OF = 287,
     FZ_SATISFY = 288,
     FZ_OUTPUT = 289,
     FZ_PREDICATE = 290,
     FZ_RECORD = 291,
     FZ_SET = 292,
     FZ_SHOW = 293,
     FZ_SHOWCOND = 294,
     FZ_SOLVE = 295,
     FZ_STRING = 296,
     FZ_TEST = 297,
     FZ_THEN = 298,
     FZ_TUPLE = 299,
     FZ_TYPE = 300,
     FZ_VARIANT_RECORD = 301,
     FZ_WHERE = 302
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 528 "gecode/flatzinc/parser.yxx"
 int iValue; char* sValue; bool bValue; double dValue;
         std::vector<int>* setValue;
         Gecode::FlatZinc::AST::SetLit* setLit;
         std::vector<double>* floatSetValue;
         std::vector<Gecode::FlatZinc::AST::SetLit>* setValueList;
         Gecode::FlatZinc::Option<Gecode::FlatZinc::AST::SetLit* > oSet;
         Gecode::FlatZinc::Option<std::pair<double,double>* > oPFloat;
         Gecode::FlatZinc::VarSpec* varSpec;
         Gecode::FlatZinc::Option<Gecode::FlatZinc::AST::Node*> oArg;
         std::vector<Gecode::FlatZinc::VarSpec*>* varSpecVec;
         Gecode::FlatZinc::Option<std::vector<Gecode::FlatZinc::VarSpec*>* > oVarSpecVec;
         Gecode::FlatZinc::AST::Node* arg;
         Gecode::FlatZinc::AST::Array* argVec;
       

/* Line 387 of yacc.c  */
#line 661 "gecode/flatzinc/parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void *parm);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_GECODE_FLATZINC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 688 "gecode/flatzinc/parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNRULES -- Number of states.  */
#define YYNSTATES  347

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    48,
       2,    55,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    10,    12,    15,    19,    20,    22,
      25,    29,    30,    32,    35,    39,    45,    46,    49,    51,
      55,    59,    66,    74,    77,    79,    81,    85,    87,    89,
      91,    95,    97,   101,   103,   105,   112,   119,   126,   135,
     142,   149,   156,   165,   179,   193,   207,   223,   239,   255,
     271,   289,   291,   293,   298,   299,   302,   304,   308,   309,
     311,   315,   317,   319,   324,   325,   328,   330,   334,   338,
     340,   342,   347,   348,   351,   353,   357,   361,   363,   365,
     370,   371,   374,   376,   380,   384,   385,   388,   389,   392,
     393,   396,   397,   400,   407,   411,   416,   418,   422,   426,
     428,   433,   435,   439,   443,   447,   448,   451,   453,   457,
     458,   461,   463,   467,   468,   471,   473,   477,   478,   481,
     483,   487,   489,   493,   495,   499,   500,   503,   505,   507,
     509,   511,   513,   518,   519,   522,   524,   528,   530,   532,
     534,   539,   541,   543,   544,   546,   549,   553,   558,   560,
     562,   566,   568,   571,   576,   577,   579,   581,   583,   585,
     587,   589,   594
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    62,    64,    98,    48,    -1,    -1,
      61,    -1,    66,    48,    -1,    61,    66,    48,    -1,    -1,
      63,    -1,    75,    48,    -1,    63,    75,    48,    -1,    -1,
      65,    -1,    97,    48,    -1,    65,    97,    48,    -1,    35,
       6,    49,    67,    50,    -1,    -1,    68,    79,    -1,    69,
      -1,    68,    51,    69,    -1,    70,    52,     6,    -1,    13,
      53,    72,    54,    32,    71,    -1,    13,    53,    72,    54,
      32,     9,    71,    -1,     9,    71,    -1,    71,    -1,    99,
      -1,    37,    32,    99,    -1,    14,    -1,    24,    -1,    73,
      -1,    72,    51,    73,    -1,    28,    -1,     3,    19,     3,
      -1,     6,    -1,     7,    -1,     9,    99,    52,    74,   119,
     113,    -1,     9,   100,    52,    74,   119,   113,    -1,     9,
     101,    52,    74,   119,   113,    -1,     9,    37,    32,    99,
      52,    74,   119,   113,    -1,    28,    52,    74,   119,    55,
     114,    -1,    24,    52,    74,   119,    55,   114,    -1,    14,
      52,    74,   119,    55,   114,    -1,    37,    32,    28,    52,
      74,   119,    55,   114,    -1,    13,    53,     3,    19,     3,
      54,    32,     9,    99,    52,    74,   119,    93,    -1,    13,
      53,     3,    19,     3,    54,    32,     9,   100,    52,    74,
     119,    94,    -1,    13,    53,     3,    19,     3,    54,    32,
       9,   101,    52,    74,   119,    95,    -1,    13,    53,     3,
      19,     3,    54,    32,     9,    37,    32,    99,    52,    74,
     119,    96,    -1,    13,    53,     3,    19,     3,    54,    32,
      28,    52,    74,   119,    55,    53,   103,    54,    -1,    13,
      53,     3,    19,     3,    54,    32,    14,    52,    74,   119,
      55,    53,   105,    54,    -1,    13,    53,     3,    19,     3,
      54,    32,    24,    52,    74,   119,    55,    53,   107,    54,
      -1,    13,    53,     3,    19,     3,    54,    32,    37,    32,
      28,    52,    74,   119,    55,    53,   109,    54,    -1,     3,
      -1,    74,    -1,    74,    53,     3,    54,    -1,    -1,    78,
      79,    -1,    76,    -1,    78,    51,    76,    -1,    -1,    51,
      -1,    53,    77,    54,    -1,     5,    -1,    74,    -1,    74,
      53,     3,    54,    -1,    -1,    83,    79,    -1,    81,    -1,
      83,    51,    81,    -1,    53,    82,    54,    -1,     4,    -1,
      74,    -1,    74,    53,     3,    54,    -1,    -1,    87,    79,
      -1,    85,    -1,    87,    51,    85,    -1,    53,    86,    54,
      -1,   102,    -1,    74,    -1,    74,    53,     3,    54,    -1,
      -1,    91,    79,    -1,    89,    -1,    91,    51,    89,    -1,
      53,    90,    54,    -1,    -1,    55,    80,    -1,    -1,    55,
      88,    -1,    -1,    55,    84,    -1,    -1,    55,    92,    -1,
      17,     6,    49,   111,    50,   119,    -1,    40,   119,    33,
      -1,    40,   119,   118,   117,    -1,    28,    -1,    56,   103,
      57,    -1,     3,    19,     3,    -1,    14,    -1,    56,   106,
      79,    57,    -1,    24,    -1,     5,    19,     5,    -1,    56,
     103,    57,    -1,     3,    19,     3,    -1,    -1,   104,    79,
      -1,     3,    -1,   104,    51,     3,    -1,    -1,   106,    79,
      -1,     4,    -1,   106,    51,     4,    -1,    -1,   108,    79,
      -1,     5,    -1,   108,    51,     5,    -1,    -1,   110,    79,
      -1,   102,    -1,   110,    51,   102,    -1,   112,    -1,   111,
      51,   112,    -1,   114,    -1,    53,   115,    54,    -1,    -1,
      55,   114,    -1,     4,    -1,     3,    -1,     5,    -1,   102,
      -1,    74,    -1,    74,    53,   114,    54,    -1,    -1,   116,
      79,    -1,   114,    -1,   116,    51,   114,    -1,    74,    -1,
       3,    -1,     5,    -1,    74,    53,     3,    54,    -1,    31,
      -1,    30,    -1,    -1,   120,    -1,    16,   121,    -1,   120,
      16,   121,    -1,     6,    49,   122,    50,    -1,   123,    -1,
     121,    -1,   122,    51,   121,    -1,   125,    -1,    53,    54,
      -1,    53,   122,   124,    54,    -1,    -1,    51,    -1,     4,
      -1,     3,    -1,     5,    -1,   102,    -1,    74,    -1,    74,
      53,   125,    54,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   630,   630,   632,   634,   637,   638,   640,   642,   645,
     646,   648,   650,   653,   654,   661,   664,   666,   669,   670,
     673,   677,   678,   679,   680,   683,   685,   687,   688,   691,
     692,   695,   696,   702,   702,   705,   740,   775,   817,   853,
     862,   872,   881,   893,   963,  1029,  1100,  1168,  1189,  1209,
    1229,  1252,  1256,  1271,  1295,  1296,  1300,  1302,  1305,  1305,
    1307,  1311,  1313,  1328,  1351,  1352,  1356,  1358,  1362,  1366,
    1368,  1383,  1406,  1407,  1411,  1413,  1416,  1419,  1421,  1436,
    1459,  1460,  1464,  1466,  1469,  1474,  1475,  1480,  1481,  1486,
    1487,  1492,  1493,  1497,  1592,  1606,  1631,  1633,  1635,  1641,
    1643,  1656,  1658,  1667,  1669,  1676,  1677,  1681,  1683,  1688,
    1689,  1693,  1695,  1700,  1701,  1705,  1707,  1712,  1713,  1717,
    1719,  1727,  1729,  1733,  1735,  1740,  1741,  1745,  1747,  1749,
    1751,  1753,  1849,  1864,  1865,  1869,  1871,  1879,  1913,  1920,
    1927,  1953,  1954,  1962,  1963,  1967,  1969,  1973,  1977,  1981,
    1983,  1987,  1989,  1991,  1994,  1994,  1997,  1999,  2001,  2003,
    2005,  2111,  2122
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FZ_INT_LIT", "FZ_BOOL_LIT",
  "FZ_FLOAT_LIT", "FZ_ID", "FZ_U_ID", "FZ_STRING_LIT", "FZ_VAR", "FZ_PAR",
  "FZ_ANNOTATION", "FZ_ANY", "FZ_ARRAY", "FZ_BOOL", "FZ_CASE",
  "FZ_COLONCOLON", "FZ_CONSTRAINT", "FZ_DEFAULT", "FZ_DOTDOT", "FZ_ELSE",
  "FZ_ELSEIF", "FZ_ENDIF", "FZ_ENUM", "FZ_FLOAT", "FZ_FUNCTION", "FZ_IF",
  "FZ_INCLUDE", "FZ_INT", "FZ_LET", "FZ_MAXIMIZE", "FZ_MINIMIZE", "FZ_OF",
  "FZ_SATISFY", "FZ_OUTPUT", "FZ_PREDICATE", "FZ_RECORD", "FZ_SET",
  "FZ_SHOW", "FZ_SHOWCOND", "FZ_SOLVE", "FZ_STRING", "FZ_TEST", "FZ_THEN",
  "FZ_TUPLE", "FZ_TYPE", "FZ_VARIANT_RECORD", "FZ_WHERE", "';'", "'('",
  "')'", "','", "':'", "'['", "']'", "'='", "'{'", "'}'", "$accept",
  "model", "preddecl_items", "preddecl_items_head", "vardecl_items",
  "vardecl_items_head", "constraint_items", "constraint_items_head",
  "preddecl_item", "pred_arg_list", "pred_arg_list_head", "pred_arg",
  "pred_arg_type", "pred_arg_simple_type", "pred_array_init",
  "pred_array_init_arg", "var_par_id", "vardecl_item", "int_init",
  "int_init_list", "int_init_list_head", "list_tail",
  "int_var_array_literal", "float_init", "float_init_list",
  "float_init_list_head", "float_var_array_literal", "bool_init",
  "bool_init_list", "bool_init_list_head", "bool_var_array_literal",
  "set_init", "set_init_list", "set_init_list_head",
  "set_var_array_literal", "vardecl_int_var_array_init",
  "vardecl_bool_var_array_init", "vardecl_float_var_array_init",
  "vardecl_set_var_array_init", "constraint_item", "solve_item",
  "int_ti_expr_tail", "bool_ti_expr_tail", "float_ti_expr_tail",
  "set_literal", "int_list", "int_list_head", "bool_list",
  "bool_list_head", "float_list", "float_list_head", "set_literal_list",
  "set_literal_list_head", "flat_expr_list", "flat_expr",
  "non_array_expr_opt", "non_array_expr", "non_array_expr_list",
  "non_array_expr_list_head", "solve_expr", "minmax", "annotations",
  "annotations_head", "annotation", "annotation_list", "annotation_expr",
  "annotation_list_tail", "ann_non_array_expr", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    59,    40,
      41,    44,    58,    91,    93,    61,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    70,    70,    70,    70,    71,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    81,    81,    81,    82,    82,    83,    83,    84,    85,
      85,    85,    86,    86,    87,    87,    88,    89,    89,    89,
      90,    90,    91,    91,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    98,    98,    99,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   114,
     114,   114,   114,   115,   115,   116,   116,   117,   117,   117,
     117,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   125
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     1,     2,     3,     0,     1,     2,
       3,     0,     1,     2,     3,     5,     0,     2,     1,     3,
       3,     6,     7,     2,     1,     1,     3,     1,     1,     1,
       3,     1,     3,     1,     1,     6,     6,     6,     8,     6,
       6,     6,     8,    13,    13,    13,    15,    15,    15,    15,
      17,     1,     1,     4,     0,     2,     1,     3,     0,     1,
       3,     1,     1,     4,     0,     2,     1,     3,     3,     1,
       1,     4,     0,     2,     1,     3,     3,     1,     1,     4,
       0,     2,     1,     3,     3,     0,     2,     0,     2,     0,
       2,     0,     2,     6,     3,     4,     1,     3,     3,     1,
       4,     1,     3,     3,     3,     0,     2,     1,     3,     0,
       2,     1,     3,     0,     2,     1,     3,     0,     2,     1,
       3,     1,     3,     1,     3,     0,     2,     1,     1,     1,
       1,     1,     4,     0,     2,     1,     3,     1,     1,     1,
       4,     1,     1,     0,     1,     2,     3,     4,     1,     1,
       3,     1,     2,     4,     0,     1,     1,     1,     1,     1,
       1,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     7,     4,     0,     0,     1,     0,     0,
       0,     0,     0,     0,    11,     8,     0,     0,     5,    16,
       0,     0,    99,   101,    96,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       9,     6,     0,     0,    27,    28,     0,   105,     0,    58,
      18,     0,    24,    25,     0,     0,     0,   107,   111,     0,
      58,    58,     0,     0,     0,     0,    33,    34,   143,   143,
     143,     0,     0,   143,     0,     0,    13,    10,    23,     0,
       0,    15,    59,    17,     0,    98,   102,     0,    97,    59,
     106,    59,     0,   143,   143,   143,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     2,    14,     0,    31,     0,
      29,    26,    19,    20,     0,   108,   112,   100,   125,   125,
     125,     0,   157,   156,   158,    33,   162,     0,   105,   160,
     159,   145,   148,   151,     0,     0,     0,     0,   143,   128,
     127,   129,   133,   131,   130,     0,   121,   123,   142,   141,
      94,     0,     0,     0,     0,   143,     0,    35,    36,    37,
       0,     0,     0,   152,   149,   154,     0,     0,    41,   146,
      40,    39,     0,   135,     0,    58,     0,   143,     0,   138,
     139,   137,    95,    32,    30,     0,   125,   126,     0,   104,
       0,   155,     0,   103,     0,     0,   124,    59,   134,     0,
      93,   122,     0,     0,    21,    38,     0,     0,     0,     0,
       0,   147,     0,   150,   153,   161,    42,   136,   132,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,     0,     0,   143,   143,   143,     0,     0,   143,
     143,   143,     0,     0,     0,     0,     0,    85,    87,    89,
       0,     0,     0,   143,   143,     0,    43,     0,    44,     0,
      45,   109,   113,   105,     0,    91,    54,    86,    72,    88,
      64,    90,     0,    58,   115,     0,    58,     0,     0,     0,
      46,    51,    52,    56,     0,    58,    69,    70,    74,     0,
      58,    61,    62,    66,     0,    58,    48,   110,    49,    59,
     114,    47,   117,    80,    92,     0,    60,    59,    55,     0,
      76,    59,    73,     0,    68,    59,    65,   116,     0,   119,
       0,    58,    78,    82,     0,    58,    77,     0,    57,     0,
      75,     0,    67,    50,    59,   118,     0,    84,    59,    81,
      53,    71,    63,   120,     0,    83,    79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    14,    15,    36,    37,     5,    48,
      49,    50,    51,    52,   109,   110,   143,    16,   283,   284,
     285,    83,   267,   293,   294,   295,   271,   288,   289,   290,
     269,   323,   324,   325,   304,   256,   258,   260,   280,    38,
      74,    53,    28,    29,   144,    59,    60,   272,    61,   275,
     276,   320,   321,   145,   146,   157,   147,   174,   175,   182,
     151,    98,    99,   164,   165,   132,   192,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
     -25,    13,    30,   253,   -25,   -20,   -13,  -123,   102,    -7,
       6,    18,    38,    87,   108,   253,    79,    81,  -123,    84,
     116,   118,  -123,  -123,  -123,   113,   111,    91,    95,   101,
     161,   126,   126,   126,   149,   173,   140,   108,   137,   138,
    -123,  -123,   217,   134,  -123,  -123,   157,   185,   142,   139,
    -123,   146,  -123,  -123,   188,   194,    78,  -123,  -123,   147,
     152,   154,   126,   126,   126,   189,  -123,  -123,   191,   191,
     191,   158,   160,   191,   163,   170,  -123,  -123,  -123,    56,
      78,  -123,    84,  -123,   211,  -123,  -123,   171,  -123,   218,
    -123,   220,   172,   191,   191,   191,   223,    35,   179,   216,
     181,   187,   126,   169,   119,  -123,  -123,   208,  -123,    28,
    -123,  -123,  -123,  -123,   126,  -123,  -123,  -123,   192,   192,
     192,   186,   224,  -123,  -123,   197,  -123,    46,   185,   196,
    -123,  -123,  -123,  -123,    57,    35,    57,    57,   191,   224,
    -123,  -123,    57,   200,  -123,   106,  -123,  -123,  -123,  -123,
    -123,   156,   255,    56,   227,   191,    57,  -123,  -123,  -123,
     228,   258,    35,  -123,  -123,   212,   214,    19,  -123,  -123,
    -123,  -123,   210,  -123,   221,   231,    57,   191,   169,  -123,
    -123,   225,  -123,  -123,  -123,   114,   192,  -123,    20,  -123,
     117,    35,   229,  -123,   232,    57,  -123,    57,  -123,   233,
    -123,  -123,   271,   217,  -123,  -123,   141,   236,   237,   239,
     247,  -123,    35,  -123,  -123,  -123,  -123,  -123,  -123,   238,
    -123,   261,   242,   243,   244,   126,   126,   126,   257,  -123,
      78,   126,   126,   126,   191,   191,   191,   245,   246,   191,
     191,   191,   248,   249,   250,   126,   126,   251,   254,   256,
     259,   260,   262,   191,   191,   263,  -123,   264,  -123,   265,
    -123,   295,   296,   185,   266,   267,    62,  -123,    88,  -123,
     177,  -123,   269,   154,  -123,   270,   268,   272,   274,   275,
    -123,  -123,   276,  -123,   277,   279,  -123,   280,  -123,   278,
     283,  -123,   282,  -123,   284,   285,  -123,  -123,  -123,   297,
    -123,  -123,    17,    11,  -123,   305,  -123,    62,  -123,   307,
    -123,    88,  -123,   311,  -123,   177,  -123,  -123,   224,  -123,
     286,   288,   289,  -123,   287,   292,  -123,   290,  -123,   291,
    -123,   293,  -123,  -123,    17,  -123,   317,  -123,    11,  -123,
    -123,  -123,  -123,  -123,   294,  -123,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   321,  -123,
    -123,   273,  -123,   -37,  -123,   184,   -31,   331,    42,  -123,
    -123,   -57,  -123,   -15,  -123,  -123,  -123,    39,  -123,  -123,
    -123,    14,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   314,
    -123,     0,   148,   150,   -90,  -122,  -123,  -123,    92,  -123,
    -123,  -123,  -123,  -123,   180,  -108,  -121,  -123,  -123,  -123,
    -123,    16,  -123,   -88,   195,  -123,  -123,   193
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      68,    69,    70,    90,    92,    78,   166,   130,    27,   131,
       1,   158,   159,   168,   318,   170,   171,    66,    67,     6,
     318,   173,   122,   123,   124,    66,    67,   126,    18,   206,
       7,    93,    94,    95,   207,   187,    19,   130,   122,   123,
     124,   125,    67,   126,   208,   130,    30,   169,   209,   122,
     123,   124,   125,    67,   126,   199,    87,   210,    31,   107,
     139,   140,   141,    66,    67,   281,   129,   128,    66,    67,
      32,   138,   130,   128,   216,   128,   217,   130,   205,   153,
     111,    20,   154,   155,   108,   100,   101,    20,   127,   104,
      33,   128,   286,    42,    66,    67,   129,    43,    44,   127,
     163,   130,   128,   213,   129,    20,    24,    21,    45,   118,
     119,   120,    24,   128,    57,    58,    22,    20,   198,    34,
     181,    46,   130,   203,   213,    35,    23,    40,    44,    41,
      24,   129,    66,    67,    47,    54,   129,    55,    45,    25,
      47,   277,    24,    62,    20,    56,    21,    63,   204,   148,
     149,    46,   150,    64,   172,    22,   177,   178,    26,   179,
     129,   180,    66,    67,    65,    23,   220,   211,   212,    24,
      47,   186,   139,   140,   141,    66,    67,    71,   221,    72,
      73,   129,   291,    66,    67,    76,    77,    79,    57,    80,
      82,    85,    81,   200,   234,   235,   236,    26,    84,    86,
     239,   240,   241,    89,    88,    91,   222,    97,    96,   103,
     102,   105,   319,   326,   253,   254,   297,   113,   106,   300,
      20,   115,   142,   114,   116,   128,   121,   152,   308,   117,
     238,    44,   135,   312,   134,   282,   136,   287,   316,   292,
     160,    45,   137,   161,   343,    24,   162,   156,   326,   167,
     242,   243,   244,   176,    46,   247,   248,   249,   183,   185,
     188,   189,     8,   191,   335,   195,     9,    10,   339,   264,
     265,   193,   322,    47,   219,   196,   282,    11,   202,   228,
     287,    12,   197,   214,   292,   237,   215,   218,   225,   226,
      13,   227,   229,   230,   231,   232,   233,   245,   246,    58,
     332,   274,   317,   250,   251,   252,   255,   322,   327,   257,
     329,   259,   261,   262,   331,   263,   266,   268,   270,   299,
     344,   278,   279,   296,   298,    17,   301,   302,   303,   305,
     307,   306,   310,   309,   311,   313,   315,   184,   314,   334,
     333,   337,   336,   338,   340,   341,    39,   342,   346,   328,
     330,    75,   345,   273,   223,   112,   224,   190,   201,     0,
     194
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      31,    32,    33,    60,    61,    42,   128,    97,     8,    97,
      35,   119,   120,   134,     3,   136,   137,     6,     7,     6,
       3,   142,     3,     4,     5,     6,     7,     8,    48,     9,
       0,    62,    63,    64,    14,   156,    49,   127,     3,     4,
       5,     6,     7,     8,    24,   135,    53,   135,    28,     3,
       4,     5,     6,     7,     8,   176,    56,    37,    52,     3,
       3,     4,     5,     6,     7,     3,    97,    56,     6,     7,
      52,   102,   162,    56,   195,    56,   197,   167,   186,    51,
      80,     3,    54,   114,    28,    69,    70,     3,    53,    73,
      52,    56,     4,     9,     6,     7,   127,    13,    14,    53,
      54,   191,    56,   191,   135,     3,    28,     5,    24,    93,
      94,    95,    28,    56,     3,     4,    14,     3,   175,    32,
     151,    37,   212,     9,   212,    17,    24,    48,    14,    48,
      28,   162,     6,     7,    56,    19,   167,    19,    24,    37,
      56,   263,    28,    52,     3,    32,     5,    52,   185,    30,
      31,    37,    33,    52,   138,    14,    50,    51,    56,     3,
     191,     5,     6,     7,     3,    24,   203,    50,    51,    28,
      56,   155,     3,     4,     5,     6,     7,    28,    37,     6,
      40,   212,     5,     6,     7,    48,    48,    53,     3,    32,
      51,     3,    50,   177,   225,   226,   227,    56,    52,     5,
     231,   232,   233,    51,    57,    51,   206,    16,    19,    49,
      52,    48,   302,   303,   245,   246,   273,     6,    48,   276,
       3,     3,    53,    52,     4,    56,     3,    19,   285,    57,
     230,    14,    16,   290,    55,   266,    55,   268,   295,   270,
      54,    24,    55,    19,   334,    28,    49,    55,   338,    53,
     234,   235,   236,    53,    37,   239,   240,   241,     3,    32,
      32,     3,     9,    51,   321,    55,    13,    14,   325,   253,
     254,    57,   303,    56,     3,    54,   307,    24,    53,    32,
     311,    28,    51,    54,   315,    28,    54,    54,    52,    52,
      37,    52,    54,    32,    52,    52,    52,    52,    52,     4,
     315,     5,     5,    55,    55,    55,    55,   338,     3,    55,
       3,    55,    53,    53,     3,    53,    53,    53,    53,    51,
       3,    55,    55,    54,    54,     4,    54,    53,    53,    53,
      51,    54,    54,    53,    51,    53,    51,   153,    54,    51,
      54,    54,    53,    51,    54,    54,    15,    54,    54,   307,
     311,    37,   338,   261,   206,    82,   206,   162,   178,    -1,
     167
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    59,    60,    61,    66,     6,     0,     9,    13,
      14,    24,    28,    37,    62,    63,    75,    66,    48,    49,
       3,     5,    14,    24,    28,    37,    56,    99,   100,   101,
      53,    52,    52,    52,    32,    17,    64,    65,    97,    75,
      48,    48,     9,    13,    14,    24,    37,    56,    67,    68,
      69,    70,    71,    99,    19,    19,    32,     3,     4,   103,
     104,   106,    52,    52,    52,     3,     6,     7,    74,    74,
      74,    28,     6,    40,    98,    97,    48,    48,    71,    53,
      32,    50,    51,    79,    52,     3,     5,    99,    57,    51,
      79,    51,    79,    74,    74,    74,    19,    16,   119,   120,
     119,   119,    52,    49,   119,    48,    48,     3,    28,    72,
      73,    99,    69,     6,    52,     3,     4,    57,   119,   119,
     119,     3,     3,     4,     5,     6,     8,    53,    56,    74,
     102,   121,   123,   125,    55,    16,    55,    55,    74,     3,
       4,     5,    53,    74,   102,   111,   112,   114,    30,    31,
      33,   118,    19,    51,    54,    74,    55,   113,   113,   113,
      54,    19,    49,    54,   121,   122,   103,    53,   114,   121,
     114,   114,   119,   114,   115,   116,    53,    50,    51,     3,
       5,    74,   117,     3,    73,    32,   119,   114,    32,     3,
     122,    51,   124,    57,   125,    55,    54,    51,    79,   114,
     119,   112,    53,     9,    71,   113,     9,    14,    24,    28,
      37,    50,    51,   121,    54,    54,   114,   114,    54,     3,
      71,    37,    99,   100,   101,    52,    52,    52,    32,    54,
      32,    52,    52,    52,    74,    74,    74,    28,    99,    74,
      74,    74,   119,   119,   119,    52,    52,   119,   119,   119,
      55,    55,    55,    74,    74,    55,    93,    55,    94,    55,
      95,    53,    53,    53,   119,   119,    53,    80,    53,    88,
      53,    84,   105,   106,     5,   107,   108,   103,    55,    55,
      96,     3,    74,    76,    77,    78,     4,    74,    85,    86,
      87,     5,    74,    81,    82,    83,    54,    79,    54,    51,
      79,    54,    53,    53,    92,    53,    54,    51,    79,    53,
      54,    51,    79,    53,    54,    51,    79,     5,     3,   102,
     109,   110,    74,    89,    90,    91,   102,     3,    76,     3,
      85,     3,    81,    54,    51,    79,    53,    54,    51,    79,
      54,    54,    54,   102,     3,    89,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (parm, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, parm); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *parm)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, parm)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void *parm;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (parm);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *parm)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, parm)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void *parm;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parm);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, void *parm)
#else
static void
yy_reduce_print (yyvsp, yyrule, parm)
    YYSTYPE *yyvsp;
    int yyrule;
    void *parm;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , parm);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, parm); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *parm)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, parm)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    void *parm;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (parm);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *parm)
#else
int
yyparse (parm)
    void *parm;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 15:
/* Line 1787 of yacc.c  */
#line 662 "gecode/flatzinc/parser.yxx"
    { free((yyvsp[(2) - (5)].sValue)); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 674 "gecode/flatzinc/parser.yxx"
    { free((yyvsp[(3) - (3)].sValue)); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 684 "gecode/flatzinc/parser.yxx"
    { if ((yyvsp[(1) - (1)].oSet)()) delete (yyvsp[(1) - (1)].oSet).some(); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 686 "gecode/flatzinc/parser.yxx"
    { if ((yyvsp[(3) - (3)].oSet)()) delete (yyvsp[(3) - (3)].oSet).some(); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 706 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        bool print = (yyvsp[(5) - (6)].argVec)->hasAtom("output_var");
        bool introduced = (yyvsp[(5) - (6)].argVec)->hasAtom("var_is_introduced");
        bool funcDep = (yyvsp[(5) - (6)].argVec)->hasAtom("is_defined_var");
        yyassert(pp,
          pp->symbols.put((yyvsp[(4) - (6)].sValue), se_iv(pp->intvars.size())),
          "Duplicate symbol");
        if (print) {
          pp->output(std::string((yyvsp[(4) - (6)].sValue)), new AST::IntVar(pp->intvars.size()));
        } else {
          introduced = true;
        }
        if ((yyvsp[(6) - (6)].oArg)()) {
          AST::Node* arg = (yyvsp[(6) - (6)].oArg).some();
          if (arg->isInt()) {
            pp->intvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
              new IntVarSpec(arg->getInt(),introduced,funcDep)));
          } else if (arg->isIntVar()) {
            pp->intvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
              new IntVarSpec(Alias(arg->getIntVar()),introduced,funcDep)));
          } else {
            yyassert(pp, false, "Invalid var int initializer");
          }
          if (!pp->hadError)
            addDomainConstraint(pp, "int_in",
                                new AST::IntVar(pp->intvars.size()-1), (yyvsp[(2) - (6)].oSet));
          delete arg;
        } else {
          pp->intvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
            new IntVarSpec((yyvsp[(2) - (6)].oSet),introduced,funcDep)));
        }
        delete (yyvsp[(5) - (6)].argVec); free((yyvsp[(4) - (6)].sValue));
      }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 741 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        bool print = (yyvsp[(5) - (6)].argVec)->hasAtom("output_var");
        bool introduced = (yyvsp[(5) - (6)].argVec)->hasAtom("var_is_introduced");
        bool funcDep = (yyvsp[(5) - (6)].argVec)->hasAtom("is_defined_var");
        yyassert(pp,
          pp->symbols.put((yyvsp[(4) - (6)].sValue), se_bv(pp->boolvars.size())),
          "Duplicate symbol");
        if (print) {
          pp->output(std::string((yyvsp[(4) - (6)].sValue)), new AST::BoolVar(pp->boolvars.size()));
        } else {
          introduced = true;
        }
        if ((yyvsp[(6) - (6)].oArg)()) {
          AST::Node* arg = (yyvsp[(6) - (6)].oArg).some();
          if (arg->isBool()) {
            pp->boolvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
              new BoolVarSpec(arg->getBool(),introduced,funcDep)));
          } else if (arg->isBoolVar()) {
            pp->boolvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
              new BoolVarSpec(Alias(arg->getBoolVar()),introduced,funcDep)));
          } else {
            yyassert(pp, false, "Invalid var bool initializer");
          }
          if (!pp->hadError)
            addDomainConstraint(pp, "int_in",
                                new AST::BoolVar(pp->boolvars.size()-1), (yyvsp[(2) - (6)].oSet));
          delete arg;
        } else {
          pp->boolvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
            new BoolVarSpec((yyvsp[(2) - (6)].oSet),introduced,funcDep)));
        }
        delete (yyvsp[(5) - (6)].argVec); free((yyvsp[(4) - (6)].sValue));
      }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 776 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        bool print = (yyvsp[(5) - (6)].argVec)->hasAtom("output_var");
        bool introduced = (yyvsp[(5) - (6)].argVec)->hasAtom("var_is_introduced");
        bool funcDep = (yyvsp[(5) - (6)].argVec)->hasAtom("is_defined_var");
        yyassert(pp,
          pp->symbols.put((yyvsp[(4) - (6)].sValue), se_fv(pp->floatvars.size())),
          "Duplicate symbol");
        if (print) {
          pp->output(std::string((yyvsp[(4) - (6)].sValue)),
                     new AST::FloatVar(pp->floatvars.size()));
        } else {
          introduced = true;
        }
        if ((yyvsp[(6) - (6)].oArg)()) {
          AST::Node* arg = (yyvsp[(6) - (6)].oArg).some();
          if (arg->isFloat()) {
            pp->floatvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
              new FloatVarSpec(arg->getFloat(),introduced,funcDep)));
          } else if (arg->isFloatVar()) {
            pp->floatvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
              new FloatVarSpec(
                Alias(arg->getFloatVar()),introduced,funcDep)));
          } else {
            yyassert(pp, false, "Invalid var float initializer");
          }
          if (!pp->hadError && (yyvsp[(2) - (6)].oPFloat)()) {
            AST::FloatVar* fv = new AST::FloatVar(pp->floatvars.size()-1);
            addDomainConstraint(pp, fv, (yyvsp[(2) - (6)].oPFloat));
          }
          delete arg;
        } else {
          Option<std::pair<double,double> > dom =
            (yyvsp[(2) - (6)].oPFloat)() ? Option<std::pair<double,double> >::some(*(yyvsp[(2) - (6)].oPFloat).some())
                 : Option<std::pair<double,double> >::none();
          if ((yyvsp[(2) - (6)].oPFloat)()) delete (yyvsp[(2) - (6)].oPFloat).some();
          pp->floatvars.push_back(varspec((yyvsp[(4) - (6)].sValue),
            new FloatVarSpec(dom,introduced,funcDep)));
        }
        delete (yyvsp[(5) - (6)].argVec); free((yyvsp[(4) - (6)].sValue));
      }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 818 "gecode/flatzinc/parser.yxx"
    { 
        ParserState* pp = static_cast<ParserState*>(parm);
        bool print = (yyvsp[(7) - (8)].argVec)->hasAtom("output_var");
        bool introduced = (yyvsp[(7) - (8)].argVec)->hasAtom("var_is_introduced");
        bool funcDep = (yyvsp[(7) - (8)].argVec)->hasAtom("is_defined_var");
        yyassert(pp,
          pp->symbols.put((yyvsp[(6) - (8)].sValue), se_sv(pp->setvars.size())),
          "Duplicate symbol");
        if (print) {
          pp->output(std::string((yyvsp[(6) - (8)].sValue)), new AST::SetVar(pp->setvars.size()));
        } else {
          introduced = true;
        }
        if ((yyvsp[(8) - (8)].oArg)()) {
          AST::Node* arg = (yyvsp[(8) - (8)].oArg).some();
          if (arg->isSet()) {
            pp->setvars.push_back(varspec((yyvsp[(6) - (8)].sValue),
              new SetVarSpec(arg->getSet(),introduced,funcDep)));
          } else if (arg->isSetVar()) {
            pp->setvars.push_back(varspec((yyvsp[(6) - (8)].sValue),
              new SetVarSpec(Alias(arg->getSetVar()),introduced,funcDep)));
            delete arg;
          } else {
            yyassert(pp, false, "Invalid var set initializer");
            delete arg;
          }
          if (!pp->hadError)
            addDomainConstraint(pp, "set_subset",
                                new AST::SetVar(pp->setvars.size()-1), (yyvsp[(4) - (8)].oSet));
        } else {
          pp->setvars.push_back(varspec((yyvsp[(6) - (8)].sValue),
            new SetVarSpec((yyvsp[(4) - (8)].oSet),introduced,funcDep)));
        }
        delete (yyvsp[(7) - (8)].argVec); free((yyvsp[(6) - (8)].sValue));
      }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 854 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(6) - (6)].arg)->isInt(), "Invalid int initializer");
        yyassert(pp,
          pp->symbols.put((yyvsp[(3) - (6)].sValue), se_i((yyvsp[(6) - (6)].arg)->getInt())),
          "Duplicate symbol");
        delete (yyvsp[(4) - (6)].argVec); free((yyvsp[(3) - (6)].sValue));        
      }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 863 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(6) - (6)].arg)->isFloat(), "Invalid float initializer");
        pp->floatvals.push_back((yyvsp[(6) - (6)].arg)->getFloat());
        yyassert(pp,
          pp->symbols.put((yyvsp[(3) - (6)].sValue), se_f(pp->floatvals.size()-1)),
          "Duplicate symbol");
        delete (yyvsp[(4) - (6)].argVec); free((yyvsp[(3) - (6)].sValue));        
      }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 873 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(6) - (6)].arg)->isBool(), "Invalid bool initializer");
        yyassert(pp,
          pp->symbols.put((yyvsp[(3) - (6)].sValue), se_b((yyvsp[(6) - (6)].arg)->getBool())),
          "Duplicate symbol");
        delete (yyvsp[(4) - (6)].argVec); free((yyvsp[(3) - (6)].sValue));        
      }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 882 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(8) - (8)].arg)->isSet(), "Invalid set initializer");
        AST::SetLit* set = (yyvsp[(8) - (8)].arg)->getSet();
        pp->setvals.push_back(*set);
        yyassert(pp,
          pp->symbols.put((yyvsp[(5) - (8)].sValue), se_s(pp->setvals.size()-1)),
          "Duplicate symbol");
        delete set;
        delete (yyvsp[(6) - (8)].argVec); free((yyvsp[(5) - (8)].sValue));        
      }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 895 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(3) - (13)].iValue)==1, "Arrays must start at 1");
        if (!pp->hadError) {
          bool print = (yyvsp[(12) - (13)].argVec)->hasCall("output_array");
          vector<int> vars((yyvsp[(5) - (13)].iValue));
          if (!pp->hadError) {
            if ((yyvsp[(13) - (13)].oVarSpecVec)()) {
              vector<VarSpec*>* vsv = (yyvsp[(13) - (13)].oVarSpecVec).some();
              yyassert(pp, vsv->size() == static_cast<unsigned int>((yyvsp[(5) - (13)].iValue)),
                       "Initializer size does not match array dimension");
              if (!pp->hadError) {
                for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++) {
                  IntVarSpec* ivsv = static_cast<IntVarSpec*>((*vsv)[i]);
                  if (ivsv->alias) {
                    if (print)
                      static_cast<IntVarSpec*>(pp->intvars[ivsv->i].second)->introduced = false;
                    vars[i] = ivsv->i;
                  } else {
                    if (print)
                      ivsv->introduced = false;
                    vars[i] = pp->intvars.size();
                    pp->intvars.push_back(varspec((yyvsp[(11) - (13)].sValue), ivsv));
                  }
                  if (!pp->hadError && (yyvsp[(9) - (13)].oSet)()) {
                    Option<AST::SetLit*> opt =
                      Option<AST::SetLit*>::some(new AST::SetLit(*(yyvsp[(9) - (13)].oSet).some()));                    
                    addDomainConstraint(pp, "int_in",
                                        new AST::IntVar(vars[i]),
                                        opt);
                  }
                }
              }
              delete vsv;
            } else {
              if ((yyvsp[(5) - (13)].iValue)>0) {
                for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++) {
                  Option<AST::SetLit*> dom =
                    (yyvsp[(9) - (13)].oSet)() ? Option<AST::SetLit*>::some(new AST::SetLit((yyvsp[(9) - (13)].oSet).some()))
                         : Option<AST::SetLit*>::none();
                  IntVarSpec* ispec = new IntVarSpec(dom,!print,false);
                  vars[i] = pp->intvars.size();
                  pp->intvars.push_back(varspec((yyvsp[(11) - (13)].sValue), ispec));
                }
              }
              if ((yyvsp[(9) - (13)].oSet)()) delete (yyvsp[(9) - (13)].oSet).some();
            }
          }
          if (print) {
            AST::Array* a = new AST::Array();
            a->a.push_back(arrayOutput((yyvsp[(12) - (13)].argVec)->getCall("output_array")));
            AST::Array* output = new AST::Array();
            for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++)
              output->a.push_back(new AST::IntVar(vars[i]));
            a->a.push_back(output);
            a->a.push_back(new AST::String(")"));
            pp->output(std::string((yyvsp[(11) - (13)].sValue)), a);
          }
          int iva = pp->arrays.size();
          pp->arrays.push_back(vars.size());
          for (unsigned int i=0; i<vars.size(); i++)
            pp->arrays.push_back(vars[i]);
          yyassert(pp,
            pp->symbols.put((yyvsp[(11) - (13)].sValue), se_iva(iva)),
            "Duplicate symbol");
        }
        delete (yyvsp[(12) - (13)].argVec); free((yyvsp[(11) - (13)].sValue));
      }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 965 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        bool print = (yyvsp[(12) - (13)].argVec)->hasCall("output_array");
        yyassert(pp, (yyvsp[(3) - (13)].iValue)==1, "Arrays must start at 1");
        if (!pp->hadError) {
          vector<int> vars((yyvsp[(5) - (13)].iValue));
          if ((yyvsp[(13) - (13)].oVarSpecVec)()) {
            vector<VarSpec*>* vsv = (yyvsp[(13) - (13)].oVarSpecVec).some();
            yyassert(pp, vsv->size() == static_cast<unsigned int>((yyvsp[(5) - (13)].iValue)),
                     "Initializer size does not match array dimension");
            if (!pp->hadError) {
              for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++) {
                BoolVarSpec* bvsv = static_cast<BoolVarSpec*>((*vsv)[i]);
                if (bvsv->alias) {
                  if (print)
                    static_cast<BoolVarSpec*>(pp->boolvars[bvsv->i].second)->introduced = false;
                  vars[i] = bvsv->i;
                } else {
                  if (print)
                    bvsv->introduced = false;
                  vars[i] = pp->boolvars.size();
                  pp->boolvars.push_back(varspec((yyvsp[(11) - (13)].sValue), (*vsv)[i]));
                }
                if (!pp->hadError && (yyvsp[(9) - (13)].oSet)()) {
                  Option<AST::SetLit*> opt =
                    Option<AST::SetLit*>::some(new AST::SetLit(*(yyvsp[(9) - (13)].oSet).some()));                    
                  addDomainConstraint(pp, "int_in",
                                      new AST::BoolVar(vars[i]),
                                      opt);
                }
              }
            }
            delete vsv;
          } else {
            for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++) {
              Option<AST::SetLit*> dom =
                (yyvsp[(9) - (13)].oSet)() ? Option<AST::SetLit*>::some(new AST::SetLit((yyvsp[(9) - (13)].oSet).some()))
                     : Option<AST::SetLit*>::none();
              vars[i] = pp->boolvars.size();
              pp->boolvars.push_back(varspec((yyvsp[(11) - (13)].sValue),
                                       new BoolVarSpec(dom,!print,false)));
            }
            if ((yyvsp[(9) - (13)].oSet)()) delete (yyvsp[(9) - (13)].oSet).some();
          }
          if (print) {
            AST::Array* a = new AST::Array();
            a->a.push_back(arrayOutput((yyvsp[(12) - (13)].argVec)->getCall("output_array")));
            AST::Array* output = new AST::Array();
            for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++)
              output->a.push_back(new AST::BoolVar(vars[i]));
            a->a.push_back(output);
            a->a.push_back(new AST::String(")"));
            pp->output(std::string((yyvsp[(11) - (13)].sValue)), a);
          }
          int bva = pp->arrays.size();
          pp->arrays.push_back(vars.size());
          for (unsigned int i=0; i<vars.size(); i++)
            pp->arrays.push_back(vars[i]);
          yyassert(pp,
            pp->symbols.put((yyvsp[(11) - (13)].sValue), se_bva(bva)),
            "Duplicate symbol");
        }
        delete (yyvsp[(12) - (13)].argVec); free((yyvsp[(11) - (13)].sValue));
      }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 1032 "gecode/flatzinc/parser.yxx"
    { 
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(3) - (13)].iValue)==1, "Arrays must start at 1");
        if (!pp->hadError) {
          bool print = (yyvsp[(12) - (13)].argVec)->hasCall("output_array");
          vector<int> vars((yyvsp[(5) - (13)].iValue));
          if (!pp->hadError) {
            if ((yyvsp[(13) - (13)].oVarSpecVec)()) {
              vector<VarSpec*>* vsv = (yyvsp[(13) - (13)].oVarSpecVec).some();
              yyassert(pp, vsv->size() == static_cast<unsigned int>((yyvsp[(5) - (13)].iValue)),
                       "Initializer size does not match array dimension");
              if (!pp->hadError) {
                for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++) {
                  FloatVarSpec* ivsv = static_cast<FloatVarSpec*>((*vsv)[i]);
                  if (ivsv->alias) {
                    if (print)
                      static_cast<FloatVarSpec*>(pp->floatvars[ivsv->i].second)->introduced = false;
                    vars[i] = ivsv->i;
                  } else {
                    if (print)
                      ivsv->introduced = false;
                    vars[i] = pp->floatvars.size();
                    pp->floatvars.push_back(varspec((yyvsp[(11) - (13)].sValue), ivsv));
                  }
                  if (!pp->hadError && (yyvsp[(9) - (13)].oPFloat)()) {
                    Option<std::pair<double,double>*> opt =
                      Option<std::pair<double,double>*>::some(
                        new std::pair<double,double>(*(yyvsp[(9) - (13)].oPFloat).some()));
                    addDomainConstraint(pp, new AST::FloatVar(vars[i]),
                                        opt);
                  }
                }
              }
              delete vsv;
            } else {
              if ((yyvsp[(5) - (13)].iValue)>0) {
                Option<std::pair<double,double> > dom =
                  (yyvsp[(9) - (13)].oPFloat)() ? Option<std::pair<double,double> >::some(*(yyvsp[(9) - (13)].oPFloat).some())
                       : Option<std::pair<double,double> >::none();
                for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++) {
                  FloatVarSpec* ispec = new FloatVarSpec(dom,!print,false);
                  vars[i] = pp->floatvars.size();
                  pp->floatvars.push_back(varspec((yyvsp[(11) - (13)].sValue), ispec));
                }
              }
            }
          }
          if (print) {
            AST::Array* a = new AST::Array();
            a->a.push_back(arrayOutput((yyvsp[(12) - (13)].argVec)->getCall("output_array")));
            AST::Array* output = new AST::Array();
            for (int i=0; i<(yyvsp[(5) - (13)].iValue); i++)
              output->a.push_back(new AST::FloatVar(vars[i]));
            a->a.push_back(output);
            a->a.push_back(new AST::String(")"));
            pp->output(std::string((yyvsp[(11) - (13)].sValue)), a);
          }
          int fva = pp->arrays.size();
          pp->arrays.push_back(vars.size());
          for (unsigned int i=0; i<vars.size(); i++)
            pp->arrays.push_back(vars[i]);
          yyassert(pp,
            pp->symbols.put((yyvsp[(11) - (13)].sValue), se_fva(fva)),
            "Duplicate symbol");
        }
        if ((yyvsp[(9) - (13)].oPFloat)()) delete (yyvsp[(9) - (13)].oPFloat).some();
        delete (yyvsp[(12) - (13)].argVec); free((yyvsp[(11) - (13)].sValue));
      }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 1102 "gecode/flatzinc/parser.yxx"
    { 
        ParserState* pp = static_cast<ParserState*>(parm);
        bool print = (yyvsp[(14) - (15)].argVec)->hasCall("output_array");
        yyassert(pp, (yyvsp[(3) - (15)].iValue)==1, "Arrays must start at 1");
        if (!pp->hadError) {
          vector<int> vars((yyvsp[(5) - (15)].iValue));
          if ((yyvsp[(15) - (15)].oVarSpecVec)()) {
            vector<VarSpec*>* vsv = (yyvsp[(15) - (15)].oVarSpecVec).some();
            yyassert(pp, vsv->size() == static_cast<unsigned int>((yyvsp[(5) - (15)].iValue)),
                     "Initializer size does not match array dimension");
            if (!pp->hadError) {
              for (int i=0; i<(yyvsp[(5) - (15)].iValue); i++) {
                SetVarSpec* svsv = static_cast<SetVarSpec*>((*vsv)[i]);
                if (svsv->alias) {
                  if (print)
                    static_cast<SetVarSpec*>(pp->setvars[svsv->i].second)->introduced = false;
                  vars[i] = svsv->i;
                } else {
                  if (print)
                    svsv->introduced = false;
                  vars[i] = pp->setvars.size();
                  pp->setvars.push_back(varspec((yyvsp[(13) - (15)].sValue), (*vsv)[i]));
                }
                if (!pp->hadError && (yyvsp[(11) - (15)].oSet)()) {
                  Option<AST::SetLit*> opt =
                    Option<AST::SetLit*>::some(new AST::SetLit(*(yyvsp[(11) - (15)].oSet).some()));                    
                  addDomainConstraint(pp, "set_subset",
                                      new AST::SetVar(vars[i]),
                                      opt);
                }
              }
            }
            delete vsv;
          } else {
            if ((yyvsp[(5) - (15)].iValue)>0) {
              for (int i=0; i<(yyvsp[(5) - (15)].iValue); i++) {
                Option<AST::SetLit*> dom =
                  (yyvsp[(11) - (15)].oSet)() ? Option<AST::SetLit*>::some(new AST::SetLit((yyvsp[(11) - (15)].oSet).some()))
                        : Option<AST::SetLit*>::none();
                SetVarSpec* ispec = new SetVarSpec(dom,!print,false);
                vars[i] = pp->setvars.size();
                pp->setvars.push_back(varspec((yyvsp[(13) - (15)].sValue), ispec));
              }
              if ((yyvsp[(11) - (15)].oSet)()) delete (yyvsp[(11) - (15)].oSet).some();
            }
          }
          if (print) {
            AST::Array* a = new AST::Array();
            a->a.push_back(arrayOutput((yyvsp[(14) - (15)].argVec)->getCall("output_array")));
            AST::Array* output = new AST::Array();
            for (int i=0; i<(yyvsp[(5) - (15)].iValue); i++)
              output->a.push_back(new AST::SetVar(vars[i]));
            a->a.push_back(output);
            a->a.push_back(new AST::String(")"));
            pp->output(std::string((yyvsp[(13) - (15)].sValue)), a);
          }
          int sva = pp->arrays.size();
          pp->arrays.push_back(vars.size());
          for (unsigned int i=0; i<vars.size(); i++)
            pp->arrays.push_back(vars[i]);
          yyassert(pp,
            pp->symbols.put((yyvsp[(13) - (15)].sValue), se_sva(sva)),
            "Duplicate symbol");
        }
        delete (yyvsp[(14) - (15)].argVec); free((yyvsp[(13) - (15)].sValue));
      }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 1170 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(3) - (15)].iValue)==1, "Arrays must start at 1");
        yyassert(pp, (yyvsp[(14) - (15)].setValue)->size() == static_cast<unsigned int>((yyvsp[(5) - (15)].iValue)),
                 "Initializer size does not match array dimension");

        if (!pp->hadError) {
          int ia = pp->arrays.size();
          pp->arrays.push_back((yyvsp[(14) - (15)].setValue)->size());
          for (unsigned int i=0; i<(yyvsp[(14) - (15)].setValue)->size(); i++)
            pp->arrays.push_back((*(yyvsp[(14) - (15)].setValue))[i]);
          yyassert(pp,
            pp->symbols.put((yyvsp[(10) - (15)].sValue), se_ia(ia)),
            "Duplicate symbol");
        }
        delete (yyvsp[(14) - (15)].setValue);
        free((yyvsp[(10) - (15)].sValue));
        delete (yyvsp[(11) - (15)].argVec);
      }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 1191 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(3) - (15)].iValue)==1, "Arrays must start at 1");
        yyassert(pp, (yyvsp[(14) - (15)].setValue)->size() == static_cast<unsigned int>((yyvsp[(5) - (15)].iValue)),
                 "Initializer size does not match array dimension");
        if (!pp->hadError) {
          int ia = pp->arrays.size();
          pp->arrays.push_back((yyvsp[(14) - (15)].setValue)->size());
          for (unsigned int i=0; i<(yyvsp[(14) - (15)].setValue)->size(); i++)
            pp->arrays.push_back((*(yyvsp[(14) - (15)].setValue))[i]);
          yyassert(pp,
            pp->symbols.put((yyvsp[(10) - (15)].sValue), se_ba(ia)),
            "Duplicate symbol");
        }
        delete (yyvsp[(14) - (15)].setValue);
        free((yyvsp[(10) - (15)].sValue));
        delete (yyvsp[(11) - (15)].argVec);
      }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 1211 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(3) - (15)].iValue)==1, "Arrays must start at 1");
        yyassert(pp, (yyvsp[(14) - (15)].floatSetValue)->size() == static_cast<unsigned int>((yyvsp[(5) - (15)].iValue)),
                 "Initializer size does not match array dimension");
        if (!pp->hadError) {
          int fa = pp->arrays.size();
          pp->arrays.push_back((yyvsp[(14) - (15)].floatSetValue)->size());
          pp->arrays.push_back(pp->floatvals.size());
          for (unsigned int i=0; i<(yyvsp[(14) - (15)].floatSetValue)->size(); i++)
            pp->floatvals.push_back((*(yyvsp[(14) - (15)].floatSetValue))[i]);
          yyassert(pp,
            pp->symbols.put((yyvsp[(10) - (15)].sValue), se_fa(fa)),
            "Duplicate symbol");
        }
        delete (yyvsp[(14) - (15)].floatSetValue);
        delete (yyvsp[(11) - (15)].argVec); free((yyvsp[(10) - (15)].sValue));
      }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 1231 "gecode/flatzinc/parser.yxx"
    {
        ParserState* pp = static_cast<ParserState*>(parm);
        yyassert(pp, (yyvsp[(3) - (17)].iValue)==1, "Arrays must start at 1");
        yyassert(pp, (yyvsp[(16) - (17)].setValueList)->size() == static_cast<unsigned int>((yyvsp[(5) - (17)].iValue)),
                 "Initializer size does not match array dimension");
        if (!pp->hadError) {
          int sa = pp->arrays.size();
          pp->arrays.push_back((yyvsp[(16) - (17)].setValueList)->size());
          pp->arrays.push_back(pp->setvals.size());
          for (unsigned int i=0; i<(yyvsp[(16) - (17)].setValueList)->size(); i++)
            pp->setvals.push_back((*(yyvsp[(16) - (17)].setValueList))[i]);
          yyassert(pp,
            pp->symbols.put((yyvsp[(12) - (17)].sValue), se_sa(sa)),
            "Duplicate symbol");
        }

        delete (yyvsp[(16) - (17)].setValueList);
        delete (yyvsp[(13) - (17)].argVec); free((yyvsp[(12) - (17)].sValue));
      }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 1253 "gecode/flatzinc/parser.yxx"
    { 
        (yyval.varSpec) = new IntVarSpec((yyvsp[(1) - (1)].iValue),false,false);
      }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 1257 "gecode/flatzinc/parser.yxx"
    { 
        SymbolEntry e;
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->symbols.get((yyvsp[(1) - (1)].sValue), e) && e.t == ST_INTVAR)
          (yyval.varSpec) = new IntVarSpec(Alias(e.i),false,false);
        else {
          pp->err << "Error: undefined identifier " << (yyvsp[(1) - (1)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.varSpec) = new IntVarSpec(0,false,false); // keep things consistent
        }
        free((yyvsp[(1) - (1)].sValue));
      }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 1272 "gecode/flatzinc/parser.yxx"
    { 
        vector<int> v;
        SymbolEntry e;
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->symbols.get((yyvsp[(1) - (4)].sValue), e) && e.t == ST_INTVARARRAY) {
          yyassert(pp,(yyvsp[(3) - (4)].iValue) > 0 && (yyvsp[(3) - (4)].iValue) <= pp->arrays[e.i],
                   "array access out of bounds");
          if (!pp->hadError)
            (yyval.varSpec) = new IntVarSpec(Alias(pp->arrays[e.i+(yyvsp[(3) - (4)].iValue)]),false,false);
          else
            (yyval.varSpec) = new IntVarSpec(0,false,false); // keep things consistent
        } else {
          pp->err << "Error: undefined array identifier " << (yyvsp[(1) - (4)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.varSpec) = new IntVarSpec(0,false,false); // keep things consistent
        }
        free((yyvsp[(1) - (4)].sValue));
      }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 1295 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = new vector<VarSpec*>(0); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 1297 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(1) - (2)].varSpecVec); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 1301 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = new vector<VarSpec*>(1); (*(yyval.varSpecVec))[0] = (yyvsp[(1) - (1)].varSpec); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 1303 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(1) - (3)].varSpecVec); (yyval.varSpecVec)->push_back((yyvsp[(3) - (3)].varSpec)); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 1308 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(2) - (3)].varSpecVec); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 1312 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpec) = new FloatVarSpec((yyvsp[(1) - (1)].dValue),false,false); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 1314 "gecode/flatzinc/parser.yxx"
    { 
        SymbolEntry e;
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->symbols.get((yyvsp[(1) - (1)].sValue), e) && e.t == ST_FLOATVAR)
          (yyval.varSpec) = new FloatVarSpec(Alias(e.i),false,false);
        else {
          pp->err << "Error: undefined identifier " << (yyvsp[(1) - (1)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.varSpec) = new FloatVarSpec(0.0,false,false);
        }
        free((yyvsp[(1) - (1)].sValue));
      }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 1329 "gecode/flatzinc/parser.yxx"
    { 
        SymbolEntry e;
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->symbols.get((yyvsp[(1) - (4)].sValue), e) && e.t == ST_FLOATVARARRAY) {
          yyassert(pp,(yyvsp[(3) - (4)].iValue) > 0 && (yyvsp[(3) - (4)].iValue) <= pp->arrays[e.i],
                   "array access out of bounds");
          if (!pp->hadError)
            (yyval.varSpec) = new FloatVarSpec(Alias(pp->arrays[e.i+(yyvsp[(3) - (4)].iValue)]),false,false);
          else
            (yyval.varSpec) = new FloatVarSpec(0.0,false,false);
        } else {
          pp->err << "Error: undefined array identifier " << (yyvsp[(1) - (4)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.varSpec) = new FloatVarSpec(0.0,false,false);
        }
        free((yyvsp[(1) - (4)].sValue));
      }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 1351 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = new vector<VarSpec*>(0); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 1353 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(1) - (2)].varSpecVec); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 1357 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = new vector<VarSpec*>(1); (*(yyval.varSpecVec))[0] = (yyvsp[(1) - (1)].varSpec); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 1359 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(1) - (3)].varSpecVec); (yyval.varSpecVec)->push_back((yyvsp[(3) - (3)].varSpec)); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 1363 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(2) - (3)].varSpecVec); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 1367 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpec) = new BoolVarSpec((yyvsp[(1) - (1)].iValue),false,false); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 1369 "gecode/flatzinc/parser.yxx"
    { 
        SymbolEntry e;
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->symbols.get((yyvsp[(1) - (1)].sValue), e) && e.t == ST_BOOLVAR)
          (yyval.varSpec) = new BoolVarSpec(Alias(e.i),false,false);
        else {
          pp->err << "Error: undefined identifier " << (yyvsp[(1) - (1)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.varSpec) = new BoolVarSpec(false,false,false);
        }
        free((yyvsp[(1) - (1)].sValue));
      }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 1384 "gecode/flatzinc/parser.yxx"
    { 
        SymbolEntry e;
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->symbols.get((yyvsp[(1) - (4)].sValue), e) && e.t == ST_BOOLVARARRAY) {
          yyassert(pp,(yyvsp[(3) - (4)].iValue) > 0 && (yyvsp[(3) - (4)].iValue) <= pp->arrays[e.i],
                   "array access out of bounds");
          if (!pp->hadError)
            (yyval.varSpec) = new BoolVarSpec(Alias(pp->arrays[e.i+(yyvsp[(3) - (4)].iValue)]),false,false);
          else
            (yyval.varSpec) = new BoolVarSpec(false,false,false);
        } else {
          pp->err << "Error: undefined array identifier " << (yyvsp[(1) - (4)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.varSpec) = new BoolVarSpec(false,false,false);
        }
        free((yyvsp[(1) - (4)].sValue));
      }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 1406 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = new vector<VarSpec*>(0); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 1408 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(1) - (2)].varSpecVec); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 1412 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = new vector<VarSpec*>(1); (*(yyval.varSpecVec))[0] = (yyvsp[(1) - (1)].varSpec); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 1414 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(1) - (3)].varSpecVec); (yyval.varSpecVec)->push_back((yyvsp[(3) - (3)].varSpec)); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 1416 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(2) - (3)].varSpecVec); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 1420 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpec) = new SetVarSpec((yyvsp[(1) - (1)].setLit),false,false); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 1422 "gecode/flatzinc/parser.yxx"
    { 
        ParserState* pp = static_cast<ParserState*>(parm);
        SymbolEntry e;
        if (pp->symbols.get((yyvsp[(1) - (1)].sValue), e) && e.t == ST_SETVAR)
          (yyval.varSpec) = new SetVarSpec(Alias(e.i),false,false);
        else {
          pp->err << "Error: undefined identifier " << (yyvsp[(1) - (1)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.varSpec) = new SetVarSpec(Alias(0),false,false);
        }
        free((yyvsp[(1) - (1)].sValue));
      }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 1437 "gecode/flatzinc/parser.yxx"
    { 
        SymbolEntry e;
        ParserState* pp = static_cast<ParserState*>(parm);
        if (pp->symbols.get((yyvsp[(1) - (4)].sValue), e) && e.t == ST_SETVARARRAY) {
          yyassert(pp,(yyvsp[(3) - (4)].iValue) > 0 && (yyvsp[(3) - (4)].iValue) <= pp->arrays[e.i],
                   "array access out of bounds");
          if (!pp->hadError)
            (yyval.varSpec) = new SetVarSpec(Alias(pp->arrays[e.i+(yyvsp[(3) - (4)].iValue)]),false,false);
          else
            (yyval.varSpec) = new SetVarSpec(Alias(0),false,false);
        } else {
          pp->err << "Error: undefined array identifier " << (yyvsp[(1) - (4)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.varSpec) = new SetVarSpec(Alias(0),false,false);
        }
        free((yyvsp[(1) - (4)].sValue));
      }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 1459 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = new vector<VarSpec*>(0); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 1461 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(1) - (2)].varSpecVec); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 1465 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = new vector<VarSpec*>(1); (*(yyval.varSpecVec))[0] = (yyvsp[(1) - (1)].varSpec); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 1467 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(1) - (3)].varSpecVec); (yyval.varSpecVec)->push_back((yyvsp[(3) - (3)].varSpec)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 1470 "gecode/flatzinc/parser.yxx"
    { (yyval.varSpecVec) = (yyvsp[(2) - (3)].varSpecVec); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 1474 "gecode/flatzinc/parser.yxx"
    { (yyval.oVarSpecVec) = Option<vector<VarSpec*>* >::none(); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 1476 "gecode/flatzinc/parser.yxx"
    { (yyval.oVarSpecVec) = Option<vector<VarSpec*>* >::some((yyvsp[(2) - (2)].varSpecVec)); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 1480 "gecode/flatzinc/parser.yxx"
    { (yyval.oVarSpecVec) = Option<vector<VarSpec*>* >::none(); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 1482 "gecode/flatzinc/parser.yxx"
    { (yyval.oVarSpecVec) = Option<vector<VarSpec*>* >::some((yyvsp[(2) - (2)].varSpecVec)); }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 1486 "gecode/flatzinc/parser.yxx"
    { (yyval.oVarSpecVec) = Option<vector<VarSpec*>* >::none(); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 1488 "gecode/flatzinc/parser.yxx"
    { (yyval.oVarSpecVec) = Option<vector<VarSpec*>* >::some((yyvsp[(2) - (2)].varSpecVec)); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 1492 "gecode/flatzinc/parser.yxx"
    { (yyval.oVarSpecVec) = Option<vector<VarSpec*>* >::none(); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 1494 "gecode/flatzinc/parser.yxx"
    { (yyval.oVarSpecVec) = Option<vector<VarSpec*>* >::some((yyvsp[(2) - (2)].varSpecVec)); }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 1498 "gecode/flatzinc/parser.yxx"
    { 
        ParserState *pp = static_cast<ParserState*>(parm);
        if (!pp->hadError) {
          std::string cid((yyvsp[(2) - (6)].sValue));
          if (cid=="int_eq" && (yyvsp[(4) - (6)].argVec)->a[0]->isIntVar() && (yyvsp[(4) - (6)].argVec)->a[1]->isIntVar()) {
            int base0 = getBaseIntVar(pp,(yyvsp[(4) - (6)].argVec)->a[0]->getIntVar());
            int base1 = getBaseIntVar(pp,(yyvsp[(4) - (6)].argVec)->a[1]->getIntVar());
            if (base0 > base1) {
              std::swap(base0, base1);
            }
            if (base0==base1) {
              // do nothing, already aliased
            } else {
              IntVarSpec* ivs1 = static_cast<IntVarSpec*>(pp->intvars[base1].second);
              ivs1->alias = true;
              ivs1->i = base0;
              if (ivs1->domain()) {
                AST::SetLit* sl = new AST::SetLit(ivs1->domain.some()->getSet());
                Option<AST::SetLit*> newdom = Option<AST::SetLit*>::some(sl);
                addDomainConstraint(pp, "int_in",
                                    new AST::IntVar(base0), newdom);
                ivs1->domain = Option<AST::SetLit*>::none();
              }
            }
          } else if (cid=="bool_eq" && (yyvsp[(4) - (6)].argVec)->a[0]->isBoolVar() && (yyvsp[(4) - (6)].argVec)->a[1]->isBoolVar()) {
            int base0 = getBaseBoolVar(pp,(yyvsp[(4) - (6)].argVec)->a[0]->getBoolVar());
            int base1 = getBaseBoolVar(pp,(yyvsp[(4) - (6)].argVec)->a[1]->getBoolVar());
            if (base0 > base1) {
              std::swap(base0, base1);
            }
            if (base0==base1) {
              // do nothing, already aliased
            } else {
              BoolVarSpec* ivs1 = static_cast<BoolVarSpec*>(pp->boolvars[base1].second);
              ivs1->alias = true;
              ivs1->i = base0;
              if (ivs1->domain()) {
                AST::SetLit* sl = new AST::SetLit(ivs1->domain.some()->getSet());
                Option<AST::SetLit*> newdom = Option<AST::SetLit*>::some(sl);
                addDomainConstraint(pp, "bool_in",
                                    new AST::BoolVar(base0), newdom);
                ivs1->domain = Option<AST::SetLit*>::none();
              }
            }
          } else if (cid=="float_eq" && (yyvsp[(4) - (6)].argVec)->a[0]->isFloatVar() && (yyvsp[(4) - (6)].argVec)->a[1]->isFloatVar()) {
            int base0 = getBaseFloatVar(pp,(yyvsp[(4) - (6)].argVec)->a[0]->getFloatVar());
            int base1 = getBaseFloatVar(pp,(yyvsp[(4) - (6)].argVec)->a[1]->getFloatVar());
            if (base0 > base1) {
              std::swap(base0, base1);
            }
            if (base0==base1) {
              // do nothing, already aliased
            } else {
              FloatVarSpec* ivs1 = static_cast<FloatVarSpec*>(pp->floatvars[base1].second);
              ivs1->alias = true;
              ivs1->i = base0;
              if (ivs1->domain()) {
                addDomainConstraint(pp, new AST::FloatVar(base0), Option<std::pair<double,double>* >::some(&ivs1->domain.some()));
                ivs1->domain = Option<std::pair<double,double> >::none();
              }
            }
          } else if (cid=="set_eq" && (yyvsp[(4) - (6)].argVec)->a[0]->isSetVar() && (yyvsp[(4) - (6)].argVec)->a[1]->isSetVar()) {
            int base0 = getBaseSetVar(pp,(yyvsp[(4) - (6)].argVec)->a[0]->getSetVar());
            int base1 = getBaseSetVar(pp,(yyvsp[(4) - (6)].argVec)->a[1]->getSetVar());
            if (base0 > base1) {
              std::swap(base0, base1);
            }
            if (base0==base1) {
              // do nothing, already aliased
            } else {
              SetVarSpec* ivs1 = static_cast<SetVarSpec*>(pp->setvars[base1].second);
              ivs1->alias = true;
              ivs1->i = base0;
              if (ivs1->upperBound()) {
                AST::SetLit* sl = new AST::SetLit(ivs1->upperBound.some()->getSet());
                Option<AST::SetLit*> newdom = Option<AST::SetLit*>::some(sl);
                addDomainConstraint(pp, "set_subset",
                                    new AST::SetVar(base0), newdom);
                ivs1->upperBound = Option<AST::SetLit*>::none();
              }
            }
          } else if ( (cid=="int_le" || cid=="int_lt" || cid=="int_ge" || cid=="int_gt"  ||
                       cid=="int_eq" || cid=="int_ne") &&
                      ((yyvsp[(4) - (6)].argVec)->a[0]->isInt() || (yyvsp[(4) - (6)].argVec)->a[1]->isInt()) ) {
            pp->domainConstraints.push_back(new ConExpr((yyvsp[(2) - (6)].sValue), (yyvsp[(4) - (6)].argVec), (yyvsp[(6) - (6)].argVec)));
          } else if ( cid=="set_in" && ((yyvsp[(4) - (6)].argVec)->a[0]->isSet() || (yyvsp[(4) - (6)].argVec)->a[1]->isSet()) ) {
            pp->domainConstraints.push_back(new ConExpr((yyvsp[(2) - (6)].sValue), (yyvsp[(4) - (6)].argVec), (yyvsp[(6) - (6)].argVec)));
          } else {
            pp->constraints.push_back(new ConExpr((yyvsp[(2) - (6)].sValue), (yyvsp[(4) - (6)].argVec), (yyvsp[(6) - (6)].argVec)));
          }
        }
        free((yyvsp[(2) - (6)].sValue));
      }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 1593 "gecode/flatzinc/parser.yxx"
    { 
        ParserState *pp = static_cast<ParserState*>(parm);
        initfg(pp);
        if (!pp->hadError) {
          try {
            pp->fg->solve((yyvsp[(2) - (3)].argVec));
          } catch (Gecode::FlatZinc::Error& e) {
            yyerror(pp, e.toString().c_str());
          }
        } else {
          delete (yyvsp[(2) - (3)].argVec);
        }
      }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 1607 "gecode/flatzinc/parser.yxx"
    { 
        ParserState *pp = static_cast<ParserState*>(parm);
        initfg(pp);
        if (!pp->hadError) {
          try {
            int v = (yyvsp[(4) - (4)].iValue) < 0 ? (-(yyvsp[(4) - (4)].iValue)-1) : (yyvsp[(4) - (4)].iValue);
            bool vi = (yyvsp[(4) - (4)].iValue) >= 0;
            if ((yyvsp[(3) - (4)].bValue))
              pp->fg->minimize(v,vi,(yyvsp[(2) - (4)].argVec));
            else
              pp->fg->maximize(v,vi,(yyvsp[(2) - (4)].argVec));
          } catch (Gecode::FlatZinc::Error& e) {
            yyerror(pp, e.toString().c_str());
          }
        } else {
          delete (yyvsp[(2) - (4)].argVec);
        }
      }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 1632 "gecode/flatzinc/parser.yxx"
    { (yyval.oSet) = Option<AST::SetLit* >::none(); }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 1634 "gecode/flatzinc/parser.yxx"
    { (yyval.oSet) = Option<AST::SetLit* >::some(new AST::SetLit(*(yyvsp[(2) - (3)].setValue))); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 1636 "gecode/flatzinc/parser.yxx"
    { 
        (yyval.oSet) = Option<AST::SetLit* >::some(new AST::SetLit((yyvsp[(1) - (3)].iValue), (yyvsp[(3) - (3)].iValue)));
      }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 1642 "gecode/flatzinc/parser.yxx"
    { (yyval.oSet) = Option<AST::SetLit* >::none(); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 1644 "gecode/flatzinc/parser.yxx"
    { bool haveTrue = false;
        bool haveFalse = false;
        for (int i=(yyvsp[(2) - (4)].setValue)->size(); i--;) {
          haveTrue |= ((*(yyvsp[(2) - (4)].setValue))[i] == 1);
          haveFalse |= ((*(yyvsp[(2) - (4)].setValue))[i] == 0);
        }
        delete (yyvsp[(2) - (4)].setValue);
        (yyval.oSet) = Option<AST::SetLit* >::some(
          new AST::SetLit(!haveFalse,haveTrue));
      }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 1657 "gecode/flatzinc/parser.yxx"
    { (yyval.oPFloat) = Option<std::pair<double,double>* >::none(); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 1659 "gecode/flatzinc/parser.yxx"
    { std::pair<double,double>* dom = new std::pair<double,double>((yyvsp[(1) - (3)].dValue),(yyvsp[(3) - (3)].dValue));
        (yyval.oPFloat) = Option<std::pair<double,double>* >::some(dom); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 1668 "gecode/flatzinc/parser.yxx"
    { (yyval.setLit) = new AST::SetLit(*(yyvsp[(2) - (3)].setValue)); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 1670 "gecode/flatzinc/parser.yxx"
    { (yyval.setLit) = new AST::SetLit((yyvsp[(1) - (3)].iValue), (yyvsp[(3) - (3)].iValue)); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 1676 "gecode/flatzinc/parser.yxx"
    { (yyval.setValue) = new vector<int>(0); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 1678 "gecode/flatzinc/parser.yxx"
    { (yyval.setValue) = (yyvsp[(1) - (2)].setValue); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 1682 "gecode/flatzinc/parser.yxx"
    { (yyval.setValue) = new vector<int>(1); (*(yyval.setValue))[0] = (yyvsp[(1) - (1)].iValue); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 1684 "gecode/flatzinc/parser.yxx"
    { (yyval.setValue) = (yyvsp[(1) - (3)].setValue); (yyval.setValue)->push_back((yyvsp[(3) - (3)].iValue)); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 1688 "gecode/flatzinc/parser.yxx"
    { (yyval.setValue) = new vector<int>(0); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 1690 "gecode/flatzinc/parser.yxx"
    { (yyval.setValue) = (yyvsp[(1) - (2)].setValue); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 1694 "gecode/flatzinc/parser.yxx"
    { (yyval.setValue) = new vector<int>(1); (*(yyval.setValue))[0] = (yyvsp[(1) - (1)].iValue); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 1696 "gecode/flatzinc/parser.yxx"
    { (yyval.setValue) = (yyvsp[(1) - (3)].setValue); (yyval.setValue)->push_back((yyvsp[(3) - (3)].iValue)); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1700 "gecode/flatzinc/parser.yxx"
    { (yyval.floatSetValue) = new vector<double>(0); }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 1702 "gecode/flatzinc/parser.yxx"
    { (yyval.floatSetValue) = (yyvsp[(1) - (2)].floatSetValue); }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 1706 "gecode/flatzinc/parser.yxx"
    { (yyval.floatSetValue) = new vector<double>(1); (*(yyval.floatSetValue))[0] = (yyvsp[(1) - (1)].dValue); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1708 "gecode/flatzinc/parser.yxx"
    { (yyval.floatSetValue) = (yyvsp[(1) - (3)].floatSetValue); (yyval.floatSetValue)->push_back((yyvsp[(3) - (3)].dValue)); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 1712 "gecode/flatzinc/parser.yxx"
    { (yyval.setValueList) = new vector<AST::SetLit>(0); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 1714 "gecode/flatzinc/parser.yxx"
    { (yyval.setValueList) = (yyvsp[(1) - (2)].setValueList); }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 1718 "gecode/flatzinc/parser.yxx"
    { (yyval.setValueList) = new vector<AST::SetLit>(1); (*(yyval.setValueList))[0] = *(yyvsp[(1) - (1)].setLit); delete (yyvsp[(1) - (1)].setLit); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 1720 "gecode/flatzinc/parser.yxx"
    { (yyval.setValueList) = (yyvsp[(1) - (3)].setValueList); (yyval.setValueList)->push_back(*(yyvsp[(3) - (3)].setLit)); delete (yyvsp[(3) - (3)].setLit); }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 1728 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = new AST::Array((yyvsp[(1) - (1)].arg)); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 1730 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = (yyvsp[(1) - (3)].argVec); (yyval.argVec)->append((yyvsp[(3) - (3)].arg)); }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1734 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = (yyvsp[(1) - (1)].arg); }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 1736 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = (yyvsp[(2) - (3)].argVec); }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 1740 "gecode/flatzinc/parser.yxx"
    { (yyval.oArg) = Option<AST::Node*>::none(); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1742 "gecode/flatzinc/parser.yxx"
    { (yyval.oArg) = Option<AST::Node*>::some((yyvsp[(2) - (2)].arg)); }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1746 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = new AST::BoolLit((yyvsp[(1) - (1)].iValue)); }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1748 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = new AST::IntLit((yyvsp[(1) - (1)].iValue)); }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1750 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = new AST::FloatLit((yyvsp[(1) - (1)].dValue)); }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1752 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = (yyvsp[(1) - (1)].setLit); }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1754 "gecode/flatzinc/parser.yxx"
    { 
        ParserState* pp = static_cast<ParserState*>(parm);
        SymbolEntry e;
        if (pp->symbols.get((yyvsp[(1) - (1)].sValue), e)) {
          switch (e.t) {
          case ST_INTVARARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::IntVar(pp->arrays[e.i+i+1]);
              (yyval.arg) = v;
            }
            break;
          case ST_BOOLVARARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::BoolVar(pp->arrays[e.i+i+1]);
              (yyval.arg) = v;
            }
            break;
          case ST_FLOATVARARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::FloatVar(pp->arrays[e.i+i+1]);
              (yyval.arg) = v;
            }
            break;
          case ST_SETVARARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::SetVar(pp->arrays[e.i+i+1]);
              (yyval.arg) = v;
            }
            break;
          case ST_INTVALARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::IntLit(pp->arrays[e.i+i+1]);
              (yyval.arg) = v;
            }
            break;
          case ST_BOOLVALARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::BoolLit(pp->arrays[e.i+i+1]);
              (yyval.arg) = v;
            }
            break;
          case ST_SETVALARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              int idx = pp->arrays[e.i+1];
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::SetLit(pp->setvals[idx+i]);
              (yyval.arg) = v;
            }
            break;
          case ST_FLOATVALARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              int idx = pp->arrays[e.i+1];
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::FloatLit(pp->floatvals[idx+i]);
              (yyval.arg) = v;
            }
            break;
          case ST_INT:
            (yyval.arg) = new AST::IntLit(e.i);
            break;
          case ST_BOOL:
            (yyval.arg) = new AST::BoolLit(e.i);
            break;
          case ST_FLOAT:
            (yyval.arg) = new AST::FloatLit(pp->floatvals[e.i]);
            break;
          case ST_SET:
            (yyval.arg) = new AST::SetLit(pp->setvals[e.i]);
            break;
          default:
            (yyval.arg) = getVarRefArg(pp,(yyvsp[(1) - (1)].sValue));
          }
        } else {
          pp->err << "Error: undefined identifier " << (yyvsp[(1) - (1)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
          (yyval.arg) = NULL;
        }
        free((yyvsp[(1) - (1)].sValue));
      }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1850 "gecode/flatzinc/parser.yxx"
    { 
        ParserState* pp = static_cast<ParserState*>(parm);
        int i = -1;
        yyassert(pp, (yyvsp[(3) - (4)].arg)->isInt(i), "Non-integer array index");
        if (!pp->hadError)
          (yyval.arg) = getArrayElement(static_cast<ParserState*>(parm),(yyvsp[(1) - (4)].sValue),i,false);
        else
          (yyval.arg) = new AST::IntLit(0); // keep things consistent
        delete (yyvsp[(3) - (4)].arg);
        free((yyvsp[(1) - (4)].sValue));
      }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1864 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = new AST::Array(0); }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1866 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = (yyvsp[(1) - (2)].argVec); }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1870 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = new AST::Array((yyvsp[(1) - (1)].arg)); }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1872 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = (yyvsp[(1) - (3)].argVec); (yyval.argVec)->append((yyvsp[(3) - (3)].arg)); }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1880 "gecode/flatzinc/parser.yxx"
    { 
        ParserState *pp = static_cast<ParserState*>(parm);
        SymbolEntry e;
        bool haveSym = pp->symbols.get((yyvsp[(1) - (1)].sValue),e);
        if (haveSym) {
          switch (e.t) {
          case ST_INTVAR:
            (yyval.iValue) = e.i;
            break;
          case ST_FLOATVAR:
            (yyval.iValue) = -e.i-1;
            break;
          case ST_INT:
          case ST_FLOAT:
            pp->intvars.push_back(varspec("OBJ_CONST_INTRODUCED",
              new IntVarSpec(0,true,false)));
            (yyval.iValue) = pp->intvars.size()-1;
            break;
          default:
            pp->err << "Error: unknown int or float variable " << (yyvsp[(1) - (1)].sValue)
                    << " in line no. "
                    << yyget_lineno(pp->yyscanner) << std::endl;
            pp->hadError = true;
            break;
          }
        } else {
          pp->err << "Error: unknown int or float variable " << (yyvsp[(1) - (1)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
        }
        free((yyvsp[(1) - (1)].sValue));
      }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 1914 "gecode/flatzinc/parser.yxx"
    {
        ParserState *pp = static_cast<ParserState*>(parm);
        pp->intvars.push_back(varspec("OBJ_CONST_INTRODUCED",
          new IntVarSpec(0,true,false)));
        (yyval.iValue) = pp->intvars.size()-1;
      }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1921 "gecode/flatzinc/parser.yxx"
    {
        ParserState *pp = static_cast<ParserState*>(parm);
        pp->intvars.push_back(varspec("OBJ_CONST_INTRODUCED",
          new IntVarSpec(0,true,false)));
        (yyval.iValue) = pp->intvars.size()-1;
      }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1928 "gecode/flatzinc/parser.yxx"
    {
        SymbolEntry e;
        ParserState *pp = static_cast<ParserState*>(parm);
        if ( (!pp->symbols.get((yyvsp[(1) - (4)].sValue), e)) ||
             (e.t != ST_INTVARARRAY && e.t != ST_FLOATVARARRAY)) {
          pp->err << "Error: unknown int or float variable array " << (yyvsp[(1) - (4)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
        }
        if ((yyvsp[(3) - (4)].iValue) == 0 || (yyvsp[(3) - (4)].iValue) > pp->arrays[e.i]) {
          pp->err << "Error: array index out of bounds for array " << (yyvsp[(1) - (4)].sValue)
                  << " in line no. "
                  << yyget_lineno(pp->yyscanner) << std::endl;
          pp->hadError = true;
        } else {
          if (e.t == ST_INTVARARRAY)
            (yyval.iValue) = pp->arrays[e.i+(yyvsp[(3) - (4)].iValue)];
          else
            (yyval.iValue) = -pp->arrays[e.i+(yyvsp[(3) - (4)].iValue)]-1;
        }
        free((yyvsp[(1) - (4)].sValue));
      }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1962 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = NULL; }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1964 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = (yyvsp[(1) - (1)].argVec); }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1968 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = new AST::Array((yyvsp[(2) - (2)].arg)); }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1970 "gecode/flatzinc/parser.yxx"
    { (yyval.argVec) = (yyvsp[(1) - (3)].argVec); (yyval.argVec)->append((yyvsp[(3) - (3)].arg)); }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 1974 "gecode/flatzinc/parser.yxx"
    { 
        (yyval.arg) = new AST::Call((yyvsp[(1) - (4)].sValue), AST::extractSingleton((yyvsp[(3) - (4)].arg))); free((yyvsp[(1) - (4)].sValue));
      }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1978 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = (yyvsp[(1) - (1)].arg); }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1982 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = new AST::Array((yyvsp[(1) - (1)].arg)); }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1984 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = (yyvsp[(1) - (3)].arg); (yyval.arg)->append((yyvsp[(3) - (3)].arg)); }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1988 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = (yyvsp[(1) - (1)].arg); }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1990 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = new AST::Array(); }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1992 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = (yyvsp[(2) - (4)].arg); }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1998 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = new AST::BoolLit((yyvsp[(1) - (1)].iValue)); }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 2000 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = new AST::IntLit((yyvsp[(1) - (1)].iValue)); }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 2002 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = new AST::FloatLit((yyvsp[(1) - (1)].dValue)); }
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 2004 "gecode/flatzinc/parser.yxx"
    { (yyval.arg) = (yyvsp[(1) - (1)].setLit); }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 2006 "gecode/flatzinc/parser.yxx"
    { 
        ParserState* pp = static_cast<ParserState*>(parm);
        SymbolEntry e;
        bool gotSymbol = false;
        if (pp->symbols.get((yyvsp[(1) - (1)].sValue), e)) {
          gotSymbol = true;
          switch (e.t) {
          case ST_INTVARARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;) {
                std::ostringstream oss;
                oss << (yyvsp[(1) - (1)].sValue) << "["<<(i+1)<<"]";
                v->a[i] = new AST::IntVar(pp->arrays[e.i+i+1], oss.str());
              }
              (yyval.arg) = v;
            }
            break;
          case ST_BOOLVARARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;) {
                std::ostringstream oss;
                oss << (yyvsp[(1) - (1)].sValue) << "["<<(i+1)<<"]";
                v->a[i] = new AST::BoolVar(pp->arrays[e.i+i+1], oss.str());
              }
              (yyval.arg) = v;
            }
            break;
          case ST_FLOATVARARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;) {
                std::ostringstream oss;
                oss << (yyvsp[(1) - (1)].sValue) << "["<<(i+1)<<"]";
                v->a[i] = new AST::FloatVar(pp->arrays[e.i+i+1], oss.str());
              }
              (yyval.arg) = v;
            }
            break;
          case ST_SETVARARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;) {
                std::ostringstream oss;
                oss << (yyvsp[(1) - (1)].sValue) << "["<<(i+1)<<"]";
                v->a[i] = new AST::SetVar(pp->arrays[e.i+i+1], oss.str());
              }
              (yyval.arg) = v;
            }
            break;
          case ST_INTVALARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::IntLit(pp->arrays[e.i+i+1]);
              (yyval.arg) = v;
            }
            break;
          case ST_BOOLVALARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::BoolLit(pp->arrays[e.i+i+1]);
              (yyval.arg) = v;
            }
            break;
          case ST_SETVALARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              int idx = pp->arrays[e.i+1];
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::SetLit(pp->setvals[idx+i]);
              (yyval.arg) = v;
            }
            break;
          case ST_FLOATVALARRAY:
            {
              AST::Array *v = new AST::Array(pp->arrays[e.i]);
              int idx = pp->arrays[e.i+1];
              for (int i=pp->arrays[e.i]; i--;)
                v->a[i] = new AST::FloatLit(pp->floatvals[idx+i]);
              (yyval.arg) = v;
            }
            break;
          case ST_INT:
            (yyval.arg) = new AST::IntLit(e.i);
            break;
          case ST_BOOL:
            (yyval.arg) = new AST::BoolLit(e.i);
            break;
          case ST_FLOAT:
            (yyval.arg) = new AST::FloatLit(pp->floatvals[e.i]);
            break;
          case ST_SET:
            (yyval.arg) = new AST::SetLit(pp->setvals[e.i]);
            break;
          default:
            gotSymbol = false;
          }
        }
        if (!gotSymbol)
          (yyval.arg) = getVarRefArg(pp,(yyvsp[(1) - (1)].sValue),true);
        free((yyvsp[(1) - (1)].sValue));
      }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 2112 "gecode/flatzinc/parser.yxx"
    { 
        ParserState* pp = static_cast<ParserState*>(parm);
        int i = -1;
        yyassert(pp, (yyvsp[(3) - (4)].arg)->isInt(i), "Non-integer array index");
        if (!pp->hadError)
          (yyval.arg) = getArrayElement(static_cast<ParserState*>(parm),(yyvsp[(1) - (4)].sValue),i,true);
        else
          (yyval.arg) = new AST::IntLit(0); // keep things consistent
        free((yyvsp[(1) - (4)].sValue));
      }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 2123 "gecode/flatzinc/parser.yxx"
    {
        (yyval.arg) = new AST::String((yyvsp[(1) - (1)].sValue));
        free((yyvsp[(1) - (1)].sValue));
      }
    break;


/* Line 1787 of yacc.c  */
#line 4036 "gecode/flatzinc/parser.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (parm, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (parm, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, parm);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, parm);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parm, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parm);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, parm);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


