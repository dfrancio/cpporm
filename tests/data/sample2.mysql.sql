SET FOREIGN_KEY_CHECKS = 0;
DROP TABLE IF EXISTS `User`;
DROP TABLE IF EXISTS `Organization`;
DROP TABLE IF EXISTS `Team`;
DROP TABLE IF EXISTS `Locale`;
DROP TABLE IF EXISTS `City`;
DROP TABLE IF EXISTS `State`;
DROP TABLE IF EXISTS `Country`;
DROP TABLE IF EXISTS `Contract`;
DROP TABLE IF EXISTS `Farm`;
DROP TABLE IF EXISTS `Unit`;
DROP TABLE IF EXISTS `Quantity`;
DROP TABLE IF EXISTS `DefaultUnit`;
DROP TABLE IF EXISTS `ContractParty`;
DROP TABLE IF EXISTS `ContractType`;
DROP TABLE IF EXISTS `Phone`;
DROP TABLE IF EXISTS `PhoneType`;
DROP TABLE IF EXISTS `OrganizationType`;
DROP TABLE IF EXISTS `Address`;
DROP TABLE IF EXISTS `AddressType`;
DROP TABLE IF EXISTS `Wage`;
DROP TABLE IF EXISTS `Field`;
DROP TABLE IF EXISTS `Crop`;
DROP TABLE IF EXISTS `Tillage`;
DROP TABLE IF EXISTS `Culture`;
DROP TABLE IF EXISTS `CultureVariety`;
DROP TABLE IF EXISTS `Document`;
DROP TABLE IF EXISTS `Equipment`;
DROP TABLE IF EXISTS `EquipmentType`;
DROP TABLE IF EXISTS `Manufacturer`;
DROP TABLE IF EXISTS `Boundary`;
DROP TABLE IF EXISTS `ProductUsage`;
DROP TABLE IF EXISTS `Characteristic`;
DROP TABLE IF EXISTS `CharacteristicType`;
DROP TABLE IF EXISTS `Price`;
DROP TABLE IF EXISTS `TeamMembership`;
DROP TABLE IF EXISTS `Variable`;
DROP TABLE IF EXISTS `Pest`;
DROP TABLE IF EXISTS `PestTreatment`;
DROP TABLE IF EXISTS `Grid`;
DROP TABLE IF EXISTS `Attachment`;
DROP TABLE IF EXISTS `Series`;
DROP TABLE IF EXISTS `Backdrop`;
DROP TABLE IF EXISTS `Map`;
DROP TABLE IF EXISTS `SeriesUsage`;
DROP TABLE IF EXISTS `Method`;
DROP TABLE IF EXISTS `InterpolationParameterUsage`;
DROP TABLE IF EXISTS `Formula`;
DROP TABLE IF EXISTS `ColorPalette`;
DROP TABLE IF EXISTS `ReportTemplate`;
DROP TABLE IF EXISTS `Macro`;
DROP TABLE IF EXISTS `PaletteType`;
DROP TABLE IF EXISTS `CustomProperty`;
DROP TABLE IF EXISTS `CustomPropertyValue`;
DROP TABLE IF EXISTS `CustomPropertyUsage`;
DROP TABLE IF EXISTS `FormulaOperand`;
DROP TABLE IF EXISTS `FileFormatConfiguration`;
DROP TABLE IF EXISTS `ConfigurationUsage`;
DROP TABLE IF EXISTS `FileFormat`;
DROP TABLE IF EXISTS `FileFormatCategory`;
DROP TABLE IF EXISTS `FileExtension`;
DROP TABLE IF EXISTS `FileFormatOptionUsage`;
DROP TABLE IF EXISTS `Parameter`;
DROP TABLE IF EXISTS `DataType`;
DROP TABLE IF EXISTS `ParameterRestrictionType`;
DROP TABLE IF EXISTS `ParameterRestriction`;
DROP TABLE IF EXISTS `ParameterSpecification`;
DROP TABLE IF EXISTS `MethodParameter`;
DROP TABLE IF EXISTS `FileFormatOption`;
DROP TABLE IF EXISTS `Algorithm`;
DROP TABLE IF EXISTS `AlgorithmOption`;
DROP TABLE IF EXISTS `AgronomyJob`;
DROP TABLE IF EXISTS `JobParticipation`;
DROP TABLE IF EXISTS `AgronomyOperation`;
DROP TABLE IF EXISTS `ParameterRequirement`;
DROP TABLE IF EXISTS `UserPhone`;
DROP TABLE IF EXISTS `OrganizationPhone`;
DROP TABLE IF EXISTS `UserAddress`;
DROP TABLE IF EXISTS `OrganizationAddress`;
DROP TABLE IF EXISTS `AgronomyJobAgenda`;
DROP TABLE IF EXISTS `Tooltip`;
DROP TABLE IF EXISTS `Action`;
DROP TABLE IF EXISTS `Role`;
DROP TABLE IF EXISTS `ActionRole`;
DROP TABLE IF EXISTS `LicenseTypeAction`;
DROP TABLE IF EXISTS `License`;
DROP TABLE IF EXISTS `QuotaUsage`;
DROP TABLE IF EXISTS `LicenseTerm`;
DROP TABLE IF EXISTS `QuotaLimit`;
DROP TABLE IF EXISTS `QuotaType`;
DROP TABLE IF EXISTS `LicenseType`;
DROP TABLE IF EXISTS `Machine`;
DROP TABLE IF EXISTS `AccessLog`;
SET FOREIGN_KEY_CHECKS = 1;

