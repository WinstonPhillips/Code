
execute procedure drop_if_exists('procedure', 'f_rating');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_update');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_insert');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_delete');
execute procedure drop_if_exists('table', 'DEPARTMENT_RATING');
 commit work;
create table DEPARTMENT_RATING
(

	RATING varchar(5),
	OCCURRENCES int
);
commit work;
insert into DEPARTMENT_RATING (RATING,OCCURRENCES) values ('ULTRA',0);
insert into DEPARTMENT_RATING (RATING,OCCURRENCES) values ('HIGH',0);
insert into DEPARTMENT_RATING (RATING,OCCURRENCES) values ('MID',0);
insert into DEPARTMENT_RATING (RATING,OCCURRENCES) values ('LOW',0);

set term #;
create procedure f_rating(budget int)
returns (rating varchar(5)) as
begin 

	if (budget <= 500000) then
		rating = 'LOW';
	else if (budget <= 850000) then
		rating = 'MID';
	else if (budget <= 1200000) then
		rating = 'HIGH';
	else 
		rating = 'ULTRA';

	suspend;
end #
set term #;

commit work;

select * from DEPARTMENT_RATING; -- show the created table

select RATING from f_rating(200000);
select RATING from f_rating(850000);
select RATING from f_rating(980000);
select RATING from f_rating(1200001);
