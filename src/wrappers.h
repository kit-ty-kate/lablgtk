/* $Id$ */

#ifndef _wrappers_
#define _wrappers_

#include <caml/mlvalues.h>
#include <caml/fail.h>

value copy_memblock_indirected (void *src, asize_t size);
value ml_some (value);
void ml_raise_null_pointer (void) Noreturn;
value Val_pointer (void *);
value copy_string_check (const char*);
value copy_string_or_null (const char *);

typedef struct { value key; int data; } lookup_info;
value ml_lookup_from_c (lookup_info *table, int data);
int ml_lookup_to_c (lookup_info *table, value key);

/* Wrapper generators */

#define ML_0(cname, conv) \
value ml_##cname (value unit) { return conv (cname ()); }
#define ML_1(cname, conv1, conv) \
value ml_##cname (value arg1) { return conv (cname (conv1 (arg1))); }
#define ML_1_post(cname, conv1, conv, post) \
value ml_##cname (value arg1) \
{ value ret = conv (cname (conv1(arg1))); post; return ret; }
#define ML_2(cname, conv1, conv2, conv) \
value ml_##cname (value arg1, value arg2) \
{ return conv (cname (conv1(arg1), conv2(arg2))); }
#define ML_2_name(mlname, cname, conv1, conv2, conv) \
value mlname (value arg1, value arg2) \
{ return conv (cname (conv1(arg1), conv2(arg2))); }
#define ML_3(cname, conv1, conv2, conv3, conv) \
value ml_##cname (value arg1, value arg2, value arg3) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3))); }
#define ML_3_name(mlname, cname, conv1, conv2, conv3, conv) \
value mlname (value arg1, value arg2, value arg3) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3))); }
#define ML_4(cname, conv1, conv2, conv3, conv4, conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4))); }
#define ML_4_name(mlname, cname, conv1, conv2, conv3, conv4, conv) \
value mlname (value arg1, value arg2, value arg3, value arg4) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4))); }
#define ML_5(cname, conv1, conv2, conv3, conv4, conv5, conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4, value arg5) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4), \
		      conv5(arg5))); }
#define ML_6(cname, conv1, conv2, conv3, conv4, conv5, conv6, conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4, value arg5, \
		  value arg6) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4), \
		      conv5(arg5), conv6(arg6))); }
#define ML_7(cname, conv1, conv2, conv3, conv4, conv5, conv6, conv7, conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4, value arg5, \
		  value arg6, value arg7) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4), \
		      conv5(arg5), conv6(arg6), conv7(arg7))); }
#define ML_8(cname, conv1, conv2, conv3, conv4, conv5, conv6, conv7, conv8, \
	     conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4, value arg5, \
		  value arg6, value arg7, value arg8) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4), \
		      conv5(arg5), conv6(arg6), conv7(arg7), conv8(arg8))); }
#define ML_9(cname, conv1, conv2, conv3, conv4, conv5, conv6, conv7, conv8, \
	      conv9, conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4, value arg5, \
		  value arg6, value arg7, value arg8, value arg9) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4), \
		      conv5(arg5), conv6(arg6), conv7(arg7), conv8(arg8), \
		      conv9(arg9))); }
#define ML_10(cname, conv1, conv2, conv3, conv4, conv5, conv6, conv7, conv8, \
	      conv9, conv10, conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4, value arg5, \
		  value arg6, value arg7, value arg8, value arg9, value arg10)\
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4), \
		      conv5(arg5), conv6(arg6), conv7(arg7), conv8(arg8), \
		      conv9(arg9), conv10(arg10))); }
#define ML_11(cname, conv1, conv2, conv3, conv4, conv5, conv6, conv7, conv8, \
	      conv9, conv10, conv11, conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4, value arg5, \
		  value arg6, value arg7, value arg8, value arg9, value arg10,\
		  value arg11) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4), \
		      conv5(arg5), conv6(arg6), conv7(arg7), conv8(arg8), \
		      conv9(arg9), conv10(arg10), conv11(arg11))); }
#define ML_12(cname, conv1, conv2, conv3, conv4, conv5, conv6, conv7, conv8, \
	      conv9, conv10, conv11, conv12, conv) \
value ml_##cname (value arg1, value arg2, value arg3, value arg4, value arg5, \
		  value arg6, value arg7, value arg8, value arg9, value arg10,\
		  value arg11, value arg12) \
{ return conv (cname (conv1(arg1), conv2(arg2), conv3(arg3), conv4(arg4), \
		      conv5(arg5), conv6(arg6), conv7(arg7), conv8(arg8), \
		      conv9(arg9), conv10(arg10), conv11(arg11), \
		      conv12(arg12))); }

/* Use with care: needs the argument index */
#define Ignore(x)
#define Insert(x) (x),
#define Split(x,f,g) f(x), g(x) Ignore
#define Split3(x,f,g,h) f(x), g(x), h(x) Ignore
#define Pair(x,f,g) f(Field(x,0)), g(Field(x,1)) Ignore
#define Triple(x,f,g,h) f(Field(x,0)), g(Field(x,1)), h(Field(x,2)) Ignore

