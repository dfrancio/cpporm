CREATE TABLE epsg_alias ( 
alias_code                                         INTEGER NOT NULL, 
object_table_name                                  VARCHAR(80) NOT NULL, 
object_code                                        INTEGER NOT NULL, 
naming_system_code                                 INTEGER NOT NULL, 
alias                                              VARCHAR(80) NOT NULL, 
remarks                                            VARCHAR(254), 
CONSTRAINT pk_alias PRIMARY KEY ( alias_code ) );

CREATE TABLE epsg_area ( 
area_code                                          INTEGER NOT NULL, 
area_name                                          VARCHAR(80) NOT NULL, 
area_of_use                                        VARCHAR(4000) NOT NULL, 
area_south_bound_lat                               DOUBLE PRECISION, 
area_north_bound_lat                               DOUBLE PRECISION, 
area_west_bound_lon                                DOUBLE PRECISION, 
area_east_bound_lon                                DOUBLE PRECISION, 
area_polygon_file_ref                              VARCHAR(254), 
iso_a2_code                                        VARCHAR(2), 
iso_a3_code                                        VARCHAR(3), 
iso_n_code                                         INTEGER, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_area PRIMARY KEY ( area_code ) );

CREATE TABLE epsg_change ( 
change_id                                          DOUBLE PRECISION NOT NULL UNIQUE, 
report_date                                        DATE NOT NULL, 
date_closed                                        DATE, 
reporter                                           VARCHAR(254) NOT NULL, 
request                                            VARCHAR(254) NOT NULL, 
tables_affected                                    VARCHAR(254), 
codes_affected                                     VARCHAR(254), 
change_comment                                     VARCHAR(254), 
`action`                                             VARCHAR(4000) );

CREATE TABLE epsg_coordinateaxis ( 
coord_axis_code                                    INTEGER UNIQUE, 
coord_sys_code                                     INTEGER NOT NULL, 
coord_axis_name_code                               INTEGER NOT NULL, 
coord_axis_orientation                             VARCHAR(24) NOT NULL, 
coord_axis_abbreviation                            VARCHAR(24) NOT NULL, 
uom_code                                           INTEGER NOT NULL, 
coord_axis_order                                   SMALLINT NOT NULL, 
CONSTRAINT pk_coordinateaxis PRIMARY KEY ( coord_sys_code, coord_axis_name_code ) );

CREATE TABLE epsg_coordinateaxisname ( 
coord_axis_name_code                               INTEGER NOT NULL, 
coord_axis_name                                    VARCHAR(80) NOT NULL, 
description                                        VARCHAR(254), 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_coordinateaxisname PRIMARY KEY ( coord_axis_name_code ) );

CREATE TABLE epsg_coordinatereferencesystem ( 
coord_ref_sys_code                                 INTEGER NOT NULL, 
coord_ref_sys_name                                 VARCHAR(80) NOT NULL, 
area_of_use_code                                   INTEGER NOT NULL, 
coord_ref_sys_kind                                 VARCHAR(24) NOT NULL, 
coord_sys_code                                     INTEGER, 
datum_code                                         INTEGER, 
source_geogcrs_code                                INTEGER, 
projection_conv_code                               INTEGER, 
cmpd_horizcrs_code                                 INTEGER, 
cmpd_vertcrs_code                                  INTEGER, 
crs_scope                                          VARCHAR(254) NOT NULL, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
show_crs                                           SMALLINT NOT NULL, 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_coordinatereferencesystem PRIMARY KEY ( coord_ref_sys_code ) );

CREATE TABLE epsg_coordinatesystem ( 
coord_sys_code                                     INTEGER NOT NULL, 
coord_sys_name                                     VARCHAR(254) NOT NULL, 
coord_sys_type                                     VARCHAR(24) NOT NULL, 
dimension                                          SMALLINT NOT NULL, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(50) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_coordinatesystem PRIMARY KEY ( coord_sys_code ) );

CREATE TABLE epsg_coordoperation ( 
coord_op_code                                      INTEGER NOT NULL, 
coord_op_name                                      VARCHAR(80) NOT NULL, 
coord_op_type                                      VARCHAR(24) NOT NULL, 
source_crs_code                                    INTEGER, 
target_crs_code                                    INTEGER, 
coord_tfm_version                                  VARCHAR(24), 
coord_op_variant                                   SMALLINT, 
area_of_use_code                                   INTEGER NOT NULL, 
coord_op_scope                                     VARCHAR(254) NOT NULL, 
coord_op_accuracy                                  FLOAT, 
coord_op_method_code                               INTEGER, 
uom_code_source_coord_diff                         INTEGER, 
uom_code_target_coord_diff                         INTEGER, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
show_operation                                     SMALLINT NOT NULL, 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_coordinate_operation PRIMARY KEY ( coord_op_code ) );

