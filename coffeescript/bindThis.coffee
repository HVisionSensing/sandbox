pos1 =
  x: 100
  y: 200
  dump: ->
    func = ->
      console.log "x => #{@x} y => #{@y}"
    func()

pos2 =
  x: 100
  y: 200
  dump: ->
    func = =>
      console.log "x => #{@x} y => #{@y}"
    func()

pos1.dump()
pos2.dump()
