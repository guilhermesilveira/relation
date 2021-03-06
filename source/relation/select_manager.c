#include <stdlib.h>
#include <string.h>
#include "relation.h"
#include "relation/select_manager.h"
#include "relation/table.h"
#include "relation/sql_literal.h"

SelectManager *new_select_manager() {
	// TODO: Verify Malloc
	SelectManager *select_manager = (SelectManager *) malloc(sizeof(SelectManager));
	return select_manager;
}

ArraySqlLiterals *new_array_of_sql_literals(SqlLiteral expression) {
	ArraySqlLiterals *array_sql_literal;
	/*  TODO: Verify malloc */
	array_sql_literal = (ArraySqlLiterals *) malloc(sizeof(ArraySqlLiterals)); 
	/*  */
	
	array_sql_literal->sql_literal = expression;
	array_sql_literal->next = NULL;
	return array_sql_literal;
}

SelectManager *select_manager_instance_table(SelectManager *select_manager, RelationTable *table) {
	select_manager->abstract_syntax_tree.froms = table;
	select_manager->abstract_syntax_tree.limit = 0;
	select_manager->abstract_syntax_tree.offset = 0;
	select_manager->abstract_syntax_tree.projections = NULL;
	select_manager->abstract_syntax_tree.projections_tail = NULL;
	select_manager->abstract_syntax_tree.wheres = NULL;	
	select_manager->abstract_syntax_tree.wheres_tail = NULL;	
	select_manager->abstract_syntax_tree.orders = NULL;
	select_manager->abstract_syntax_tree.groups = NULL;
	select_manager->abstract_syntax_tree.groups_tail = NULL;
	select_manager->abstract_syntax_tree.having = NULL;	
	return select_manager;
}

SelectManager *select_manager_order(SelectManager *select_manager, char *expression) {
	select_manager->abstract_syntax_tree.orders = expression;
	return select_manager;
}

SelectManager *select_manager_offset(SelectManager *select_manager, int offset_number) {
	select_manager->abstract_syntax_tree.offset = offset_number;
	return select_manager;
}

SelectManager *select_manager_limit(SelectManager *select_manager, long long limit_number) {
	select_manager->abstract_syntax_tree.limit = limit_number;
	return select_manager;
}

/*
* FIXME: Removing Duplication
*/
SelectManager *select_manager_project(SelectManager *select_manager, SqlLiteral sql_literal) {
	ArraySqlLiterals *literal = new_array_of_sql_literals(sql_literal);
	
	if(select_manager->abstract_syntax_tree.projections == NULL)
		select_manager->abstract_syntax_tree.projections = literal;
	else 
		select_manager->abstract_syntax_tree.projections_tail->next = literal;
		
	select_manager->abstract_syntax_tree.projections_tail = literal;
	
	return select_manager;
}

/*
* * FIXME: Removing Duplication
*/
SelectManager *select_manager_where(SelectManager *select_manager, SqlLiteral expression) {
	ArraySqlLiterals *literal = new_array_of_sql_literals(expression);
	
	if(select_manager->abstract_syntax_tree.wheres == NULL)
		select_manager->abstract_syntax_tree.wheres = literal;
	else 
		select_manager->abstract_syntax_tree.wheres_tail->next = literal;
		
	select_manager->abstract_syntax_tree.wheres_tail = literal;

	return select_manager;
}

/*
* FIXME: Removing Duplication
*/
SelectManager *select_manager_group(SelectManager *select_manager, SqlLiteral expression) {
	ArraySqlLiterals *literal = new_array_of_sql_literals(expression);
	
	if(select_manager->abstract_syntax_tree.groups == NULL)
		select_manager->abstract_syntax_tree.groups = literal;
	else 
		select_manager->abstract_syntax_tree.groups_tail->next = literal;
		
	select_manager->abstract_syntax_tree.groups_tail = literal;

	return select_manager;
}

SelectManager *select_manager_having(SelectManager *select_manager, SqlLiteral expression) {
	select_manager->abstract_syntax_tree.having = expression;
	return select_manager;
}