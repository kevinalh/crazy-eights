define plist
  set var $n = $arg0->begin
  while $n
    print Card_string((struct Card *) $n->element, stdout)
    set var $n = $n->next
  end
end

define pcard
	set var $c = $arg0
	print Card_string((struct Card *)$c, stdout)
end
