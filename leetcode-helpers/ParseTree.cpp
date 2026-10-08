#include "ParseTree.h"

#include "StringSplit.h"

#include <vector>

struct IndexAndNode
{
    std::size_t value_index{};
    TreeNode& node;
};

std::size_t get_left_node_index( std::size_t parent_index )
{
    return 2*parent_index + 1;
}

std::size_t get_right_node_index( std::size_t parent_index )
{
    return 2*parent_index + 2;
}

std::list<TreeNode> Parse( const std::string& input )
{
    const auto values{ split( input, ',' ) };

    if( 0 == input.size() || "null" == values.at( 0 ) )
        return {};

    std::list<TreeNode> data{ TreeNode( std::stoi( values.at( 0 ) ) ) };

    std::vector<IndexAndNode> to_add_children_stack{
        IndexAndNode{ 0, data.front() }
    };

    while( 0 < to_add_children_stack.size() )
    {
        const auto index_and_node{ to_add_children_stack.back() };
        to_add_children_stack.pop_back();

        const auto l_node_index{ get_left_node_index( index_and_node.value_index ) };
        const auto r_node_index{ get_right_node_index( index_and_node.value_index ) };

        if( l_node_index < values.size() && values.at( l_node_index ) != "null" )
        {
            data.push_back( TreeNode( std::stoi( values.at( l_node_index ) ) ) );
            index_and_node.node.left = &data.back();
            to_add_children_stack.push_back(
                IndexAndNode{ l_node_index, data.back() }
            );
        }
        if( r_node_index < values.size() && values.at( r_node_index ) != "null" )
        {
            data.push_back( TreeNode( std::stoi( values.at( r_node_index ) ) ) );
            index_and_node.node.right = &data.back(); 
            to_add_children_stack.push_back(
                IndexAndNode{ r_node_index, data.back() }
            );
        }
    }

    return data;
}
