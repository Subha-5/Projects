# MySQL

## Built in functions

### show databases
    show databases

### use database
    use myDatabase

### show all the tables in a database
    show tables

### show all the records or rows in a table
    select * from myTable

### show details about the fields
    describe myTable

### create a new database
    create database myDatabase;

### create a table
    create table myTable ( myField varchar(size)/int/char(size)/date/float );
    
    eg : create table emp_details(  Name varchar(25), 
                                    Age int, 
                                    sex char(1), 
                                    doj date, 
                                    city varchar(20), 
                                    salary float 
                                 )

### Inserting data into the table
    insert into myTable values 
        (name1, age1, sex1, doj1, city1, salary1 ),
        (name2, age2, sex2, doj2, city2, salary2 ),
        (name3, age3, sex3, doj3, city3, salary3 ),
        (name4, age4, sex4, doj4, city4, salary4 ),
        (name5, age5, sex5, doj5, city5, salary5 );

OR inserting by fields

    insert into myTable (Name) values
    (name1), (name2), (name3), (name4), (name5)

### get distinct values of a field from a table
    select distinct myField from myTable

### get count of certain field values and setting alias
    select count(myField) as countField from myTable

### get sum of a field values
    select sum(myField) from myTable
### get average of a field values
    select avg(myField) from myTable

### show specific fields in a table
    select myField1, myField2, myField3 from myTable

### filter out result based on a certain condition
    select * from myTable where myField > x ;
    select * from myTable where myField = x or myField = y ;
        select * from myTable where myField in (x,y) ;

    select * from myTable where myField between condition1 and condition2 ;

    select * from myTable where condition1 and condition2 ;

### Group by statements
    select myField1, sum(myField2) as sum_Alias from myTable group by myField3;

### sort by ascending order by myField
    select * from myTable order by myField
### sort by descending order by myField
    select * from myTable order by myField desc
### to show a calculation
    select (30-20) as alias_name; // 10
### length() function
    select length('India') as total_len; // total_len = 5
### Repeat() function
    select repeat('@', 10); // @@@@@@@@@@
### upper() function
    select upper('India'); // INDIA
### lower() function
    select lower('INdia'); // india
### lcase() function
    select lcase('INdia'); // india
### get current date
    select curdate();
### get current date and time
    select now();
### get day by date
    select day(curdate());
### get character length 
    select character_length('India') as total_len; // total_len = 5
    select char_length('India') as total_len; // total_len = 5
### concatenation
    select concat("India", " is", " in Asia") as merged; // merged = India is in Asia
### reverse() function
    select reverse('India') as Rev; // Rev = aidni
### replace() function
    select replace("Orange is a vegetable", "vegetable", "fruit"); // Orange is a fruit
### Trimming a string
    select trim("     India     "); // "India"
    select ltrim("     India     "); // "India     "
    select rtrim("     India     "); // "     India"

### position()
    select position("fruit" in "Orange is a fruit") as name; // name = 13
### get ascii code
    select ascii('a'); // 97
    select ascii('4'); // 52

### Round()
    select round(myField) from myTable // rounds to nearest integer
    
## Group by

### group by
    select dept, avg(age)as average_age from myTable group by dept; 
    select dept, sum(age)as total_salary from myTable group by dept; 

    select count(emp_id), city from employees 
    group by city 
    order by count(emp_id) desc;

    select year(doj) as year_of_joining, count(emp_id) from employees 
    group by year(doj);

### *Creating a table "sales" with fields - product_id, sell_price, quantity and state*

    select product_id, sum(sell_price*quantity) as revenue from sales group by product_id;

### *create a table "c_product" with fields - product_id and cost_price*

    select c.product_id, 
    sum((s.sell_price - c.cost_price)*s.quantity) as profit 
    from sales as s inner join c_product as c 
    where s.product_id = c.product_id
    group by c.product_id ;

## Having 
(having clause is used with aggregate functions, whereas where can't be used with such functions)
    
    select dept, avg(salary) as avg_salary from employees
    group by dept
    having avg(salaary) > 75000;

    select city, sym(salary) as total from employees
    group by city
    having sum(salary) >2000000;

    select dept, count(*) as emp_count from employees
    group by dept
    having count(*) > 2;

    select city, count(*) as emp_count from employees
    where city != "Houston"
    group by city
    having count(*) > 2;

    select dept, count(*) as emp_count from employees
    group by dept
    having avg(salary) > 75000


<hr>


## Joins in SQL
Types of Join

### Inner join

### *create a table "cricket" with fields - cricket_id ( int auto_increment ), name varchar(30) and primary key (cricket_id)*

### *create a table "football" with fields - football_id ( int auto_increment ), name varchar(30) and primary key (football_id)*

    select * from cricket as c inner join football as f on c.name=f.name

    select c.cricket_id, c.name, f.football_id, f.name 
        from cricket as c inner join football as f 
        on c.name = f.name

### *a table "products" with details of product manufactured*
### *a table "productlines" with details of product lines*

    select productcode, productname, textdescription from products inner join productlines using (productline)

### *a table "orders" with the list of products ordered*
### *a table "orderdetails" with details of products ordered*
    select o.ordernumber, o.status, p.productname, sum(quantityordered*priceeach) as revenue
        from orders as o inner join orderdetails as od 
        on o.ordernumber=od.ordernumber 
        inner join products as p on p.productcode = od.productcode
        group by ordernumber

### Left join

### *a table "orders" with the list of products ordered*
### *a table "customers" with the list of customers with orders*
    select c.customername, c.customername, ordernumber, status 
        from customers as c left join orders as o 
        on c.customernumber = o.customernumber
        where ordernumber is null;

### Right join

### *a table "orders" with the list of products ordered*
### *a table "employees" with the list of employees*
    select c.customername, c.phone, e.employeenumber, e.email
    from customers as c right join employees as e
    on e.employeenumber = c.salesrepemployeenumber
    order by employeenumber;

### Self join
### *a table "employees" with the list of employees with fields - employeeNumber, lastName, firstName, extension, email, officeCode, reportsTo, JobTitle*
    select concat(m.lastname, ', ', m.firstname ) as manager, concat(e.lastname, ', ', e.firstname) as employee
    from employees as e inner join employees as m 
    on m.employeenumber = e.reportsto
    order by manager;

### Full join

#### Full outer join
    select c.customername, o.ordernumber from customers as c left join orders as o 
    on c.customernumber = o.customernumber
    union 
    select c.customername, o.ordernumber from customers as c right join orders as 
    o on c.customernumber = o.customernumber 
