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

SELECT sender.first_name AS sender_first, 
	sender.last_name AS sender_last, 
	receiver.first_name AS receiver_first, 
	receiver.last_name AS receiver_last, 
	message.message_id, 
	message.message, 
	message.send_datetime AS timestamp
	FROM message, person sender, person receiver
	WHERE message.sender_id = sender.person_id 
	AND message.receiver_id = receiver.person_id 
	AND sender.first_name = 'Michael' 
	AND sender.last_name = 'Phelps';

SELECT COUNT(*) AS message_count, 
	person.person_id, 
	person.first_name, 
	person.last_name
	FROM message, person
	WHERE message.sender_id = person.person_id
	GROUP BY person.person_id, person.first_name, person.last_name;

SELECT message_image.message_id, 
	MIN(message.message) AS message, 
	MIN(message.send_datetime) AS timestamp, 
	MIN(image.image_name) AS image_name,
	MIN(image.image_location) AS image_location
	FROM message
	INNER JOIN message_image
	ON message.message_id = message_image.message_id
	INNER JOIN image
	ON image.image_id = message_image.image_id
	GROUP BY message_image.message_id;
