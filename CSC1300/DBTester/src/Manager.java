import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class Manager {

	public static void main(String[] args) {
		try {
			/**
			 * Returns the Class object associated with the class or interface with the
			 * given string name. Given the fully qualified name for a class or interface
			 * this method attempts to locate, load, and link the class or interface.
			 * https://docs.oracle.com/javase/8/docs/api/java/lang/Class.html
			 */
			Scanner input = new Scanner(System.in);
			String user;
			String pass;
			System.out.println("Username: ");
			user = input.nextLine();
			System.out.println("Password");
			pass = input.nextLine();
			Class.forName("com.mysql.cj.jdbc.Driver");
			try (Connection conn = DriverManager
					.getConnection("jdbc:mysql://localhost:3306/university?user=" + user + "&password=" + pass);
					Statement stmt = conn.createStatement();) {
				boolean end = false;
				String option;

				String choice;
				String input1;
				String input2;
				String input3;
				String input4;
				while (!end) {

					System.out.println(
							"\nWhat would you like to do select(1), update(2), create(3), delete(4), leave(5)");
					option = input.nextLine();

					// Select
					if (option.equals("1")) {
						System.out.println("Where would you like to select from? department(1), course(2), prereq(3) ");
						input = new Scanner(System.in);
						choice = input.nextLine();

						// Dept
						if (choice.equals("1")) {
							ResultSet rset = stmt.executeQuery("select * from dept");
							while (rset.next()) {
								System.out.println(rset.getString("dept_name") + " " + rset.getString("Building"));
							}
							// Course
						} else if (choice.equals("2")) {
							ResultSet rset = stmt.executeQuery("select * from course");
							while (rset.next()) {
								System.out.println(rset.getString("course_id") + " " + rset.getString("title") + " "
										+ rset.getString("dept_name") + " " + rset.getString("credits"));
							}
							// Prereq
						} else if (choice.equals("3")) {
							ResultSet rset = stmt.executeQuery("select * from prereq");
							while (rset.next()) {
								System.out.println(rset.getString("course_id") + " " + rset.getString("prereq_id"));
							}
						} else {
							System.out.println("You entered the wrong input ");

						}
						// Update course title
					} else if (option.equals("2")) {
						System.out.println("You can only update course title!\n Course ID? ");
						input = new Scanner(System.in);
						input1 = input.nextLine();
						System.out.println("New Title: ");
						input2 = input.nextLine();

						try {
							PreparedStatement pStmt = conn
									.prepareStatement("update course set title = ? where course_id = ?");
							pStmt.setString(1, input2);
							pStmt.setString(2, input1);
							int xxx = pStmt.executeUpdate();
							if (xxx == 0) {
								System.out.println("Nothing was changed");
							}

						} catch (SQLException sqle) {
							System.out.println("The course does not exist or could not be updated");
						}
						// Create a value in the table

					} else if (option.equals("3")) {
						System.out.println("Where would you like to create from? course(1), prereq(2) ");
						input = new Scanner(System.in);
						choice = input.nextLine();
						// Create a course
						if (choice.equals("1")) {
							System.out.println("Enter course_id");
							input1 = input.nextLine();
							System.out.println("Enter title");
							input2 = input.nextLine();
							System.out.println("Enter dept_name");
							input3 = input.nextLine();
							System.out.println("Enter credits");
							input4 = input.nextLine();
							try {
								PreparedStatement pStmt = conn.prepareStatement("insert into course values(?,?,?,?)");
								pStmt.setString(1, input1);
								pStmt.setString(2, input2);
								pStmt.setString(3, input3);
								pStmt.setString(4, input4);
								int xxx = pStmt.executeUpdate();
								if (xxx == 0) {
									System.out.println("Nothing was changed");
								}
							} catch (SQLException sqle) {
								System.out.println("Could not insert course values" + sqle);
							}
							// Create a prereq
						} else if (choice.equals("2")) {

							System.out.println("Enter course_id");
							input1 = input.nextLine();
							System.out.println("Enter prereq_id");
							input2 = input.nextLine();
							try {
								PreparedStatement pStmt = conn.prepareStatement("insert into prereq values(?,?)");
								pStmt.setString(1, input1);
								pStmt.setString(2, input2);
								int xxx = pStmt.executeUpdate();
								if (xxx == 0) {
									System.out.println("Nothing was changed");
								}
							} catch (SQLException sqle) {
								System.out.println("Could not insert prereq values" + sqle);
							}
						} else {
							System.out.println("You entered the wrong input ");
						}
						// Delete a value
					} else if (option.equals("4")) {
						System.out.println("Where would you like to delete from? course(1), prereq(2) ");
						input = new Scanner(System.in);
						choice = input.nextLine();
						System.out.println("Enter the course_id");
						input1 = input.nextLine();
						// Delete a course
						if (choice.equals("1")) {
							ResultSet rset = stmt.executeQuery(
									"select course.course_id, prereq.prereq_id from course, prereq where prereq.course_id = '"
											+ input1 + "'");
							if (rset.next()) {
								System.out.println(
										"You cannot delete this course without deleting it from the prereq class");
							} else {
								try {
									PreparedStatement pStmt = conn
											.prepareStatement("delete from course where course_id = (?)");
									pStmt.setString(1, input1);
									int xxx = pStmt.executeUpdate();
									if (xxx == 0) {
										System.out.println("Nothing was changed");
									}
								}

								catch (SQLException sqle)

								{
									System.out.println("Could not delete tuple " + sqle);
								}
							}
							// Delete a prereq
						} else if (choice.equals("2")) {

							try {
								PreparedStatement pStmt = conn
										.prepareStatement("delete from prereq where course_id = (?)");
								pStmt.setString(1, input1);
								int xxx = pStmt.executeUpdate();
								if (xxx == 0) {
									System.out.println("Nothing was changed");
								}
							}

							catch (SQLException sqle)

							{
								System.out.println("Could not delete tuple " + sqle);
							}
						} else {
							System.out.println("You entered the wrong input ");
						}
					} else if (option.equals("5")) {
						break;
					} else {
						System.out.println("You entered the wrong input");
					}

				}
				input.close();

			} catch (SQLException e) {
				e.printStackTrace();
			}
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}