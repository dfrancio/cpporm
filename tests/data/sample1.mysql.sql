CREATE TABLE `User` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT 'CURRENT_TIMESTAMP',
    `updated_at` DATETIME NOT NULL,
    `deleted_at` DATETIME,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT,
    `name` TEXT NOT NULL,
    `email` TEXT NOT NULL,
    `birth_date` DATE,
    `personal_id` TEXT,
    `professional_id` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`email`)
);

CREATE TABLE `Organization` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `created_at` DATETIME NOT NULL DEFAULT 'CURRENT_TIMESTAMP',
    `updated_at` DATETIME NOT NULL,
    `deleted_at` DATETIME,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT,
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
    `created_at` DATETIME NOT NULL DEFAULT 'CURRENT_TIMESTAMP',
    `updated_at` DATETIME NOT NULL,
    `deleted_at` DATETIME,
    `created_by` BIGINT NOT NULL,
    `updated_by` BIGINT NOT NULL,
    `deleted_by` BIGINT,
    `organization_id` BIGINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT,
    PRIMARY KEY (`id`),
    UNIQUE (`organization_id`, `name`)
);

CREATE TABLE `OrganizationType` (
    `id` SMALLINT NOT NULL,
    `name` TEXT NOT NULL,
    `description` TEXT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`name`)
);

CREATE TABLE `TeamMembership` (
    `id` BIGINT NOT NULL AUTO_INCREMENT,
    `team_id` BIGINT NOT NULL,
    `user_id` BIGINT NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE (`team_id`, `user_id`)
);

ALTER TABLE `User` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `User` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `User` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`) ON DELETE SET NULL;
ALTER TABLE `Organization` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Organization` ADD FOREIGN KEY (`type_id`) REFERENCES `OrganizationType`(`id`);
ALTER TABLE `Organization` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Organization` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`) ON DELETE SET NULL;
ALTER TABLE `Team` ADD FOREIGN KEY (`created_by`) REFERENCES `User`(`id`);
ALTER TABLE `Team` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization`(`id`) ON DELETE CASCADE;
ALTER TABLE `Team` ADD FOREIGN KEY (`updated_by`) REFERENCES `User`(`id`);
ALTER TABLE `Team` ADD FOREIGN KEY (`deleted_by`) REFERENCES `User`(`id`) ON DELETE SET NULL;
ALTER TABLE `TeamMembership` ADD FOREIGN KEY (`user_id`) REFERENCES `User`(`id`);
ALTER TABLE `TeamMembership` ADD FOREIGN KEY (`team_id`) REFERENCES `Team`(`id`) ON DELETE CASCADE;
