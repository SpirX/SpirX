---
date: 2017-05-01T14:31:53-05:00
title: Loader
---
The loader is the component used to load all necessary SpirX libraries, extensions, and layers.

## sxQueryAddress {#sxqueryaddress}
Queries the loader for a function address.

### Specification {#sxqueryaddress-specification}
``` c
int sxQueryAddress(
		const char*                             symbol,         // The name of the symbol.
		void**                                  address         // A pointer to a function pointer.
);
```

### Parameters {#sxqueryaddress-parameters}
- `symbol` is a C string storing a symbol name. Must not be `NULL`.
- `address` is an out pointer to a function pointer.

### Description {#sxqueryaddress-description}
The function attempts to locate a function address given its name. The parameter `symbol` is a C string representing the name of the function.

The parameter `address` may be `NULL` or non-`NULL`. If the parameter is `NULL`, then the return value of the function represents a boolean value, `true` if the function exists, and `false` if the function does not. If the parameter is non-`NULL`, then the function will store the function pointer at the address given by `address`.

### See Also {#sxqueryaddress-see-also}
[sxQuerySymbol](#sxquerysymbol)

## sxQuerySymbol {#sxquerysymbol}
Queries the loader for a symbol name.

### Specification {#sxquerysymbol-specification}
``` c
int sxQuerySymbol(
		void*                                   address,        // A pointer to the function
		const char**                            symbol          // A pointer to the name of the symbol.
);
```

### Parameters {#sxquerysymbol-parameters}
- `address` is a function pointer. Must not be `NULL`.
- `symbol` is an out pointer to a C string storing a symbol name.

### Description {#sxquerysymbol-description}
The function attempts to locate a function name given its address. The parameter `address` is a pointer to the function itself.

The parameter `symbol` may be `NULL` or non-`NULL`. If the parameter is `NULL`, then the return value of the function represents a boolean value, `true` if the function's name exists, and `false` if the function's name does not. If the parameter is non-`NULL`, then the function will store a pointer to the C string at the address given by `symbol`.

### See Also {#sxquerysymbol-see-also}
[sxQueryAddress](#sxqueryaddress)
