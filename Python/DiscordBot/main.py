#imports

import discord as dc
from discord.ext.commands import Bot
from discord.ext import commands
import asyncio
import time
import random as rand

Client = dc.Client()
bot = commands.Bot(command_prefix='//')


def GetID(tosend, message):
    serverID = message.server
    members={}
    for person in serverID.members:
        print(person)
        if person.nick == None:
            print(person.name.lower())
            members[person.name.lower()] = person.id
        else:
            print(person.nick.lower())
            members[person.nick.lower()] = person.id
    print(members)
    if tosend.lower() in members:
        return members[tosend.lower()]

#main shit here
@bot.event
async def on_ready():
    print("ready")

# on message
@bot.event
async def on_message(message):
    if message.author == bot.user:
        return

    if message.content.lower().startswith('//slave'):
        msg = "{0.author.mention} is a nigger monster".format(message)
        await bot.send_message(message.channel, msg)

    if message.content.lower().startswith('//speeddate'):
        msg = "{0.author.mention} has decided its speed dating time!!".format(message)
        for i in range(2):
            TotalChanneles = []
            connectedUsers = []
            if(len(connectedUsers)%2 == 0):
                TotalChanneles = TotalChanneles[0:len(connectedUsers)/2]
            else:
                TotalChanneles = TotalChanneles[0:len(connectedUsers)/2]
                #also add afk to that list of servers
                TotalChanneles += AfkChannel
            keepTrack = set(TotalChanneles)
            for user in connectedUsers:
                while(1):
                    randomint = randomInterger[0 ... len(TotalChanneles)]
                    keepTrack[TotalChanneles[randomint]] += 1
                    if keepTrack[TotalChanneles[randomint]] > 2 && "afkchannal" > 1:
                        redo random integer
                    else:
                        await user.move_to(TotalChanneles[randomint],reason="speed Dating time, Enjoy :)")
                        break # breaks from while loop
            #10 seconds between randomisze movements
            time.sleep(10)
        await bot.send_message(message.channel, msg)








bot.run("NDc2NzEyMzMxNjU3NzQwMjg4.Dk1zBA.-sPUBVllC-GRWzmRo2juHXPI9nk")