CREATE TABLE epsg_coordoperationmethod ( 
coord_op_method_code                               INTEGER NOT NULL, 
coord_op_method_name                               VARCHAR(50) NOT NULL, 
reverse_op                                         SMALLINT NOT NULL, 
formula                                            VARCHAR(4000), 
example                                            VARCHAR(4000), 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_coordinate_operationmethod PRIMARY KEY ( coord_op_method_code ) );

CREATE TABLE epsg_coordoperationparam ( 
parameter_code                                     INTEGER NOT NULL, 
parameter_name                                     VARCHAR(80) NOT NULL, 
description                                        VARCHAR(4000), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_coordinate_operationparamet PRIMARY KEY ( parameter_code ) );

CREATE TABLE epsg_coordoperationparamusage ( 
coord_op_method_code                               INTEGER NOT NULL, 
parameter_code                                     INTEGER NOT NULL, 
sort_order                                         SMALLINT NOT NULL, 
param_sign_reversal                                VARCHAR(3), 
CONSTRAINT pk_coordinate_operationparame2 PRIMARY KEY ( parameter_code, coord_op_method_code ) );

CREATE TABLE epsg_coordoperationparamvalue ( 
coord_op_code                                      INTEGER NOT NULL, 
coord_op_method_code                               INTEGER NOT NULL, 
parameter_code                                     INTEGER NOT NULL, 
parameter_value                                    DOUBLE PRECISION, 
param_value_file_ref                               VARCHAR(254), 
uom_code                                           INTEGER, 
CONSTRAINT pk_coordinate_operationparame3 PRIMARY KEY ( coord_op_code, parameter_code, coord_op_method_code ) );

CREATE TABLE epsg_coordoperationpath ( 
concat_operation_code                              INTEGER NOT NULL, 
single_operation_code                              INTEGER NOT NULL, 
op_path_step                                       SMALLINT NOT NULL, 
CONSTRAINT pk_coordinate_operationpath PRIMARY KEY ( concat_operation_code, single_operation_code ) );

CREATE TABLE epsg_datum ( 
datum_code                                         INTEGER NOT NULL, 
datum_name                                         VARCHAR(80) NOT NULL, 
datum_type                                         VARCHAR(24) NOT NULL, 
origin_description                                 VARCHAR(254), 
realization_epoch                                  VARCHAR(10), 
ellipsoid_code                                     INTEGER, 
prime_meridian_code                                INTEGER, 
area_of_use_code                                   INTEGER NOT NULL, 
datum_scope                                        VARCHAR(254) NOT NULL, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_datum PRIMARY KEY ( datum_code ) );

CREATE TABLE epsg_deprecation ( 
deprecation_id                                     INTEGER, 
deprecation_date                                   DATE, 
change_id                                          DOUBLE PRECISION NOT NULL, 
object_table_name                                  VARCHAR(80), 
object_code                                        INTEGER, 
replaced_by                                        INTEGER, 
deprecation_reason                                 VARCHAR(254), 
CONSTRAINT pk_deprecation PRIMARY KEY ( deprecation_id ) );

CREATE TABLE epsg_ellipsoid ( 
ellipsoid_code                                     INTEGER NOT NULL, 
ellipsoid_name                                     VARCHAR(80) NOT NULL, 
semi_major_axis                                    DOUBLE PRECISION NOT NULL, 
uom_code                                           INTEGER NOT NULL, 
inv_flattening                                     DOUBLE PRECISION, 
semi_minor_axis                                    DOUBLE PRECISION, 
ellipsoid_shape                                    SMALLINT NOT NULL, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_ellipsoid PRIMARY KEY ( ellipsoid_code ) );

CREATE TABLE epsg_namingsystem ( 
naming_system_code                                 INTEGER NOT NULL, 
naming_system_name                                 VARCHAR(80) NOT NULL, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_namingsystem PRIMARY KEY ( naming_system_code ) );

