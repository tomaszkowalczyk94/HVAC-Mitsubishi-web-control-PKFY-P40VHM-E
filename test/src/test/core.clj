(ns test.core)
(use 'serial.core)

(defn foo
  "I don't do a whole lot."
  [x]
  (println x "Hello, World!"))

(def port (open "COM4"))
(listen! port (fn [stream] (println stream)), false)

(delay 9999999)
