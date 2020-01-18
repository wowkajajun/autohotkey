/*
AutoHotkey
Copyright 2003-2009 Chris Mallett (support@autohotkey.com)
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

// These names are reserved (as module names) and cannot be defined by the script.
// They can be changed here to any valid "var name". 
#define SMODULES_DEFAULT_MODULE_NAME _T("Script")	// This is the name of the module which the entire script resides in. 
													// It allows easy access to the top layer in a general and recognizable way.

#define SMODULES_STANDARD_MODULE_NAME _T("std")		// This is the name of the standard module for easy access to built-in functions and possibly future addititions. This module is parallel to the script's default module.

#define SMODULES_OUTER_MODULE_NAME _T("Outer")

// For unnamed modules:
#define SMODULES_UNNAMED_NAME _T("<unnamed ") SMODULES_DECLARATION_KEYWORD_NAME _T(">")	// For listlines / errors etc. This name is invalid for scripts due to '<', ' ' and '>'. This name can be any string.
#define SMODULES_UNNAMED_STR (ScriptModule::sUnamedModuleName)	// This is a static string for quickly identifying an unnamed module and avoid allocating a string for each unnamed module.

// For literal module definitions:
#define SMODULES_DECLARATION_KEYWORD_NAME _T("Namespace")
#define SMODULES_DECLARATION_KEYWORD_NAME_LENGTH (_countof(SMODULES_DECLARATION_KEYWORD_NAME) - 1) // - 1 to exclude the '\0

// For including file to module:
#define SMODULE_INCLUDE_DIRECTIVE_NAME _T("#Import")
#define SMODULE_INCLUDE_DIRECTIVE_NAME_LENGTH (_countof(SMODULE_INCLUDE_DIRECTIVE_NAME) - 1) // - 1 to exclude the '\0'

// Rule for module names match:
#define SMODULE_NAMES_MATCH(name1, name2) ((name1) != SMODULES_UNNAMED_STR && (name2) != SMODULES_UNNAMED_STR && !_tcsicmp( (name1), (name2)))

// Error messages:
#define ERR_SMODULES_NOT_FOUND _T("Namespace not found.")
#define ERR_SMODULES_DUPLICATE_NAME _T("Duplicate namespace definition.")
#define ERR_SMODULES_IN_FUNCTION _T("Functions cannot contain namespaces.")
#define ERR_SMODULES_IN_CLASS _T("Classes cannot contain namespaces.")
#define ERR_SMODULES_IN_BLOCK _T("This block cannot contain namespaces.")
#define ERR_SMODULES_DEFINITION_SYNTAX _T("Syntax error in namespace definition.") // Also used with SMODULE_INCLUDE_DIRECTIVE_NAME.