CREATE TABLE `User` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `name` TEXT NOT NULL,
    `email` TEXT NOT NULL,
    `preferred_locale_id` SMALLINT NOT NULL,
    `birth_date` DATE,
    `personal_id` TEXT,
    `professional_id` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`email`)
);

CREATE TABLE `Organization` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `name` TEXT NOT NULL,
    `type_id` SMALLINT NOT NULL,
    `legal_id` TEXT,
    `legal_name` TEXT,
    `description` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `Team` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `organization_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT,
    `role_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`organization_id`, `name`)
);

CREATE TABLE `Locale` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `City` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `state_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    `latitude` DOUBLE NOT NULL,
    `longitude` DOUBLE NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`state_id`, `name`)
);

CREATE TABLE `State` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `country_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    `acronym` TEXT NOT NULL,
    `area_code` SMALLINT,
    PRIMARY KEY (`id`),
    UNIQUE (`country_id`, `name`)
);

CREATE TABLE `Country` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `iso_code` TEXT NOT NULL,
    `name` TEXT NOT NULL,
    `calling_code` SMALLINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`iso_code`)
);

CREATE TABLE `Contract` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `farm_id` BIGINT,
    `type_id` SMALLINT NOT NULL,
    `start_date` DATE NOT NULL,
    `end_date` DATE,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Farm` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `organization_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`organization_id`, `name`)
);

CREATE TABLE `Unit` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `name` TEXT NOT NULL,
    `symbol` TEXT NOT NULL,
    `quantity_id` BIGINT NOT NULL,
    `multiplier` DOUBLE NOT NULL,
    `additive_factor` DOUBLE NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `symbol`)
);

CREATE TABLE `Quantity` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `name` TEXT NOT NULL,
    `si_unit_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `name`)
);

CREATE TABLE `DefaultUnit` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `quantity_id` BIGINT NOT NULL,
    `unit_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `quantity_id`)
);

CREATE TABLE `ContractParty` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `contract_id` BIGINT NOT NULL,
    `party_id` BIGINT NOT NULL,
    `organization_id` BIGINT,
    PRIMARY KEY (`id`),
    UNIQUE (`contract_id`, `party_id`)
);

CREATE TABLE `ContractType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `Phone` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `state_id` BIGINT NOT NULL,
    `number` TEXT NOT NULL,
    `type_id` SMALLINT NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `PhoneType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `OrganizationType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `Address` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `city_id` BIGINT NOT NULL,
    `zip_code` TEXT NOT NULL,
    `type_id` SMALLINT NOT NULL,
    `line1` TEXT NOT NULL,
    `line2` TEXT,
    `line3` TEXT,
    `line4` TEXT,
    `line5` TEXT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `AddressType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `Wage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `contract_party_id` BIGINT NOT NULL,
    `value` DOUBLE NOT NULL,
    `currency_id` BIGINT NOT NULL,
    `period_days` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Field` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `farm_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    `boundary_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`farm_id`, `name`)
);

CREATE TABLE `Crop` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `organization_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`organization_id`, `name`)
);

CREATE TABLE `Tillage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `crop_id` BIGINT NOT NULL,
    `field_id` BIGINT NOT NULL,
    `culture_id` BIGINT NOT NULL,
    `start_date` DATE NOT NULL,
    `end_date` DATE,
    PRIMARY KEY (`id`),
    UNIQUE (`crop_id`, `field_id`, `culture_id`)
);

CREATE TABLE `Culture` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `name` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `name`)
);

