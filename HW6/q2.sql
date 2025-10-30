-- a.
SELECT DISTINCT s.ID, s.name
FROM student AS s
JOIN takes   AS t ON t.ID = s.ID
WHERE t.semester = 'Spring' AND t.year = 2009;

-- b. 
SELECT DISTINCT t.ID
FROM instructor AS i
JOIN teaches   AS te
  ON te.ID = i.ID
JOIN takes     AS t
  ON t.course_id = te.course_id
 AND t.sec_id    = te.sec_id
 AND t.semester  = te.semester
 AND t.year      = te.year
WHERE i.name = 'Einstein';

-- c. 
SELECT DISTINCT s.name
FROM student AS s
JOIN takes   AS t ON t.ID = s.ID
JOIN course  AS c ON c.course_id = t.course_id
WHERE c.dept_name = 'Comp. Sci.';

-- d. 
SELECT course_id, title, credits
FROM course
WHERE dept_name = 'Biology'
ORDER BY course_id;

-- e. 
create table person
	(driver_id		varchar(20),
	 name			varchar(100) not null,
	 address		varchar(200),
	 primary key (driver_id)
	);

create table car
	(vin			char(17),
	 model			varchar(60) not null,
	 year			numeric(4,0) check (year >= 1886 and year <= 2100),
	 primary key (vin)
	);

create table accident
	(report_id		varchar(20),
	 date			date not null,
	 location		varchar(200) not null,
	 primary key (report_id)
	);

create table owns
	(driver_id		varchar(20),
	 vin			char(17),
	 primary key (driver_id, vin),
	 foreign key (driver_id) references person
		on delete cascade,
	 foreign key (vin) references car
		on delete cascade
	);

create table participated
	(report_id		varchar(20),
	 vin			char(17),
	 driver_id		varchar(20),
	 damage_amt		numeric(12,2) check (damage_amt >= 0),
	 primary key (report_id, vin, driver_id),
	 foreign key (report_id) references accident
		on delete cascade,
	 foreign key (vin) references car
		on delete cascade,
	 foreign key (driver_id) references person
		on delete cascade
	);