<template>
  <div id="app" class="">
    <navbar></navbar>
    <router-view/>
  </div>
</template>

<script>
import Navbar from '@/components/Navbar.vue';
import { mapActions } from 'vuex';

export default {
  name: 'App',
  components: {
    Navbar,
  },
  methods: {
    ...mapActions([
      'addIntensities',
    ]),
  },
  created() {
    this.addIntensities();
  },
};
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
</style>
