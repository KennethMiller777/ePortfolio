USE messaging; 

INSERT INTO person (first_name,last_name) 
	VALUES
	("Kenneth", "Miller");

ALTER TABLE person ADD gender VARCHAR(1) default "M"; 

UPDATE person 
	SET gender = "F"
	WHERE first_name = "Katie" OR first_name = "Allyson" OR first_name = "Diana";

DELETE FROM person 
	WHERE first_name = "Diana" AND last_name = "Taurasi"; 

ALTER TABLE contact_list ADD favorite VARCHAR(10) default NULL; 

UPDATE contact_list 
	SET favorite = "y"
	WHERE contact_id = 1;

UPDATE contact_list 
	SET favorite = "n"
	WHERE contact_id > 1;

INSERT INTO contact_list (person_id,contact_id,favorite) 
	VALUES
	(1, 7, "y"),
	(7, 1, "y"),
	(7, 5, "n");

CREATE TABLE image ( 
	image_id INT(8) UNSIGNED NOT NULL AUTO_INCREMENT,
	image_name VARCHAR(50) NOT NULL,
	image_location VARCHAR(250) NOT NULL,
	PRIMARY KEY (image_id)
	) AUTO_INCREMENT = 1;

CREATE TABLE message_image ( 
	message_id INT(8) UNSIGNED NOT NULL,
	image_id INT(8) UNSIGNED NOT NULL,
	PRIMARY KEY (message_id, image_id)
	);

INSERT INTO image (image_name,image_location) 
	VALUES
	("Picture 1", "New York City"),
	("Picture 2", "Boise"),
	("Picture 3", "San Fransisco"),
	("Picture 4", "Atlanta"),
	("Picture 5", "Dallas");

INSERT INTO message_image (message_id,image_id) 
	VALUES
	(3, 4),
	(5, 5),
	(4, 3),
	(3, 2),
	(2, 1);


