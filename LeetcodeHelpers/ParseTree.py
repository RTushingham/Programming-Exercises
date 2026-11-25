
from .TreeNode import TreeNode

from collections.abc import Sequence
from operator import methodcaller


def _Parse_from_sequence( vals: Sequence ) -> TreeNode | None:
    if 0 == len( vals ):
        return None

    def get_left_node_index( parent_index: int ) -> int:
        return 2*parent_index + 1
    def get_right_node_index( parent_index: int ) -> int:
        return 2*parent_index + 2

    first_node = TreeNode( vals[0] )
    to_add_children_stack = [ ( 0, first_node ) ]
    while 0 < len( to_add_children_stack ):
        index, val = to_add_children_stack.pop()

        left_node_index = get_left_node_index( index )
        if left_node_index < len( vals ) :
            left_val = vals[ left_node_index ]
            if left_val is not None :
                val.left = TreeNode( left_val )
                to_add_children_stack.append( ( left_node_index, val.left ) )

        right_node_index = get_right_node_index( index )
        if right_node_index < len( vals ) :
            right_val = vals[ right_node_index ]
            if right_val is not None :
                val.right = TreeNode( right_val )
                to_add_children_stack.append( ( right_node_index, val.right ) )

    return first_node


def Parse_from_string( literal: str, val_type : type = int ) -> TreeNode | None:
    """
    Construct a binary tree from a comma separated list of node values or "null"
    
    Syntax matches that used on leetcode
    """
    
    if not isinstance( literal, str ):
        raise Exception( "Test writer error" )

    def construct_if_not_string_null( literal: str ) :
        if literal == "null" :
            return None
        else :
            return val_type( literal )
    
    strip_quotes_and_spaces = methodcaller("strip", '" ')
    vals_list = [ val for val in map( construct_if_not_string_null, map( strip_quotes_and_spaces, literal.split(',') ) ) ]
    return _Parse_from_sequence( vals_list )