CREATE TABLE epsg_primemeridian ( 
prime_meridian_code                                INTEGER NOT NULL, 
prime_meridian_name                                VARCHAR(80) NOT NULL, 
greenwich_longitude                                DOUBLE PRECISION NOT NULL, 
uom_code                                           INTEGER NOT NULL, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_primemeridian PRIMARY KEY ( prime_meridian_code ) );

CREATE TABLE epsg_supersession ( 
supersession_id                                    INTEGER, 
object_table_name                                  VARCHAR(80) NOT NULL, 
object_code                                        INTEGER NOT NULL, 
superseded_by                                      INTEGER, 
supersession_type                                  VARCHAR(50), 
supersession_year                                  SMALLINT, 
remarks                                            VARCHAR(254), 
CONSTRAINT pk_supersession PRIMARY KEY ( supersession_id ) );

CREATE TABLE epsg_unitofmeasure ( 
uom_code                                           INTEGER NOT NULL, 
unit_of_meas_name                                  VARCHAR(80) NOT NULL, 
unit_of_meas_type                                  VARCHAR(50), 
target_uom_code                                    INTEGER NOT NULL, 
factor_b                                           DOUBLE PRECISION, 
factor_c                                           DOUBLE PRECISION, 
remarks                                            VARCHAR(254), 
information_source                                 VARCHAR(254), 
data_source                                        VARCHAR(40) NOT NULL, 
revision_date                                      DATE NOT NULL, 
change_id                                          VARCHAR(255), 
deprecated                                         SMALLINT NOT NULL, 
CONSTRAINT pk_unitofmeasure PRIMARY KEY ( uom_code ) );

CREATE TABLE epsg_versionhistory ( 
version_history_code                               INTEGER NOT NULL, 
version_date                                       DATE, 
version_number                                     VARCHAR(10) NOT NULL UNIQUE, 
version_remarks                                    VARCHAR(254) NOT NULL, 
superceded_by                                      VARCHAR(10), 
supercedes                                         VARCHAR(10), 
CONSTRAINT pk_versionhistory PRIMARY KEY ( version_history_code ) );

ALTER TABLE epsg_coordoperation ADD CONSTRAINT fk_uom_code_target_coord_diff FOREIGN KEY 
( uom_code_target_coord_diff ) REFERENCES epsg_unitofmeasure ( uom_code ) ; 

ALTER TABLE epsg_coordoperationparamusage ADD CONSTRAINT fk_parameter_code FOREIGN KEY 
( parameter_code ) REFERENCES epsg_coordoperationparam ( parameter_code ) ; 

ALTER TABLE epsg_unitofmeasure ADD CONSTRAINT fk_target_uom_code FOREIGN KEY 
( target_uom_code ) REFERENCES epsg_unitofmeasure ( uom_code ) ; 

ALTER TABLE epsg_deprecation ADD CONSTRAINT fk_change_id FOREIGN KEY 
( change_id ) REFERENCES epsg_change ( change_id ) ; 

ALTER TABLE epsg_datum ADD CONSTRAINT fk_ellipsoid_code FOREIGN KEY 
( ellipsoid_code ) REFERENCES epsg_ellipsoid ( ellipsoid_code ) ; 

ALTER TABLE epsg_primemeridian ADD CONSTRAINT fk_uom_code FOREIGN KEY 
( uom_code ) REFERENCES epsg_unitofmeasure ( uom_code ) ; 

ALTER TABLE epsg_coordinateaxis ADD CONSTRAINT fk_uom_code2 FOREIGN KEY 
( uom_code ) REFERENCES epsg_unitofmeasure ( uom_code ) ; 

ALTER TABLE epsg_coordinatereferencesystem ADD CONSTRAINT fk_cmpd_horizcrs_code FOREIGN KEY 
( cmpd_horizcrs_code ) REFERENCES epsg_coordinatereferencesystem ( coord_ref_sys_code ) ; 

ALTER TABLE epsg_coordoperation ADD CONSTRAINT fk_coord_op_method_code FOREIGN KEY 
( coord_op_method_code ) REFERENCES epsg_coordoperationmethod ( coord_op_method_code ) ; 

ALTER TABLE epsg_coordinatereferencesystem ADD CONSTRAINT fk_datum_code FOREIGN KEY 
( datum_code ) REFERENCES epsg_datum ( datum_code ) ; 

ALTER TABLE epsg_datum ADD CONSTRAINT fk_prime_meridian_code FOREIGN KEY 
( prime_meridian_code ) REFERENCES epsg_primemeridian ( prime_meridian_code ) ; 