CREATE TABLE `CultureVariety` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `culture_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`culture_id`, `name`)
);

CREATE TABLE `Document` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `path` TEXT NOT NULL,
    `checksum` BINARY(32) NOT NULL,
    `size_bytes` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`path`)
);

CREATE TABLE `Equipment` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `organization_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    `serial_number` TEXT NOT NULL,
    `type_id` SMALLINT NOT NULL,
    `manufacturer_id` BIGINT,
    PRIMARY KEY (`id`),
    UNIQUE (`organization_id`, `serial_number`)
);

CREATE TABLE `EquipmentType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `Manufacturer` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `Boundary` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `field_id` BIGINT NOT NULL,
    `area` DOUBLE NOT NULL,
    `perimeter` DOUBLE NOT NULL,
    `min_lat` DOUBLE NOT NULL,
    `min_long` DOUBLE NOT NULL,
    `max_lat` DOUBLE NOT NULL,
    `max_long` DOUBLE NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `ProductUsage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `agenda_id` BIGINT NOT NULL,
    `variable_id` BIGINT NOT NULL,
    `value` DOUBLE NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Characteristic` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT,
    `type_id` SMALLINT NOT NULL,
    `quantity_id` BIGINT NOT NULL,
    `variety_id` BIGINT,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `name`)
);

CREATE TABLE `CharacteristicType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `Price` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `variable_id` BIGINT NOT NULL,
    `currency_id` BIGINT NOT NULL,
    `value` DOUBLE NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `variable_id`)
);

CREATE TABLE `TeamMembership` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `team_id` BIGINT NOT NULL,
    `user_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`team_id`, `user_id`)
);

CREATE TABLE `Variable` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `characteristic_id` BIGINT NOT NULL,
    `unit_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`characteristic_id`, `unit_id`)
);

CREATE TABLE `Pest` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT,
    `species` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `name`)
);

CREATE TABLE `PestTreatment` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `pest_id` BIGINT NOT NULL,
    `product_id` BIGINT NOT NULL,
    `notes` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`pest_id`, `product_id`)
);

CREATE TABLE `Grid` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `boundary_id` BIGINT NOT NULL,
    `min_lat` DOUBLE NOT NULL,
    `min_long` DOUBLE NOT NULL,
    `cell_width` DOUBLE,
    `cell_height` DOUBLE,
    `angle_degrees` DOUBLE,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Attachment` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `crop_id` BIGINT,
    `farm_id` BIGINT,
    `organization_id` BIGINT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Series` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `grid_id` BIGINT NOT NULL,
    `variable_id` BIGINT NOT NULL,
    `minimum` DOUBLE NOT NULL,
    `maximum` DOUBLE NOT NULL,
    `average` DOUBLE NOT NULL,
    `median` DOUBLE NOT NULL,
    `stddev` DOUBLE NOT NULL,
    `sum` DOUBLE NOT NULL,
    `equipment_id` BIGINT,
    `laboratory_id` BIGINT,
    `collection_date` DATE,
    `degree` SMALLINT,
    `method_id` SMALLINT,
    `formula_id` BIGINT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Backdrop` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `field_id` BIGINT NOT NULL,
    `width` INTEGER NOT NULL,
    `height` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Map` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `tillage_id` BIGINT,
    `width` INTEGER NOT NULL,
    `height` INTEGER NOT NULL,
    `pixel_width` DOUBLE NOT NULL,
    `pixel_height` DOUBLE NOT NULL,
    `field_id` BIGINT,
    `equipment_id` BIGINT,
    `origin_series_id` BIGINT,
    `origin_map_id` BIGINT,
    `palette_id` BIGINT,
    `method_id` SMALLINT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `SeriesUsage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `input_series_id` BIGINT NOT NULL,
    `output_series_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`input_series_id`, `output_series_id`)
);

CREATE TABLE `Method` (
    `id` SMALLINT NOT NULL,
    `algorithm_id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`algorithm_id`, `name`)
);

CREATE TABLE `InterpolationParameterUsage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `series_id` BIGINT NOT NULL,
    `parameter_id` BIGINT NOT NULL,
    `value` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`series_id`, `parameter_id`)
);

CREATE TABLE `Formula` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `ColorPalette` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `variable_id` BIGINT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `ReportTemplate` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `is_portrait` TINYINT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Macro` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `document_id` BIGINT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`)
);