/* For more than 5 arguments */
#define ML_bc6(cname) \
value cname##_bc (value *argv, int argn) \
{ return cname(argv[0],argv[1],argv[2],argv[3],argv[4],argv[5]); }
#define ML_bc7(cname) \
value cname##_bc (value *argv, int argn) \
{ return cname(argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6]); }
#define ML_bc8(cname) \
value cname##_bc (value *argv, int argn) \
{ return cname(argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6], \
	       argv[7]); }
#define ML_bc9(cname) \
value cname##_bc (value *argv, int argn) \
{ return cname(argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6], \
	       argv[7],argv[8]); }
#define ML_bc10(cname) \
value cname##_bc (value *argv, int argn) \
{ return cname(argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6], \
	       argv[7],argv[8],argv[9]); }
#define ML_bc11(cname) \
value cname##_bc (value *argv, int argn) \
{ return cname(argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6], \
	       argv[7],argv[8],argv[9],argv[10]); }
#define ML_bc12(cname) \
value cname##_bc (value *argv, int argn) \
{ return cname(argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6], \
	       argv[7],argv[8],argv[9],argv[10],argv[11]); }

/* result conversion */
#define Unit(x) ((x), Val_unit)
#define Id(x) x
#define Val_char Val_int

/* parameter conversion */
#define Bool_ptr(x) ((long) x - 1)
#define Char_val Int_val
#define Float_val(x) ((float)Double_val(x))

#define Option_val(val,unwrap,default) \
((long)val-1 ? unwrap(Field(val,0)) : default)
#define String_option_val(s) Option_val(s,String_val,NULL)

/* Utility */

#define Copy_array(ret,l,src,conv) \
 if (!l) ret = Atom(0); \
 else if (l <= Max_young_wosize) { int i; ret = alloc_tuple(l); \
   for(i=0;i<l;i++) Field(ret,i) = conv(src[i]); } \
 else { int i; ret = alloc_shr(l,0); \
   for(i=0;i<l;i++) initialize (&Field(ret,i), conv(src[i])); }

#define Make_Val_final_pointer(type, init, final, adv) \
static void ml_final_##type (value val) \
{ if (Field(val,1)) final ((type*)Field(val,1)); } \
value Val_##type (type *p) \
{ value ret; if (!p) ml_raise_null_pointer(); \
  ret = alloc_final (2, ml_final_##type, adv, 1000); \
  initialize (&Field(ret,1), (value) p); init(p); return ret; }

#define Make_Val_final_pointer_ext(type, ext, init, final, adv) \
static void ml_final_##type##ext (value val) \
{ if (Field(val,1)) final ((type*)Field(val,1)); } \
value Val_##type##ext (type *p) \
{ value ret; if (!p) ml_raise_null_pointer(); \
  ret = alloc_final (2, ml_final_##type##ext, adv, 1000); \
  initialize (&Field(ret,1), (value) p); init(p); return ret; }

#define Pointer_val(val) ((void*)Field(val,1))
#define MLPointer_val(val) (Field(val,1) == 2 ? &Field(val,2) : (void*)Field(val,1))

#define Val_addr(ptr) (1+(value)ptr)
#define Addr_val(val) ((void*)(val-1))

#define Wosize_asize(x) ((x-1)/sizeof(value)+1)
#define Wosizeof(x) Wosize_asize(sizeof(x))

#define Make_Extractor(name,conv1,field,conv2) \
value ml_##name##_##field (value val) \
{ return conv2 ((conv1(val))->field); }

#define Make_Setter(name,conv1,conv2,field) \
value ml_##name##_##field (value val, value new) \
{ (conv1(val))->field = conv2(new); return Val_unit; }

#define Make_Array_Extractor(name,conv1,conv2,field,conv) \
value ml_##name##_##field (value val, value index) \
{ return conv ((conv1(val))->field[conv2(index)]); }

#define Make_Array_Setter(name,conv1,conv2,conv3,field) \
value ml_##name##_##field (value val, value index, value new) \
{ (conv1(val))->field[conv2(index)] = conv3(new); return Val_unit; }

/* ML value is [flag list] */
#define Make_Flags_val(conv) \
int Flags_##conv (value list) \
{ int flags = 0L; \
  while Is_block(list) { flags |= conv(Field(list,0)); list = Field(list,1); }\
  return flags; }

/* ML value is [flag list option] */
#define Make_OptFlags_val(conv) \
int OptFlags_##conv (value list) \
{ int flags = 0L; \
  if Is_block(list) list = Field(list,0); \
  while Is_block(list) { flags |= conv(Field(list,0)); list = Field(list,1); }\
  return flags; }

#define Val_copy(val) copy_memblock_indirected (&val, sizeof(val))
#define Val_string copy_string_check
#define Val_optstring copy_string_or_null
#define Val_option(v,f) (v ? ml_some(f(v)) : Val_unit)

#define Check_null(v) (v ? v : (ml_raise_null_pointer (), v))

#endif /* _wrappers_ */