# Battleship
#### Video Demo:  <https://youtu.be/oWDmXAs56lM>
#### Description:
Battleship Game Introduction:

Welcome to the thrilling world of Battleship! Prepare to embark on an epic naval battle against a formidable enemy fleet. Your strategic skills and precision shots will determine the outcome of this intense showdown! 🚢⚔️

Game Structure:

Get ready to navigate a game board that takes the shape of a square table with dimensions nxn. The value of n should be an odd number between 5 and 20, allowing for a dynamic and challenging gameplay experience. 🎮

As you take your place on one side of the table, a boundary line separates you from your adversary. Both players will begin with an equal number of ships, mirroring the table's dimensions. Your task is to outmaneuver and outgun your opponent's fleet. 🛳️

Game Play:

The engagement begins by strategically deploying your ships within the confines of your side of the board. Meanwhile, the enemy awaits, their ships concealed on their side. Be cautious to place your ships properly, avoiding the border and beyond!

Each turn unveils the game screen, presenting you with an opportunity to skillfully select a coordinate on the enemy's side to launch your strike. Optimize your chances of success by analyzing the possibilities and directing your firepower with precision. 🔍💣

As you fire at a target, coordinate your shots using (x, y) values, with x indicating the column and y indicating the row. Remember, your shots must fall within the enemy's border.

The enemy will retaliate, directing their fire towards your fleet. Their shots are randomized, adding an element of unpredictability to the battle. Receive feedback on whether their shots hit your ships, as marked by '1', or missed, marked by '0'.

Score Calculation:

Your mastery of the battlefield will be reflected in your score, which is computed using a formula based on your performance. The equation is as follows:

Score = Number of successful hits + (n / (Number of misses + 1)) + (n - Number of remaining ships)

Or

Score = c + ( n / (i+1) ) + l

c = Number of correct shots
n = The number of rows/columns of the game table
i = Number of misfires
l = The number of player's remaining ships

This comprehensive scoring system captures your accuracy, adaptability, and resourcefulness throughout the battle. Keep an eye on your score as you strategize and adapt your tactics. Aim for the highest possible score! 🎯

Game Completion:

The battle rages on until all the ships of either you or the enemy have met their watery demise. Victory belongs to the player who successfully annihilates their opponent's fleet.

If you manage to sink the enemy's entire fleet, congratulations! Celebrate your triumph and savor the sweet taste of victory. 🎉

However, should the enemy decimate your fleet, the unfortunate reality of defeat will set in. Do not despair; learn from the experience and prepare for your next encounter. Persevere, and victory will eventually be yours! 😔

At the conclusion of each game, the final result will be displayed, highlighting the outcome and featuring your ultimate score. Reflect upon your performance and strive for improvement as you continue your battleship journey.

Get ready to engage in an exhilarating battle that will test your strategic prowess and keep you on the edge of your seat! Are you prepared to outmaneuver, outgun, and outsmart your opponent? Stand tall, set sail, and let the Battleship game commence! ⚓💥
