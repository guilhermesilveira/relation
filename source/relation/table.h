#ifndef TABLE_H
#define TABLE_H

RelationTable *new_relation_table();

RelationTable *table_instance_name(RelationTable *relation_table, SqlLiteral table_name);

RelationTable *table_instance_alias(RelationTable *relation_table, SqlLiteral alias_name);

SelectManager *relation_table_from(RelationTable *table);

SelectManager *relation_table_select_manager(RelationTable *table);

SelectManager *relation_table_project(RelationTable *table, SqlLiteral sql_literal);

SelectManager *relation_table_limit(RelationTable *table, long long limit_number);

SelectManager *relation_table_where(RelationTable *table, SqlLiteral expression);

SelectManager *relation_table_order(RelationTable *table, SqlLiteral expression);

SelectManager *relation_table_offset(RelationTable *table, int offset_number);

SelectManager *relation_table_group(RelationTable *table, SqlLiteral expression);

SelectManager *relation_table_having(RelationTable *table, SqlLiteral expression);

#endif