CREATE TABLE `PaletteType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `CustomProperty` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `table_name` TEXT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `table_name`, `name`)
);

CREATE TABLE `CustomPropertyValue` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `property_id` BIGINT NOT NULL,
    `value` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `property_id`, `value`)
);

CREATE TABLE `CustomPropertyUsage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `value_id` BIGINT NOT NULL,
    `object_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`created_by`, `value_id`, `object_id`)
);

CREATE TABLE `FormulaOperand` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `formula_id` BIGINT NOT NULL,
    `is_output` TINYINT NOT NULL,
    `port` SMALLINT NOT NULL,
    `unit_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`formula_id`, `is_output`, `port`)
);

CREATE TABLE `FileFormatConfiguration` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `file_format_id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `ConfigurationUsage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `configuration_id` BIGINT NOT NULL,
    `macro_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`configuration_id`, `macro_id`)
);

CREATE TABLE `FileFormat` (
    `id` SMALLINT NOT NULL,
    `category_id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`category_id`, `name`)
);

CREATE TABLE `FileFormatCategory` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `FileExtension` (
    `id` SMALLINT NOT NULL,
    `file_format_id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`file_format_id`, `name`)
);

CREATE TABLE `FileFormatOptionUsage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `configuration_id` BIGINT NOT NULL,
    `option_id` BIGINT NOT NULL,
    `value` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`configuration_id`, `option_id`)
);

CREATE TABLE `Parameter` (
    `id` SMALLINT NOT NULL,
    `tag` TEXT NOT NULL,
    `name` TEXT NOT NULL,
    `datatype_id` SMALLINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`tag`)
);

CREATE TABLE `DataType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `ParameterRestrictionType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `ParameterRestriction` (
    `id` SMALLINT NOT NULL,
    `parameter_id` SMALLINT NOT NULL,
    `type_id` SMALLINT NOT NULL,
    `value` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`parameter_id`, `type_id`)
);

CREATE TABLE `ParameterSpecification` (
    `id` SMALLINT NOT NULL,
    `parameter_id` SMALLINT NOT NULL,
    `default_value` TEXT NOT NULL,
    `is_mandatory` TINYINT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`default_value`)
);

CREATE TABLE `MethodParameter` (
    `id` SMALLINT NOT NULL,
    `method_id` SMALLINT NOT NULL,
    `specification_id` SMALLINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`method_id`, `specification_id`)
);

CREATE TABLE `FileFormatOption` (
    `id` SMALLINT NOT NULL,
    `file_format_id` SMALLINT NOT NULL,
    `specification_id` SMALLINT NOT NULL,
    `is_layer` TINYINT NOT NULL,
    `is_import` TINYINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`file_format_id`, `specification_id`, `is_layer`, `is_import`)
);

CREATE TABLE `Algorithm` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    `input_category_id` SMALLINT,
    `output_category_id` SMALLINT,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `AlgorithmOption` (
    `id` SMALLINT NOT NULL,
    `algorithm_id` SMALLINT NOT NULL,
    `specification_id` SMALLINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`algorithm_id`, `specification_id`)
);

CREATE TABLE `AgronomyJob` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `tillage_id` BIGINT NOT NULL,
    `operation_id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `JobParticipation` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `user_id` BIGINT NOT NULL,
    `job_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`user_id`, `job_id`)
);

CREATE TABLE `AgronomyOperation` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `ParameterRequirement` (
    `id` SMALLINT NOT NULL,
    `parameter_id` SMALLINT NOT NULL,
    `required_id` SMALLINT NOT NULL,
    `value` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`parameter_id`, `required_id`)
);

CREATE TABLE `UserPhone` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `user_id` BIGINT NOT NULL,
    `phone_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`user_id`, `phone_id`)
);

CREATE TABLE `OrganizationPhone` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `organization_id` BIGINT NOT NULL,
    `phone_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`organization_id`, `phone_id`)
);

CREATE TABLE `UserAddress` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `user_id` BIGINT NOT NULL,
    `address_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`user_id`, `address_id`)
);

CREATE TABLE `OrganizationAddress` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `organization_id` BIGINT NOT NULL,
    `address_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`organization_id`, `address_id`)
);

CREATE TABLE `AgronomyJobAgenda` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `job_id` BIGINT NOT NULL,
    `is_estimated` TINYINT NOT NULL,
    `start_date` DATE NOT NULL,
    `end_date` DATE,
    `cost` DOUBLE NOT NULL,
    `currency_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`job_id`, `is_estimated`)
);

CREATE TABLE `Tooltip` (
    `id` SMALLINT NOT NULL,
    `table_name` TEXT NOT NULL,
    `column_name` TEXT NOT NULL,
    `value` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`table_name`, `column_name`)
);

CREATE TABLE `Action` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `name` TEXT NOT NULL,
    `controller` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`, `controller`)
);

