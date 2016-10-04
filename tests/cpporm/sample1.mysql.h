/*
 * sample1.mysql.h
 *
 * generated by the ORM-compiler version 0.2.3
 */
#pragma once

/*
 * The entry-point header for cpporm
 */
#include <cpporm/cpporm.h>

/*
 * The client namespace
 */
namespace orm
{

/*
 * Forward declarations
 */
struct User;
struct Organization;
struct Team;
struct OrganizationType;
struct TeamMembership;

/*
 * The entity creator function
 */
std::shared_ptr<cpporm::Entity> Create(const std::string &key);

/*******************************************************************************
 * User
 ******************************************************************************/
CPPORM_DECLARE_ENTITY(User)
{
    CPPORM_DECLARE_ENTITY_METHODS;
    CPPORM_DECLARE_ATTRIBUTE(id);
    CPPORM_DECLARE_ATTRIBUTE(created_at);
    CPPORM_DECLARE_ATTRIBUTE(updated_at);
    CPPORM_DECLARE_ATTRIBUTE(deleted_at);
    CPPORM_DECLARE_ATTRIBUTE(created_by);
    CPPORM_DECLARE_ATTRIBUTE(updated_by);
    CPPORM_DECLARE_ATTRIBUTE(deleted_by);
    CPPORM_DECLARE_ATTRIBUTE(name);
    CPPORM_DECLARE_ATTRIBUTE(email);
    CPPORM_DECLARE_ATTRIBUTE(birth_date);
    CPPORM_DECLARE_ATTRIBUTE(personal_id);
    CPPORM_DECLARE_ATTRIBUTE(professional_id);
    CPPORM_DECLARE_INDEX(primary_key);
    CPPORM_DECLARE_INDEX(unique_email);
    CPPORM_DECLARE_INDEX(foreign_key_created_by);
    CPPORM_DECLARE_INDEX(foreign_key_updated_by);
    CPPORM_DECLARE_INDEX(foreign_key_deleted_by);
    CPPORM_DECLARE_INDEX(version_fields);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(created_by_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(updated_by_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(deleted_by_User, User);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_User_created_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_User_updated_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_User_deleted_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Organization_created_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Organization_updated_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Organization_deleted_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Team_created_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Team_updated_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Team_deleted_by);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_TeamMembership_user_id);
};

/*******************************************************************************
 * Organization
 ******************************************************************************/
CPPORM_DECLARE_ENTITY(Organization)
{
    CPPORM_DECLARE_ENTITY_METHODS;
    CPPORM_DECLARE_ATTRIBUTE(id);
    CPPORM_DECLARE_ATTRIBUTE(created_at);
    CPPORM_DECLARE_ATTRIBUTE(updated_at);
    CPPORM_DECLARE_ATTRIBUTE(deleted_at);
    CPPORM_DECLARE_ATTRIBUTE(created_by);
    CPPORM_DECLARE_ATTRIBUTE(updated_by);
    CPPORM_DECLARE_ATTRIBUTE(deleted_by);
    CPPORM_DECLARE_ATTRIBUTE(name);
    CPPORM_DECLARE_ATTRIBUTE(type_id);
    CPPORM_DECLARE_ATTRIBUTE(legal_id);
    CPPORM_DECLARE_ATTRIBUTE(legal_name);
    CPPORM_DECLARE_ATTRIBUTE(description);
    CPPORM_DECLARE_INDEX(primary_key);
    CPPORM_DECLARE_INDEX(unique_name);
    CPPORM_DECLARE_INDEX(foreign_key_created_by);
    CPPORM_DECLARE_INDEX(foreign_key_type_id);
    CPPORM_DECLARE_INDEX(foreign_key_updated_by);
    CPPORM_DECLARE_INDEX(foreign_key_deleted_by);
    CPPORM_DECLARE_INDEX(version_fields);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(created_by_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(updated_by_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(deleted_by_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(type_id_OrganizationType, OrganizationType);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Team_organization_id);
};

/*******************************************************************************
 * Team
 ******************************************************************************/
CPPORM_DECLARE_ENTITY(Team)
{
    CPPORM_DECLARE_ENTITY_METHODS;
    CPPORM_DECLARE_ATTRIBUTE(id);
    CPPORM_DECLARE_ATTRIBUTE(created_at);
    CPPORM_DECLARE_ATTRIBUTE(updated_at);
    CPPORM_DECLARE_ATTRIBUTE(deleted_at);
    CPPORM_DECLARE_ATTRIBUTE(created_by);
    CPPORM_DECLARE_ATTRIBUTE(updated_by);
    CPPORM_DECLARE_ATTRIBUTE(deleted_by);
    CPPORM_DECLARE_ATTRIBUTE(organization_id);
    CPPORM_DECLARE_ATTRIBUTE(name);
    CPPORM_DECLARE_ATTRIBUTE(description);
    CPPORM_DECLARE_INDEX(primary_key);
    CPPORM_DECLARE_INDEX(unique_organization_id_name);
    CPPORM_DECLARE_INDEX(foreign_key_created_by);
    CPPORM_DECLARE_INDEX(foreign_key_organization_id);
    CPPORM_DECLARE_INDEX(foreign_key_updated_by);
    CPPORM_DECLARE_INDEX(foreign_key_deleted_by);
    CPPORM_DECLARE_INDEX(version_fields);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(created_by_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(updated_by_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(deleted_by_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(organization_id_Organization, Organization);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_TeamMembership_team_id);
};

/*******************************************************************************
 * OrganizationType
 ******************************************************************************/
CPPORM_DECLARE_ENTITY(OrganizationType)
{
    CPPORM_DECLARE_ENTITY_METHODS;
    CPPORM_DECLARE_ATTRIBUTE(id);
    CPPORM_DECLARE_ATTRIBUTE(name);
    CPPORM_DECLARE_ATTRIBUTE(description);
    CPPORM_DECLARE_INDEX(primary_key);
    CPPORM_DECLARE_INDEX(unique_name);
    CPPORM_DECLARE_TO_MANY_RELATIONSHIP(all_Organization_type_id);
};

/*******************************************************************************
 * TeamMembership
 ******************************************************************************/
CPPORM_DECLARE_ENTITY(TeamMembership)
{
    CPPORM_DECLARE_ENTITY_METHODS;
    CPPORM_DECLARE_ATTRIBUTE(id);
    CPPORM_DECLARE_ATTRIBUTE(team_id);
    CPPORM_DECLARE_ATTRIBUTE(user_id);
    CPPORM_DECLARE_INDEX(primary_key);
    CPPORM_DECLARE_INDEX(unique_team_id_user_id);
    CPPORM_DECLARE_INDEX(foreign_key_user_id);
    CPPORM_DECLARE_INDEX(foreign_key_team_id);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(user_id_User, User);
    CPPORM_DECLARE_TO_ONE_RELATIONSHIP(team_id_Team, Team);
};

} // namespace orm