ALTER TABLE epsg_coordoperationparamvalue ADD CONSTRAINT fk_uom_code3 FOREIGN KEY 
( uom_code ) REFERENCES epsg_unitofmeasure ( uom_code ) ; 

ALTER TABLE epsg_coordinatereferencesystem ADD CONSTRAINT fk_area_of_use_code FOREIGN KEY 
( area_of_use_code ) REFERENCES epsg_area ( area_code ) ; 

ALTER TABLE epsg_coordinateaxis ADD CONSTRAINT fk_coord_axis_name_code FOREIGN KEY 
( coord_axis_name_code ) REFERENCES epsg_coordinateaxisname ( coord_axis_name_code ) ; 

ALTER TABLE epsg_coordoperation ADD CONSTRAINT fk_uom_code_source_coord_diff FOREIGN KEY 
( uom_code_source_coord_diff ) REFERENCES epsg_unitofmeasure ( uom_code ) ; 

ALTER TABLE epsg_coordoperationparamvalue ADD CONSTRAINT fk_parameter_codecoord_op_meth FOREIGN KEY 
( parameter_code, coord_op_method_code ) REFERENCES epsg_coordoperationparamusage ( parameter_code, coord_op_method_code ) ; 

ALTER TABLE epsg_coordoperation ADD CONSTRAINT fk_source_crs_code FOREIGN KEY 
( source_crs_code ) REFERENCES epsg_coordinatereferencesystem ( coord_ref_sys_code ) ; 

ALTER TABLE epsg_coordoperationpath ADD CONSTRAINT fk_concat_operation_code FOREIGN KEY 
( concat_operation_code ) REFERENCES epsg_coordoperation ( coord_op_code ) ; 

ALTER TABLE epsg_coordinateaxis ADD CONSTRAINT fk_coord_sys_code FOREIGN KEY 
( coord_sys_code ) REFERENCES epsg_coordinatesystem ( coord_sys_code ) ; 

ALTER TABLE epsg_coordoperationpath ADD CONSTRAINT fk_single_operation_code FOREIGN KEY 
( single_operation_code ) REFERENCES epsg_coordoperation ( coord_op_code ) ; 

ALTER TABLE epsg_coordinatereferencesystem ADD CONSTRAINT fk_coord_sys_code2 FOREIGN KEY 
( coord_sys_code ) REFERENCES epsg_coordinatesystem ( coord_sys_code ) ; 

ALTER TABLE epsg_coordinatereferencesystem ADD CONSTRAINT fk_cmpd_vertcrs_code FOREIGN KEY 
( cmpd_vertcrs_code ) REFERENCES epsg_coordinatereferencesystem ( coord_ref_sys_code ) ; 

ALTER TABLE epsg_coordinatereferencesystem ADD CONSTRAINT fk_source_geogcrs_code FOREIGN KEY 
( source_geogcrs_code ) REFERENCES epsg_coordinatereferencesystem ( coord_ref_sys_code ) ; 

ALTER TABLE epsg_coordoperation ADD CONSTRAINT fk_target_crs_code FOREIGN KEY 
( target_crs_code ) REFERENCES epsg_coordinatereferencesystem ( coord_ref_sys_code ) ; 

ALTER TABLE epsg_datum ADD CONSTRAINT fk_area_of_use_code2 FOREIGN KEY 
( area_of_use_code ) REFERENCES epsg_area ( area_code ) ; 

ALTER TABLE epsg_alias ADD CONSTRAINT fk_naming_system_code FOREIGN KEY 
( naming_system_code ) REFERENCES epsg_namingsystem ( naming_system_code ) ; 

ALTER TABLE epsg_coordoperation ADD CONSTRAINT fk_area_of_use_code3 FOREIGN KEY 
( area_of_use_code ) REFERENCES epsg_area ( area_code ) ; 

ALTER TABLE epsg_coordoperationparamvalue ADD CONSTRAINT fk_coord_op_code FOREIGN KEY 
( coord_op_code ) REFERENCES epsg_coordoperation ( coord_op_code ) ; 

ALTER TABLE epsg_ellipsoid ADD CONSTRAINT fk_uom_code4 FOREIGN KEY 
( uom_code ) REFERENCES epsg_unitofmeasure ( uom_code ) ; 

ALTER TABLE epsg_coordoperationparamusage ADD CONSTRAINT fk_coord_op_method_code2 FOREIGN KEY 
( coord_op_method_code ) REFERENCES epsg_coordoperationmethod ( coord_op_method_code ) ; 

