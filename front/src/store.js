import Vue from 'vue';
import Vuex from 'vuex';
import rp from 'request-promise';

Vue.use(Vuex);

function getIntensities() {
  return rp.get('');
}

export default new Vuex.Store({
  state: {
    intensities: [
      { value: -1, lat: 48.866667, lng: 2.333333 },
      { value: -40, lat: 48.890000, lng: 2.200034 },
    ],
  },
  mutations: {
    addWifi(state, intensities) {
      state.intensities = intensities;
    },
  },
  actions: {
    async addIntensities({ commit }) {
      const intensities = await getIntensities();
      commit('addWifi', intensities);
    },
  },
  getters: {
    intensities(state) {
      return state.intensities;
    },
  },
});