CREATE TABLE `Role` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `ActionRole` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `action_id` BIGINT NOT NULL,
    `role_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`action_id`, `role_id`)
);

CREATE TABLE `LicenseTypeAction` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `action_id` BIGINT NOT NULL,
    `type_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`action_id`, `type_id`)
);

CREATE TABLE `License` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `organization_id` BIGINT NOT NULL,
    `serial_key` CHAR(25) NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`serial_key`)
);

CREATE TABLE `QuotaUsage` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `created_by` BIGINT NOT NULL,
    `term_id` BIGINT NOT NULL,
    `type_id` SMALLINT NOT NULL,
    `value` DOUBLE NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `LicenseTerm` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `license_id` BIGINT NOT NULL,
    `type_id` BIGINT NOT NULL,
    `expiry_date` DATE NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `QuotaLimit` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `created_by` BIGINT NOT NULL,
    `term_id` BIGINT NOT NULL,
    `type_id` SMALLINT NOT NULL,
    `value` DOUBLE NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `QuotaType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `LicenseType` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `Machine` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `deleted_at` DATETIME DEFAULT NULL,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT DEFAULT NULL,
    `machine_id` TEXT NOT NULL,
    `operating_system` TEXT NOT NULL,
    `processor_id` TEXT NOT NULL,
    `motherboard_id` TEXT NOT NULL,
    `mac_address` TEXT NOT NULL,
    `details` TEXT NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE `AccessLog` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `created_by` BIGINT NOT NULL,
    `machine_id` BIGINT NOT NULL,
    `ip_address` TEXT NOT NULL,
    `operating_system` TEXT NOT NULL,
    `architecture` TEXT NOT NULL,
    `ram_megabytes` INTEGER NOT NULL,
    `sw_version` TEXT NOT NULL,
    PRIMARY KEY (`id`)
);

ALTER TABLE `User` ADD FOREIGN KEY (`preferred_locale_id`) REFERENCES `Locale`(`id`);
ALTER TABLE `User` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `User` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `User` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Organization` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Organization` ADD FOREIGN KEY (`type_id`) REFERENCES `OrganizationType`(`id`);
ALTER TABLE `Organization` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Organization` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Team` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Team` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `Team` ADD FOREIGN KEY (`role_id`) REFERENCES `Role`(`id`);
ALTER TABLE `Team` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Team` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `City` ADD FOREIGN KEY (`state_id`) REFERENCES `State`(`id`);
ALTER TABLE `State` ADD FOREIGN KEY (`country_id`) REFERENCES `Country`(`id`);
ALTER TABLE `Contract` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Contract` ADD FOREIGN KEY (`type_id`) REFERENCES `ContractType`(`id`);
ALTER TABLE `Contract` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Contract` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Farm` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Farm` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `Farm` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Farm` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Unit` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Unit` ADD FOREIGN KEY (`quantity_id`) REFERENCES `Quantity`(`id`);
ALTER TABLE `Unit` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Unit` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Quantity` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Quantity` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Quantity` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Quantity` ADD FOREIGN KEY (`si_unit_id`) REFERENCES `Unit`(`id`);
ALTER TABLE `DefaultUnit` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `DefaultUnit` ADD FOREIGN KEY (`unit_id`) REFERENCES `Unit`(`id`);
ALTER TABLE `DefaultUnit` ADD FOREIGN KEY (`quantity_id`) REFERENCES `Quantity`(`id`);
ALTER TABLE `DefaultUnit` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `DefaultUnit` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `ContractParty` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `ContractParty` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `ContractParty` ADD FOREIGN KEY (`contract_id`) REFERENCES `Contract`(`id`);
ALTER TABLE `ContractParty` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `ContractParty` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `ContractParty` ADD FOREIGN KEY (`party_id`) REFERENCES `User`(`id`);
ALTER TABLE `Phone` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Phone` ADD FOREIGN KEY (`type_id`) REFERENCES `PhoneType`(`id`);
ALTER TABLE `Phone` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Phone` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Address` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Address` ADD FOREIGN KEY (`city_id`) REFERENCES `City`(`id`);
ALTER TABLE `Address` ADD FOREIGN KEY (`type_id`) REFERENCES `AddressType`(`id`);
ALTER TABLE `Address` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Address` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Wage` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Wage` ADD FOREIGN KEY (`currency_id`) REFERENCES `Unit`(`id`);
ALTER TABLE `Wage` ADD FOREIGN KEY (`contract_party_id`) REFERENCES `ContractParty`(`id`);
ALTER TABLE `Wage` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Wage` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Field` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Field` ADD FOREIGN KEY (`farm_id`) REFERENCES `Farm`(`id`);
ALTER TABLE `Field` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Field` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Crop` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Crop` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `Crop` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Crop` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Tillage` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Tillage` ADD FOREIGN KEY (`field_id`) REFERENCES `Field`(`id`);
ALTER TABLE `Tillage` ADD FOREIGN KEY (`crop_id`) REFERENCES `Crop`(`id`);
ALTER TABLE `Tillage` ADD FOREIGN KEY (`culture_id`) REFERENCES `Culture`(`id`);
ALTER TABLE `Tillage` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Tillage` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Culture` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Culture` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Culture` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `CultureVariety` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `CultureVariety` ADD FOREIGN KEY (`culture_id`) REFERENCES `Culture`(`id`);
ALTER TABLE `CultureVariety` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `CultureVariety` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Equipment` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Equipment` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `Equipment` ADD FOREIGN KEY (`type_id`) REFERENCES `EquipmentType`(`id`);
ALTER TABLE `Equipment` ADD FOREIGN KEY (`manufacturer_id`) REFERENCES `Manufacturer`(`id`);
ALTER TABLE `Equipment` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Equipment` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Boundary` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Boundary` ADD FOREIGN KEY (`field_id`) REFERENCES `Field`(`id`);
ALTER TABLE `Boundary` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `Boundary` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Boundary` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `ProductUsage` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `ProductUsage` ADD FOREIGN KEY (`variable_id`) REFERENCES `Variable`(`id`);
ALTER TABLE `ProductUsage` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `ProductUsage` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Characteristic` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Characteristic` ADD FOREIGN KEY (`quantity_id`) REFERENCES `Quantity`(`id`);
ALTER TABLE `Characteristic` ADD FOREIGN KEY (`variety_id`) REFERENCES `CultureVariety`(`id`);
ALTER TABLE `Characteristic` ADD FOREIGN KEY (`type_id`) REFERENCES `CharacteristicType`(`id`);
ALTER TABLE `Characteristic` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Characteristic` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Price` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Price` ADD FOREIGN KEY (`currency_id`) REFERENCES `Unit`(`id`);
ALTER TABLE `Price` ADD FOREIGN KEY (`variable_id`) REFERENCES `Variable`(`id`);
ALTER TABLE `Price` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Price` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `TeamMembership` ADD FOREIGN KEY (`user_id`) REFERENCES `User`(`id`);
ALTER TABLE `TeamMembership` ADD FOREIGN KEY (`team_id`) REFERENCES `Team`(`id`);
ALTER TABLE `Variable` ADD FOREIGN KEY (`unit_id`) REFERENCES `Unit`(`id`);
ALTER TABLE `Variable` ADD FOREIGN KEY (`characteristic_id`) REFERENCES `Characteristic`(`id`);
ALTER TABLE `Pest` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Pest` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Pest` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `PestTreatment` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `PestTreatment` ADD FOREIGN KEY (`product_id`) REFERENCES `Characteristic`(`id`);
ALTER TABLE `PestTreatment` ADD FOREIGN KEY (`pest_id`) REFERENCES `Pest`(`id`);
ALTER TABLE `PestTreatment` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `PestTreatment` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Grid` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Grid` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `Grid` ADD FOREIGN KEY (`boundary_id`) REFERENCES `Boundary`(`id`);
ALTER TABLE `Grid` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Grid` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Attachment` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Attachment` ADD FOREIGN KEY (`farm_id`) REFERENCES `Farm`(`id`);
ALTER TABLE `Attachment` ADD FOREIGN KEY (`crop_id`) REFERENCES `Crop`(`id`);
ALTER TABLE `Attachment` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `Attachment` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Attachment` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Attachment` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`laboratory_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`equipment_id`) REFERENCES `Equipment`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`variable_id`) REFERENCES `Variable`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`grid_id`) REFERENCES `Grid`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`formula_id`) REFERENCES `Formula`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Series` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Backdrop` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Backdrop` ADD FOREIGN KEY (`field_id`) REFERENCES `Field`(`id`);
ALTER TABLE `Backdrop` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `Backdrop` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Backdrop` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`field_id`) REFERENCES `Field`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`tillage_id`) REFERENCES `Tillage`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`equipment_id`) REFERENCES `Equipment`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`origin_series_id`) REFERENCES `Series`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`method_id`) REFERENCES `Method`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`palette_id`) REFERENCES `ColorPalette`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Map` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `SeriesUsage` ADD FOREIGN KEY (`input_series_id`) REFERENCES `Series`(`id`);
ALTER TABLE `SeriesUsage` ADD FOREIGN KEY (`output_series_id`) REFERENCES `Series`(`id`);
ALTER TABLE `Method` ADD FOREIGN KEY (`algorithm_id`) REFERENCES `Algorithm`(`id`);
ALTER TABLE `InterpolationParameterUsage` ADD FOREIGN KEY (`series_id`) REFERENCES `Series`(`id`);
ALTER TABLE `InterpolationParameterUsage` ADD FOREIGN KEY (`parameter_id`) REFERENCES `Parameter`(`id`);
ALTER TABLE `Formula` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Formula` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `Formula` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Formula` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `ColorPalette` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `ColorPalette` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `ColorPalette` ADD FOREIGN KEY (`variable_id`) REFERENCES `Variable`(`id`);
ALTER TABLE `ColorPalette` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `ColorPalette` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `ReportTemplate` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `ReportTemplate` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `ReportTemplate` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `ReportTemplate` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `Macro` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Macro` ADD FOREIGN KEY (`document_id`) REFERENCES `Document`(`id`);
ALTER TABLE `Macro` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Macro` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomProperty` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomProperty` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomProperty` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomPropertyValue` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomPropertyValue` ADD FOREIGN KEY (`property_id`) REFERENCES `CustomProperty`(`id`);
ALTER TABLE `CustomPropertyValue` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomPropertyValue` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomPropertyUsage` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomPropertyUsage` ADD FOREIGN KEY (`value_id`) REFERENCES `CustomPropertyValue`(`id`);
ALTER TABLE `CustomPropertyUsage` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `CustomPropertyUsage` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `FormulaOperand` ADD FOREIGN KEY (`unit_id`) REFERENCES `Unit`(`id`);
ALTER TABLE `FormulaOperand` ADD FOREIGN KEY (`formula_id`) REFERENCES `Formula`(`id`);
ALTER TABLE `FileFormatConfiguration` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `FileFormatConfiguration` ADD FOREIGN KEY (`file_format_id`) REFERENCES `FileFormat`(`id`);
ALTER TABLE `FileFormatConfiguration` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `FileFormatConfiguration` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `ConfigurationUsage` ADD FOREIGN KEY (`macro_id`) REFERENCES `Macro`(`id`);
ALTER TABLE `ConfigurationUsage` ADD FOREIGN KEY (`configuration_id`) REFERENCES `FileFormatConfiguration`(`id`);
ALTER TABLE `FileFormat` ADD FOREIGN KEY (`category_id`) REFERENCES `FileFormatCategory`(`id`);
ALTER TABLE `FileExtension` ADD FOREIGN KEY (`file_format_id`) REFERENCES `FileFormat`(`id`);
ALTER TABLE `FileFormatOptionUsage` ADD FOREIGN KEY (`configuration_id`) REFERENCES `FileFormatConfiguration`(`id`);
ALTER TABLE `FileFormatOptionUsage` ADD FOREIGN KEY (`option_id`) REFERENCES `Parameter`(`id`);
ALTER TABLE `Parameter` ADD FOREIGN KEY (`datatype_id`) REFERENCES `DataType`(`id`);
ALTER TABLE `ParameterRestriction` ADD FOREIGN KEY (`parameter_id`) REFERENCES `Parameter`(`id`);
ALTER TABLE `ParameterRestriction` ADD FOREIGN KEY (`type_id`) REFERENCES `ParameterRestrictionType`(`id`);
ALTER TABLE `ParameterSpecification` ADD FOREIGN KEY (`parameter_id`) REFERENCES `Parameter`(`id`);
ALTER TABLE `MethodParameter` ADD FOREIGN KEY (`method_id`) REFERENCES `Method`(`id`);
ALTER TABLE `MethodParameter` ADD FOREIGN KEY (`specification_id`) REFERENCES `ParameterSpecification`(`id`);
ALTER TABLE `FileFormatOption` ADD FOREIGN KEY (`file_format_id`) REFERENCES `FileFormat`(`id`);
ALTER TABLE `FileFormatOption` ADD FOREIGN KEY (`specification_id`) REFERENCES `ParameterSpecification`(`id`);
ALTER TABLE `Algorithm` ADD FOREIGN KEY (`input_category_id`) REFERENCES `FileFormatCategory`(`id`);
ALTER TABLE `Algorithm` ADD FOREIGN KEY (`output_category_id`) REFERENCES `FileFormatCategory`(`id`);
ALTER TABLE `AlgorithmOption` ADD FOREIGN KEY (`specification_id`) REFERENCES `ParameterSpecification`(`id`);
ALTER TABLE `AlgorithmOption` ADD FOREIGN KEY (`algorithm_id`) REFERENCES `Algorithm`(`id`);
ALTER TABLE `AgronomyJob` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `AgronomyJob` ADD FOREIGN KEY (`tillage_id`) REFERENCES `Tillage`(`id`);
ALTER TABLE `AgronomyJob` ADD FOREIGN KEY (`operation_id`) REFERENCES `AgronomyOperation`(`id`);
ALTER TABLE `AgronomyJob` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `AgronomyJob` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `JobParticipation` ADD FOREIGN KEY (`user_id`) REFERENCES `User`(`id`);
ALTER TABLE `JobParticipation` ADD FOREIGN KEY (`job_id`) REFERENCES `AgronomyJob`(`id`);
ALTER TABLE `ParameterRequirement` ADD FOREIGN KEY (`parameter_id`) REFERENCES `Parameter`(`id`);
ALTER TABLE `ParameterRequirement` ADD FOREIGN KEY (`required_id`) REFERENCES `Parameter`(`id`);
ALTER TABLE `UserPhone` ADD FOREIGN KEY (`user_id`) REFERENCES `User`(`id`);
ALTER TABLE `UserPhone` ADD FOREIGN KEY (`phone_id`) REFERENCES `Phone`(`id`);
ALTER TABLE `OrganizationPhone` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `OrganizationPhone` ADD FOREIGN KEY (`phone_id`) REFERENCES `Phone`(`id`);
ALTER TABLE `UserAddress` ADD FOREIGN KEY (`user_id`) REFERENCES `User`(`id`);
ALTER TABLE `UserAddress` ADD FOREIGN KEY (`address_id`) REFERENCES `Address`(`id`);
ALTER TABLE `OrganizationAddress` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `OrganizationAddress` ADD FOREIGN KEY (`address_id`) REFERENCES `Address`(`id`);
ALTER TABLE `AgronomyJobAgenda` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `AgronomyJobAgenda` ADD FOREIGN KEY (`currency_id`) REFERENCES `Unit`(`id`);
ALTER TABLE `AgronomyJobAgenda` ADD FOREIGN KEY (`job_id`) REFERENCES `AgronomyJob`(`id`);
ALTER TABLE `AgronomyJobAgenda` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `ActionRole` ADD FOREIGN KEY (`role_id`) REFERENCES `Role`(`id`);
ALTER TABLE `ActionRole` ADD FOREIGN KEY (`action_id`) REFERENCES `Action`(`id`);
ALTER TABLE `LicenseTypeAction` ADD FOREIGN KEY (`action_id`) REFERENCES `Action`(`id`);
ALTER TABLE `LicenseTypeAction` ADD FOREIGN KEY (`type_id`) REFERENCES `LicenseType`(`id`);
ALTER TABLE `License` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `License` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`);
ALTER TABLE `License` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `License` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `QuotaUsage` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `QuotaUsage` ADD FOREIGN KEY (`term_id`) REFERENCES `LicenseTerm`(`id`);
ALTER TABLE `QuotaUsage` ADD FOREIGN KEY (`type_id`) REFERENCES `QuotaType`(`id`);
ALTER TABLE `LicenseTerm` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `LicenseTerm` ADD FOREIGN KEY (`license_id`) REFERENCES `License`(`id`);
ALTER TABLE `LicenseTerm` ADD FOREIGN KEY (`type_id`) REFERENCES `LicenseType`(`id`);
ALTER TABLE `LicenseTerm` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `LicenseTerm` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `QuotaLimit` ADD FOREIGN KEY (`term_id`) REFERENCES `LicenseTerm`(`id`);
ALTER TABLE `QuotaLimit` ADD FOREIGN KEY (`type_id`) REFERENCES `QuotaType`(`id`);
ALTER TABLE `QuotaLimit` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Machine` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Machine` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Machine` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`);
ALTER TABLE `AccessLog` ADD FOREIGN KEY (`machine_id`) REFERENCES `Machine`(`id`);
ALTER TABLE `AccessLog` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
