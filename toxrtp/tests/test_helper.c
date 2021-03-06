/*   test_helper.c
 *
 *   Tests support. !Red!
 *
 *
 *   Copyright (C) 2013 Tox project All Rights Reserved.
 *
 *   This file is part of Tox.
 *
 *   Tox is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tox is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tox.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "test_helper.h"

#include <string.h>
#include <stdlib.h>

arg_t* parse_args ( int argc, char* argv[] )
{
    arg_t* _list = calloc(sizeof(arg_t), 1);
    _list->next = _list->prev = NULL;

    arg_t* it = _list;

    size_t val;
    for ( val = 0; val < argc; val ++ ) {
        it->value = argv[val];

        if ( val < argc - 1 ) { /* just about to end */
            it->next = calloc(sizeof(arg_t), 1);
            it->next->prev = it;
            it = it->next;
            it->next = NULL;
        }
    }

    return _list;
}

int find_arg_simple ( arg_t* _head, const char* _id )
{
    arg_t* it = _head;

    int i;
    for ( i = 1; it != NULL; it = it->next ) {
        if ( strcmp ( _id, it->value ) == 0 ) {
            return i;
        }

        i++;
    }

    return FAILURE;
}

const char* find_arg_duble ( arg_t* _head, const char* _id )
{
    arg_t* _it;
    for ( _it = _head; _it != NULL; _it = _it->next ) {
        if ( strcmp ( _id, _it->value ) == 0 ) {
            if ( _it->next && _it->next->value[0] != '-' ) { /* exclude option */
                return _it->next->value;
            } else {
                return NULL;
            }
        }
    }

    return NULL;
}

