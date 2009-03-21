#!/usr/bin/ruby -w
# simple script for turning the euc file into unicode 8
require 'uconv'

begin
  utf8file = File.open("edict_utf8.txt", "w")
  File.open("edict").each do |line|
    utf8 = Uconv.euctou8(line)
    utf8file << utf8
  end
  utf8file.close
end
